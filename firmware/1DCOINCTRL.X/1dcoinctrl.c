/*************************************************************************
 *                                                                       *
 * Copyright (c) 2020 Howard M. Harte, WZ2Q.                             *
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
 *     MPLAB X IDE v5.30                                                 *
 *                                                                       *
 *************************************************************************/
 
#include  <stdio.h>
#include  <string.h>
#include  <stdint.h>
#include  <ctype.h>

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

//#define DEBUG

#define COIN_LINE_MAX       4

#ifndef FALSE
#define FALSE  (0)
#define TRUE  (1)
#endif

#define RELEASE             FALSE
#define HOLD                TRUE
#define REFUND              FALSE
#define COLLECT             TRUE
#define INITIAL_RATE        TRUE
#define STUCK_COIN          FALSE

#define ON_HOOK             (0)
#define OFF_HOOK_F          (1)
#define OFF_HOOK_R          (2)


#define LED_ON              //IO_RD0_SetHigh()
#define LED_OFF             //IO_RD0_SetLow()

#define REFUND_ON           REFUND_SetHigh()
#define REFUND_OFF          REFUND_SetLow()
#define DISPOSITION_ON      DISPOSITION_SetHigh()
#define DISPOSITION_OFF     DISPOSITION_SetLow()
#define L1_HOLD_ON          L1_HOLD_CO_SetHigh()
#define L1_HOLD_OFF         L1_HOLD_CO_SetLow()
#define L2_HOLD_ON          L2_HOLD_CO_SetHigh()
#define L2_HOLD_OFF         L2_HOLD_CO_SetLow()
#define L3_HOLD_ON          L3_HOLD_CO_SetHigh()
#define L3_HOLD_OFF         L3_HOLD_CO_SetLow()
#define L4_HOLD_ON          L4_HOLD_CO_SetHigh()
#define L4_HOLD_OFF         L4_HOLD_CO_SetLow()

#define L1_COIN_CTRL_ON     L1_COIN_CONTROL_SetHigh()
#define L1_COIN_CTRL_OFF    L1_COIN_CONTROL_SetLow()
#define L2_COIN_CTRL_ON     L2_COIN_CONTROL_SetHigh()
#define L2_COIN_CTRL_OFF    L2_COIN_CONTROL_SetLow()
#define L3_COIN_CTRL_ON     L3_COIN_CONTROL_SetHigh()
#define L3_COIN_CTRL_OFF    L3_COIN_CONTROL_SetLow()
#define L4_COIN_CTRL_ON     L4_COIN_CONTROL_SetHigh()
#define L4_COIN_CTRL_OFF    L4_COIN_CONTROL_SetLow()

#define TEST_STATUS         TEST_STATUS_GetValue()

#define MCP23008_BASE       (0x20)
#define MCP23008_IODIR      (0x00)
#define MCP23008_IPOL       (0x01)
#define MCP23008_GPINTEN    (0x02)
#define MCP23008_DEFVAL     (0x03)
#define MCP23008_INTCON     (0x04)
#define MCP23008_IOCON      (0x05)
#define MCP23008_GPPU       (0x06)
#define MCP23008_INTF       (0x07)
#define MCP23008_INTCAP     (0x08)
#define MCP23008_GPIO       (0x09)
#define MCP23008_OLAT       (0x0A)

#ifdef DEBUG
#define DBG_PRINT(x) printf x
#else
#define DBG_PRINT(x)
#endif

const char          menu[] = "ATC Collect coin\n\r" \
                             "ATR Refund coin\n\r" \
                             "ATI Initial rate test\n\r" \
                             "ATS Stuck coin test\n\r" \
                             "ATQ Query hook state\n\r" \
                             "ATH Hold CO line\n\r" \
                             "ATU Un-hold CO line\n\r" \
                             "ATV Display version information\n\r" \
                             "AT? Help\n\r"
                             "\n> ";

volatile uint32_t timer_tick = 0;
volatile uint32_t int2_count = 0;
volatile uint8_t cur_hook_state = 0;

static void delay_ms(uint16_t ms);
void hook_state_ISR(void);
void TIMER0_ISR(void);
static void set_line_hold(uint8_t coin_line, uint8_t state);
static uint8_t read_hook_state(uint8_t coin_line);
static void do_coin_ctrl(uint8_t coin_line, uint8_t state);
static void collect_coin(uint8_t coin_line, uint8_t collect);
static uint8_t test_coin(uint8_t coin_line, uint8_t initial_rate);
static void print_version(void);
static void coinctrl_reset(void);
static uint8_t MCP23008_Read(uint8_t reg);
static uint8_t MCP23008_Write(uint8_t reg, uint8_t val);

