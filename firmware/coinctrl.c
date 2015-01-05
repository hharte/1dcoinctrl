/*************************************************************************
 *                                                                       *
 * $Id: coinctrl.c 2594 2015-01-04 21:05:34Z hharte $                    *
 *                                                                       *
 * Copyright (c) 2015 Howard M. Harte, WZ2Q.                             *
 * http://www.magicandroidapps.com                                       *
 *                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining *
 * a copy of this software and associated documentation files (the       *
 * "Software"), to deal in the Software without restriction, including   *
 * without limitation the rights to use, copy, modify, merge, publish,   *
 * distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject to *
 * the following conditions:                                             *
 *                                                                       *
 * The above copyright notice and this permission notice shall be        *
 * included in all copies or substantial portions of the Software.       *
 *                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                 *
 * NONINFRINGEMENT. IN NO EVENT SHALL HOWARD M. HARTE BE LIABLE FOR ANY  *
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  *
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     *
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                *
 *                                                                       *
 * Except as contained in this notice, the name of Howard M. Harte shall *
 * not be used in advertising or otherwise to promote the sale, use or   *
 * other dealings in this Software without prior written authorization   *
 * Howard M. Harte.                                                      *
 *                                                                       *
 * Module Description:                                                   *
 *                                                                       *
 * Environment:                                                          *
 *     Teensy 3.1 Module                                                 *
 *     Sourcery CodeBench 2014.05-46) 4.8.3 20140320 toolchain           *
 *     Karl Lunt's "Bare-metal Teensy 3.x Development" as described at:  *
 *     http://www.seanet.com/~karllunt/bareteensy31.html                 *
 *     Uses Karl's Teensy Libraries for UART and terminal I/O,           *
 *     found here:                                                       *
 *     http://www.seanet.com/~karllunt/bareteensy31libs.html             *
 *                                                                       *
 *************************************************************************/
 
#include  <stdio.h>
#include  <string.h>
#include  <stdint.h>
#include  "common.h"
#include  "arm_cm4.h"
#include  "sdcard.h"
#include  "uart.h"
#include  "termio.h"

static void collect_coin(int line, int collect);
static void test_coin(int line, int initial_rate);
static void set_line_hold(int line, int state);
static void do_coin_ctrl(int line, int state);
static int read_hook_state(int line);
static int check_dial_pulses(int line);
static void delay(void);

#ifndef FALSE
#define FALSE  0
#define TRUE  !FALSE
#endif

#define RELEASE				FALSE
#define HOLD				TRUE
#define REFUND				FALSE
#define COLLECT				TRUE
#define INITIAL_RATE		TRUE
#define STUCK_COIN			FALSE
#define OFF_HOOK			TRUE
#define ON_HOOK				FALSE


#define LED_ON				(GPIOC_PSOR=(1<<5))
#define LED_OFF				(GPIOC_PCOR=(1<<5))

#define REFUND_ON			(GPIOC_PSOR=(1<<2))
#define REFUND_OFF			(GPIOC_PCOR=(1<<2))
#define DISPOSITION_ON		(GPIOC_PSOR=(1<<1))
#define DISPOSITION_OFF		(GPIOC_PCOR=(1<<1))
#define L1_HOLD_ON			(GPIOD_PSOR=(1<<6))
#define L1_HOLD_OFF			(GPIOD_PCOR=(1<<6))
#define L1_COIN_CTRL_ON		(GPIOD_PSOR=(1<<5))
#define L1_COIN_CTRL_OFF	(GPIOD_PCOR=(1<<5))

#define TEST_STATUS			(!(GPIOC_PDIR & (1<<7)))
#define L1_OFF_HOOK			(!(GPIOC_PDIR & (1<<6)))
#define L2_OFF_HOOK			(!(GPIOC_PDIR & (1<<4)))
#define L3_OFF_HOOK			(!(GPIOC_PDIR & (1<<3)))
#define L4_OFF_HOOK			(!(GPIOD_PDIR & (1<<3)))

const char			menu[] = "1. Put line on HOLD\n\r" \
							 "2. Take line off HOLD\n\r" \
							 "3. Collect Coin\n\r" \
							 "4. Refund Coin\n\r" \
							 "5. Initial Rate Test\n\r" \
							 "6. Stuck Coin Test\n\r" \
							 "7. Hookswitch Status\n\r" \
							 "8. Check Dial pulses\n\r" \
							 "0. Select Line\n\r"
							 "\n> ";