uint8_t coinctrl_main(void)
{
    uint8_t coin_line = 1;
    char c = 0;
    char atcmd[80];
    char len = 0;
    char i;

    /* Initialize the 1ms tick timer. */
    TMR0_Initialize();
    TMR0_SetInterruptHandler(TIMER0_ISR);
    TMR0_StartTimer();

    INT2_SetInterruptHandler(hook_state_ISR);

    coinctrl_reset();
    coin_line = 1;                      // Set default coin_line

    while (1) {

        DBG_PRINT(("Timer_tick: %lu, Current Line: %d, hook state: %s\n\r",
                timer_tick,
                coin_line,
                read_hook_state(coin_line) ? "OFF Hook" : "ON Hook"));

        while (c != '\r') {
            c = getch();

            if ((c == 0x08) || (c == 0x7F)) {
                len--;
                atcmd[len] = 0;
                putchar(0x7F);
            } else {
                atcmd[len] = toupper(c);
                len++;
                putchar(c);
            }
        }
        atcmd[len - 1 ] = 0;
        printf("\n\r");
        c = 0;
        len = 0;

        if (atcmd[0] == 'A' && atcmd[1] == 'T') {

            if (atcmd[3] >= '1' && atcmd[3] <= (COIN_LINE_MAX + '0')) {
                coin_line = atcmd[3] - '0';
            }

            switch (atcmd[2]) {
            case 'H':
                set_line_hold(coin_line, HOLD);
                puts("OK\n\r");
                break;
            case 'U':
                set_line_hold(coin_line, RELEASE);
                puts("OK\n\r");
                break;
            case 'C':
                collect_coin(coin_line, COLLECT);
                printf("OK\n\r");
                break;
            case 'R':
                collect_coin(coin_line, REFUND);
                printf("OK\n\r");
                break;
            case 'I':
                printf("%d\n\r", test_coin(coin_line, INITIAL_RATE));
                break;
            case 'V':
                print_version();
                break;
            case 'S':
                printf("%d\n\r", test_coin(coin_line, STUCK_COIN));
                break;
            case 'Q':
                printf("%d\n\r", read_hook_state(coin_line));
                break;
            case 'E':
                for (i = 0; i < 100 ; i++) {
                    printf("%d: ", i);
                    collect_coin(coin_line, REFUND);
                    delay_ms(1000);
                }
                break;
            case 'Z': /* Reset */
                coinctrl_reset();
                coin_line = 1;  // Set default coin_line
                /* Fall through */
            case 0:
                printf("OK\n\r");
                break;
            case '?':
                printf(menu);
                break;
            default:
                printf("ERROR\n\r");
                break;
            }
        }
    }

    return 0;
}

static void print_version(void)
{
    printf("\n\rWestern Electric 1D Coin Controller Iss 2 Firmware v1.0\n\r" \
           "(c) 2020 Howard M. Harte, WZ2Q\n\r" \
           "http://github.com/hharte/1dcoinctrl\n\r");
}

static void delay_ms(uint16_t ms)
{
    uint32_t end_time;
    
    end_time = timer_tick + ms;
    
    while (timer_tick < end_time);
}

void TIMER0_ISR(void)
{
    timer_tick++;
}

void hook_state_ISR(void)
{
    int2_count++;
    cur_hook_state = MCP23008_Read(MCP23008_GPIO);
}

static void set_line_hold(uint8_t coin_line, uint8_t state)
{
    if (coin_line > COIN_LINE_MAX) {
        DBG_PRINT(("Invalid coin_line %d selected.\n\r", coin_line));
        return;
    }

    DBG_PRINT(("%s coin_line %d\n\r", state ? "Holding" : "Releasing", coin_line));
    switch (coin_line) {
    case 1:
        if (state == TRUE) L1_HOLD_ON; else L1_HOLD_OFF;
        break;
    case 2:
        if (state == TRUE) L2_HOLD_ON; else L2_HOLD_OFF;
        break;
    case 3:
        if (state == TRUE) L3_HOLD_ON; else L3_HOLD_OFF;
        break;
    case 4:
        if (state == TRUE) L4_HOLD_ON; else L4_HOLD_OFF;
        break;
    }

}

#define HOOK_BITS_SHIFT     ((coin_line - 1) << 1)
#define HOOK_BITS_MASK      (0x03)
static uint8_t read_hook_state(uint8_t coin_line)
{
    uint8_t gpio;

    if (coin_line > COIN_LINE_MAX) {
        return 0;
    }

    gpio = cur_hook_state;

    return ((gpio >> HOOK_BITS_SHIFT) & HOOK_BITS_MASK);
}