int  main(void)
{
	int line = 1;
	char c;

	/* Configure GPIO pins */
	PORTC_PCR2 = PORT_PCR_MUX(0x1); // REFUND Relay is on PC2 (pin 23), config as GPIO (alt = 1)
	PORTC_PCR1 = PORT_PCR_MUX(0x1); // DISPOSITION Relay is on PC1 (pin 22), config as GPIO (alt = 1)
	PORTC_PCR5 = PORT_PCR_MUX(0x1); // LED is on PC5 (pin 13), config as GPIO (alt = 1)
	GPIOC_PDDR = (1 << 5 | 1 << 2 | 1 << 1);			// make these output pins

	PORTD_PCR6 = PORT_PCR_MUX(0x1); // L1_HOLD_CO is on PD6 (pin 21), config as GPIO (alt = 1)
	PORTD_PCR5 = PORT_PCR_MUX(0x1); // L1_COIN_CTRL is on PD5 (pin 20), config as GPIO (alt = 1)
	GPIOD_PDDR = (1 << 6 | 1 << 5);	// make these output pins

	PORTD_PCR3 = PORT_PCR_MUX(0x1); // L4_OFF_HOOK input is on PD3 (pin 8), config as GPIO (alt = 1)
	PORTC_PCR3 = PORT_PCR_MUX(0x1); // L3_OFF_HOOK input is on PC3 (pin 9), config as GPIO (alt = 1)
	PORTC_PCR4 = PORT_PCR_MUX(0x1); // L2_OFF_HOOK input is on PC4 (pin 10), config as GPIO (alt = 1)
	PORTC_PCR6 = PORT_PCR_MUX(0x1); // L1_OFF_HOOK input is on PC6 (pin 11), config as GPIO (alt = 1)
	PORTC_PCR7 = PORT_PCR_MUX(0x1); // TEST_STATUS input is on PC7 (pin 12), config as GPIO (alt = 1)

	LED_OFF;						// start with LED off
	
	/* Make sure all relays are off initially. */
	REFUND_OFF;
	DISPOSITION_OFF;
	for (line = 1; line <= 4; line++) {
		do_coin_ctrl(line, 0);
		set_line_hold(line, RELEASE);
	}

	line = 1;						// Set default line

	UARTInit(0, 115200);			// open UART0 for communication

	xprintf("\n\rWestern Electric 1D Coin Controller Firmware v0.1\n\r(c) 2015 Howard M. Harte, WZ2Q\n\r");

	while (1) {

		xprintf("\n\rCurrent Line: %d\n\r", line);
		xprintf(menu);
		c = xgetc();
		xprintf("%c\n\n\r", c);

		switch (c) {
		case '1':
			set_line_hold(line, HOLD);
			break;
		case '2':
			set_line_hold(line, RELEASE);
			break;
		case '3':
			collect_coin(line, COLLECT);
			break;
		case '4':
			collect_coin(line, REFUND);
			break;
		case '5':
			test_coin(line, INITIAL_RATE);
			break;
		case '6':
			test_coin(line, STUCK_COIN);
			break;
		case '7':
			xprintf("Line %d is %s hook.\n\r", line, read_hook_state(line) ? "OFF" : "on");
			break;
		case '8':
			check_dial_pulses(line);
			break;
		case '0':
			xprintf("Which line (1-4?) ");
			c = xgetc();
			line = c - '0';
			if (line > 0 && line <= 4) {
				xprintf("%c - Line selected.\n\r", c);
			} else {
				xprintf("%c - Invalid line, defaulting to line 1.\n\r", c);
				line = 1;
			}
			break;
		default:
			xprintf("Invalid command '%c'", c);
			break;
		}
	}
}

void run_tests(void)
{
	int line;
	for (line = 1; line <= 4; line++) {
		xprintf("\n\n\n\rTesting Line %d\n\r", line);
		xprintf("Line %d is %s hook.\n\r", line, read_hook_state(1) ? "OFF" : "on");
		test_coin(line, STUCK_COIN);
		collect_coin(line, REFUND);
		collect_coin(line, COLLECT);
		test_coin(line, INITIAL_RATE);
		xprintf("Line %d is %s hook.\n\r", line, read_hook_state(1) ? "OFF" : "on");
	}
}