static void do_coin_ctrl(uint8_t coin_line, uint8_t state)
{
    
    if (coin_line > COIN_LINE_MAX) {
        DBG_PRINT(("Invalid coin_line %d selected.\n\r", coin_line));
        return;
    }

    DBG_PRINT(("%s coin_line %d Coin Control\n\r", state ? "Enable" : "Disable", coin_line));

    switch (coin_line) {
    case 1:
        if (state == TRUE) L1_COIN_CTRL_ON; else L1_COIN_CTRL_OFF;
        break;
    case 2:
        if (state == TRUE) L2_COIN_CTRL_ON; else L2_COIN_CTRL_OFF;
        break;
    case 3:
        if (state == TRUE) L3_COIN_CTRL_ON; else L3_COIN_CTRL_OFF;
        break;
    case 4:
        if (state == TRUE) L4_COIN_CTRL_ON; else L4_COIN_CTRL_OFF;
        break;
    }
}

/* Collect or refund the coin in the hopper. */
static void collect_coin(uint8_t coin_line, uint8_t collect)
{
    volatile uint24_t n;
    uint8_t hook_state;
    
    hook_state = read_hook_state(coin_line);
    
    /* Put coin_line on hold if it is off hook. */
    if (hook_state != ON_HOOK) {
        set_line_hold(coin_line, TRUE);
    }
    
    /* Set REFUND relay off */
    if (collect) {
        DBG_PRINT(("Collecting coin for coin_line %d\n\r", coin_line));
        REFUND_OFF;
    } else {
        DBG_PRINT(("Refunding coin for coin_line %d\n\r", coin_line));
        REFUND_ON;
    }

    /* Set DISPOSITION relay on */
    DISPOSITION_ON;

    /* Operate Line COIN Control Relay for 600ms */
    do_coin_ctrl(coin_line, TRUE);
    delay_ms(600);
    do_coin_ctrl(coin_line, FALSE);

    /* Turn DISPOSITION relay off */
    REFUND_OFF;
    DISPOSITION_OFF;

    if (hook_state != ON_HOOK) {
        /* Take coin_line off hold. */
        set_line_hold(coin_line, FALSE);
    }
}

/* Test for stuck coin or initial rate */
static uint8_t test_coin(uint8_t coin_line, uint8_t initial_rate)
{
    uint8_t hook_state;
    uint8_t result;

    /* Set DISPOSITION relay off (selects test mode) */
    DISPOSITION_OFF;
    
    hook_state = read_hook_state(coin_line);
    
    /* Put CO on hold if the coin collector is off hook. */
    if (hook_state != ON_HOOK) {
        set_line_hold(coin_line, TRUE);
    }
    
    /* Set REFUND relay */
    if (initial_rate) {
        REFUND_ON;
    } else {
        REFUND_OFF;
    }

    /* Apply Coin Control Relay and check status of the TEST_STATUS input */
    do_coin_ctrl(coin_line, TRUE);
    delay_ms(100);
    
    result = (TEST_STATUS == 0);
    
    do_coin_ctrl(coin_line, FALSE);
    
    /* Turn REFUND relay off */
    REFUND_OFF;

    if (hook_state != ON_HOOK) {
        /* Remove CO hold. */
        set_line_hold(coin_line, FALSE);
    }
    
    return (result);
}

static void coinctrl_reset(void)
{
    uint8_t coin_line;

    EXT_INT2_InterruptDisable();

    /* Reset the MCP23008 I/O Expander */
    I2C_RESET_N_SetLow();

    /* Make sure all relays are off initially. */
    REFUND_OFF;
    DISPOSITION_OFF;

    for (coin_line = 1; coin_line <= COIN_LINE_MAX; coin_line++) {
        DBG_PRINT(("Release coin line %d\n\r", coin_line));
        set_line_hold(coin_line, RELEASE);
    }

    /* Take the MCP23008 I/O Expander out of reset. */
    I2C_RESET_N_SetHigh();

    /* Configure MCP23008 I/O Expander */
    MCP23008_Write(MCP23008_GPPU, 0xFF);    /* Enable pull-ups */
    MCP23008_Write(MCP23008_IPOL, 0xFF);    /* Invert input polarity */
    MCP23008_Write(MCP23008_IOCON, 0x02);   /* Active High Interrupt. */
    MCP23008_Write(MCP23008_GPINTEN, 0xFF); /* Interrupt on change. */

    EXT_INT2_InterruptEnable();
}

static uint8_t MCP23008_Read(uint8_t reg)
{
    uint8_t val = 0;
    val = I2C1_Read1ByteRegister(MCP23008_BASE, reg);
    return val;
}

static uint8_t MCP23008_Write(uint8_t reg, uint8_t val)
{
    I2C1_Write1ByteRegister(MCP23008_BASE, reg, val);
    return 0;
}