/* Collect or refund the coin in the hopper. */
void collect_coin(int line, int collect)
{
	/* Put line on hold. */
	set_line_hold(line, TRUE);

	/* Set REFUND relay off */
	if (collect) {
		xprintf("Collecting coin for line %d\n\r", line);
		REFUND_OFF;
	} else {
		xprintf("Refunding coin for line %d\n\r", line);
		REFUND_ON;
	}

	/* Set DISPOSITION relay on */
	DISPOSITION_ON;

	/* Operate Line COIN Control Relay for 600ms */
	LED_ON;
	do_coin_ctrl(line, TRUE);
	delay();
	do_coin_ctrl(line, FALSE);
	LED_OFF;

	/* Turn DISPOSITION relay off */
	REFUND_OFF;
	DISPOSITION_OFF;
	
	/* Take line off hold. */
	set_line_hold(line, FALSE);

}

/* Test for stuck coin or initial rate */
void test_coin(int line, int initial_rate)
{
	volatile uint32_t n;

	/* Put line on hold. */
	set_line_hold(line, TRUE);

	/* Set REFUND relay */
	if (initial_rate) {
		xprintf("Initial Rate Test for line %d\n\r", line);
		REFUND_ON;
	}
	else {
		xprintf("Stuck Coin Test for line %d\n\r", line);
		REFUND_OFF;
	}

	/* Set DISPOSITION relay off (selects test mode) */
	DISPOSITION_OFF;

	/* Apply Coin Control Relay and check status of the TEST_STATUS input */
	LED_ON;
	do_coin_ctrl(line, TRUE);
	
	for (n = 0; n<1000000; n++);	// dumb delay
	if (TEST_STATUS) {
		xprintf("Test Status: %s\n\r", initial_rate ? "INITIAL RATE DEPOSITED" : "STUCK COIN");
	} else {
		xprintf("Test Status: %s\n\r", initial_rate ? "insufficient funds" : "no coin");
	}
	
	do_coin_ctrl(line, FALSE);
	LED_OFF;

	/* Turn DISPOSITION relay off */
	REFUND_OFF;
	DISPOSITION_OFF;

	/* Take line off hold. */
	set_line_hold(line, FALSE);

}

void set_line_hold(int line, int state)
{
	switch (line) {
	case 1:
		xprintf("%s line 1\n\r", state ? "Holding" : "Releasing");
		state ? L1_HOLD_ON : L1_HOLD_OFF;
		break;
	case 2:
	case 3:
	case 4:
		xprintf("Line %d not built yet.\n\r", line);
		break;
	default:
		xprintf("Invalid line %d selected.\n\r", line);
		break;
	}

}

void do_coin_ctrl(int line, int state)
{
	switch (line) {
	case 1:
		xprintf("%s line 1 Coin Control\n\r", state ? "Enable" : "Disable");
		state ? L1_COIN_CTRL_ON : L1_COIN_CTRL_OFF;
		break;
	case 2:
	case 3:
	case 4:
		xprintf("Line %d not built yet.\n\r", line);
			break;
	default:
		xprintf("Invalid line %d selected.\n\r", line);
		break;
	}
}

int read_hook_state(int line)
{
	switch (line) {
	case 1:
		return L1_OFF_HOOK;
		break;
	case 2:
		return L2_OFF_HOOK;
		break;
	case 3:
		return L3_OFF_HOOK;
		break;
	case 4:
		return L4_OFF_HOOK;
		break;
	default:
		xprintf("Invalid line %d selected.\n\r", line);
		break;
	}

	return FALSE;
}

static int check_dial_pulses(int line)
{
	int current_state = read_hook_state(line);
	int new_state;
	int dial_pulses = 0;

	xprintf("Counting dial pulses for line %d, press any key to exit...\n\r", line);

	while (UARTAvail() == 0) {
		if ((new_state = read_hook_state(line)) != current_state) {
			current_state = new_state;
			if (current_state == ON_HOOK) {
				dial_pulses++;
				xprintf("Current pulse count %d\n\r", dial_pulses);
			}
		}
	}

	xgetc();	// flush character that ended the while loop.

	xprintf("Final pulse count %d\n\r", dial_pulses);
	return dial_pulses;
}

void delay()
{
	volatile uint32_t n;
	for (n = 0; n<1000000; n++);	// dumb delay
	for (n = 0; n<1000000; n++);	// dumb delay
	for (n = 0; n<1000000; n++);	// dumb delay
	for (n = 0; n<1000000; n++);	// dumb delay
}