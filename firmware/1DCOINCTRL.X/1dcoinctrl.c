/*************************************************************************
 *                                                                       *
 * Copyright (c) 2020-2022 Howard M. Harte, WZ2Q.                        *
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
 *     MPLAB X IDE v6.00                                                 *
 *     PIC18F47Q84                                                       *
 *                                                                       *
 *************************************************************************/
 
#include  <stdio.h>
#include  <string.h>
#include  <stdint.h>
#include  <ctype.h>

#include "mcc_generated_files/mcc.h"

//#define DEBUG
//#define DEBUG_PULSES

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

#ifdef DEBUG
#define DBG_PRINT(x) printf x
#else
#define DBG_PRINT(x)
#endif

const char menu[] =
    "ATC Collect coin\n\r" \
    "ATR Refund coin\n\r" \
    "ATI Initial rate test\n\r" \
    "ATS Stuck coin test\n\r" \
    "ATQ Query hook state\n\r" \
    "ATL Query selected line\n\r" \
    "ATH Hold CO line\n\r" \
    "ATU Un-hold CO line\n\r" \
    "ATZ Reset controller\n\r" \
    "ATD Dump current state\n\r" \
    "ATE Test 100 refunds.\n\r" \
    "ATT Test (needs hard reset to exit.)\n\r" \
    "ATV Display version information\n\r" \
    "AT? Help\n\n\r" \
    "Line number (1-4) may be specified after the AT command,\n\r" \
    "for example: ATC2 will collect line 2.\n\r";

volatile uint32_t timer_tick = 0;
volatile uint32_t ioc_count = 0;

typedef struct pulse_entry {
    uint16_t pulse_duration;
    uint8_t hook_state;
} pulse_entry_t;

#define PULSE_LIST_ENTRIES_MAX  32  /* Must be a power of 2! */
#define DIGIT_LIST_ENTRIES_MAX  16  /* Must be a power of 2! */

typedef struct digit_fifo {
    uint8_t wptr;
    uint8_t rptr;
    uint8_t dialed_digit[DIGIT_LIST_ENTRIES_MAX];
    uint8_t current_digit;
    uint16_t digit_start_time;
    uint16_t digit_duration;
} digit_fifo_t;

typedef struct hook_switch_context {
    uint32_t last_tick;
    uint8_t wptr;
    uint8_t rptr;
#ifdef DEBUG_PULSES
    pulse_entry_t pulse_list[PULSE_LIST_ENTRIES_MAX];
#endif /* DEBUG_FIFO */
    digit_fifo_t digits;
    volatile uint8_t dial_in_progress;
    uint8_t coin_op_in_progress;
    volatile uint8_t hook_state;
    uint8_t hook_state_delayed;
    uint8_t prev_hook_state;
} hook_switch_context_t;

hook_switch_context_t hs_context[COIN_LINE_MAX] = { 0 };

static void delay_ms(uint16_t ms);
void TIMER0_ISR(void);
void hook_state_ISR(void);
void process_coin_lines(void);
static void set_line_hold(uint8_t coin_line, uint8_t state);
static void set_line_hold_cmd(uint8_t coin_line, uint8_t state);
static void do_coin_ctrl(uint8_t coin_line, uint8_t state);
static void collect_coin(uint8_t coin_line, uint8_t collect);
static uint8_t test_coin(uint8_t coin_line, uint8_t initial_rate);
static void print_version(void);
static void coinctrl_reset(void);
void clear_ioc_per_line(uint8_t coin_line);

void process_coin_lines(void);

uint8_t coinctrl_main(void)
{
    hook_switch_context_t *pHS;
    uint8_t coin_line;
    char c = 0;
    char atcmd[80];
    char len = 0;
    char i;
    uint8_t pps;
    uint8_t digit;
    uint16_t digit_duration;

    print_version();
    printf("\n");

    /* Initialize the 1ms tick timer. */
    TMR0_SetInterruptHandler(TIMER0_ISR);
    TMR0_StartTimer();

    /* Configure IOC interrupts for hook state sensors */
    IOCBF0_SetInterruptHandler(hook_state_ISR);
    IOCBF1_SetInterruptHandler(hook_state_ISR);
    IOCBF2_SetInterruptHandler(hook_state_ISR);
    IOCCF1_SetInterruptHandler(hook_state_ISR);
    IOCCF2_SetInterruptHandler(hook_state_ISR);
    IOCCF3_SetInterruptHandler(hook_state_ISR);
    IOCCF4_SetInterruptHandler(hook_state_ISR);
    IOCCF5_SetInterruptHandler(hook_state_ISR);

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Clear any pending IOC interrupts.
    IOCBF = 0;
    IOCCF = 0;
    // Enable low priority global interrupts
    INTERRUPT_GlobalInterruptLowEnable();

    coinctrl_reset();
    coin_line = 0;                      // Set default coin_line

    while (1) {

//        process_coin_lines();

        while (c != '\r') {
            c = UART1_Read();

            if ((c == 0x08) || (c == 0x7F)) {
                len--;
                atcmd[len] = 0;
                putchar(0x7F);
            } else {
                atcmd[len] = (char)toupper(c);
                len++;
                putchar(c);
            }
        }
        atcmd[len - 1 ] = 0;
        puts("\r");
        c = 0;
        len = 0;

        if (atcmd[0] == 'A' && atcmd[1] == 'T') {

            if (atcmd[3] >= '1' && atcmd[3] < (COIN_LINE_MAX + '1')) {
                coin_line = atcmd[3] - '1';
            } else if (atcmd[3] != 0) {
                puts("ERROR\r");
                continue;
            }

        DBG_PRINT(("Timer_tick: %lu (last: %lu), ioc_int: %lu, Current Line: %d, hook state: %d -> %d (%d delayed), dial in progress: %d, last dialed_digit: %d\n\r",
                timer_tick,
                hs_context[coin_line].last_tick,
                ioc_count,
                coin_line + 1,
                hs_context[coin_line].prev_hook_state,
                hs_context[coin_line].hook_state,
                hs_context[coin_line].hook_state_delayed,
                hs_context[coin_line].dial_in_progress,
                hs_context[coin_line].digits.dialed_digit[(hs_context[coin_line].digits.wptr - 1) & (DIGIT_LIST_ENTRIES_MAX - 1)]));

            switch (atcmd[2]) {
            case 'D': /* Dump current state. */
                digit = hs_context[coin_line].digits.dialed_digit[(hs_context[coin_line].digits.wptr - 1) & (DIGIT_LIST_ENTRIES_MAX - 1)];
                if (digit > 1) {
                    /* Calculate PPS */
                    digit_duration = hs_context[coin_line].digits.digit_duration;
                    pps = (uint8_t)(((digit - 1) * 1000) / (digit_duration / 10));
                }
                printf("Timer_tick: %lu, Current Line: %d, hook state: %d -> %d, dial in progress: %d, last dialed_digit: %d, %u.%upps\n\r",
                        timer_tick,
                        coin_line + 1,
                        hs_context[coin_line].prev_hook_state,
                        hs_context[coin_line].hook_state,
                        hs_context[coin_line].dial_in_progress,
                        digit,
                        pps / 10, pps % 10);

                for (i = 0; i < COIN_LINE_MAX; i++) {
                    pHS = &hs_context[i];
#ifdef DEBUG_PULSES
                    while(pHS->rptr != pHS->wptr) {
                        printf("%d: [%u ms] 0x%02x\n\r", hs_context[i].rptr,
                                pHS->pulse_list[pHS->rptr].pulse_duration,
                                pHS->pulse_list[pHS->rptr].hook_state);
                        pHS->rptr++;
                        pHS->rptr &= (PULSE_LIST_ENTRIES_MAX - 1);
                    }

                    if (pHS->digits.rptr == pHS->digits.wptr) {
                        continue;
                    }
#endif /* DEBUG_PULSES */
                    printf("\n\rLine %d dialed digits: ", i + 1);

                    while (pHS->digits.rptr != pHS->digits.wptr) {
                        printf("%d, ", pHS->digits.dialed_digit[pHS->digits.rptr]);
                        pHS->digits.rptr++;
                        pHS->digits.rptr &= (DIGIT_LIST_ENTRIES_MAX - 1); /* Wrap the pointer */
                    }
                    puts("\r");
                }
                puts("\rOK\r");
                break;
            case 'H':
                set_line_hold_cmd(coin_line, HOLD);
                puts("OK\r");
                break;
            case 'U':
                set_line_hold_cmd(coin_line, RELEASE);
                puts("OK\r");
                break;
            case 'C':
                collect_coin(coin_line, COLLECT);
                puts("OK\r");
                break;
            case 'R':
                collect_coin(coin_line, REFUND);
                puts("OK\r");
                break;
            case 'I':
                printf("%d\n\r", test_coin(coin_line, INITIAL_RATE));
                break;
            case 'V':
                print_version();
                puts("OK\r");
                break;
            case 'S':
                printf("%d\n\r", test_coin(coin_line, STUCK_COIN));
                break;
            case 'T':
                printf("Starting test, RESET to exit....\n\r");
                while (1) {
                    process_coin_lines();
                }
                break;
            case 'Q':
                printf("%d\n\r", hs_context[coin_line].hook_state);
                break;
            case 'L':
                printf("%d\n\r", coin_line + 1);
                break;
            case 'E':
                for (i = 0; i < 100 ; i++) {
                    printf("%d: ", i);
                    collect_coin(coin_line, REFUND);
                    delay_ms(1000);
                }
                puts("OK\r");
                break;
            case 'Z': /* Reset */
                coinctrl_reset();
                coin_line = 0;  // Set default coin_line
                /* Fall through */
            case 0:
                puts("OK\r");
                break;
            case '?':
                printf(menu);
                puts("OK\r");
                break;
            default:
                puts("ERROR\r");
                break;
            }
        }
    }

    return 0;
}

void process_coin_lines(void)
{
    uint8_t coin_line;
    hook_switch_context_t *pHS;
    uint8_t prev_hook_state, hook_state;

    for (coin_line = 0; coin_line < COIN_LINE_MAX; coin_line++) {
        pHS = &hs_context[coin_line];

        /* Do not process the hook switch state while dialing is in progress. */
        if (pHS->dial_in_progress == 1) continue;

        hook_state = pHS->hook_state_delayed;
        prev_hook_state = pHS->prev_hook_state;
        if (hook_state != prev_hook_state) {
            printf("Hook state for line %d changed from %d to %d.\n\r",
                    coin_line + 1,
                    prev_hook_state,
                    hook_state);

            switch(hook_state) {
                case ON_HOOK:
                    if (prev_hook_state == OFF_HOOK_F) {
                        printf("Refund coin, line %d.\n\r", coin_line);
                        collect_coin(coin_line, REFUND);
                    } else if (prev_hook_state == OFF_HOOK_R) {
                        printf("Collect coin, line %d\n\r", coin_line);
                        collect_coin(coin_line, COLLECT);
                    }
                    break;
                case OFF_HOOK_R:
                    if (prev_hook_state == OFF_HOOK_F) {
                        printf("Collect coin2, line %d\n\r", coin_line);
                        collect_coin(coin_line, COLLECT);
                    }
            }
            pHS->prev_hook_state = pHS->hook_state_delayed;
        }
    }
}

static void print_version(void)
{
    printf("\n\rWestern Electric 1D Coin Controller Iss 2 Firsmware v1.1\n\r" \
           "(c) 2020-2022 Howard M. Harte, WZ2Q\n\r" \
           "http://github.com/hharte/1dcoinctrl\n\r");
}

/* Use the 1ms timer tick to delay for the specified number of milliseconds. */
static void delay_ms(uint16_t ms)
{
    uint32_t end_time;
    
    end_time = timer_tick + ms;
    
    while (timer_tick < end_time);

}


/* The TIMER0_ISR must be higher-priority than the IOC ISR. */
void TIMER0_ISR(void)
{
    hook_switch_context_t *pHS;
    uint32_t time_delta;
    uint8_t coin_line;

    timer_tick++;

    for (coin_line = 0; coin_line < COIN_LINE_MAX; coin_line++) {
        pHS = &hs_context[coin_line];

        /* Calculate the time since the last pulse. */
        time_delta = timer_tick - pHS->last_tick;

        /* If more than 100ms has passed since the last hook state interrupt,
         * we may need to add the current_digit to the dialed_digits FIFO.
         */
        if (time_delta > 100) {
            if (pHS->digits.current_digit != 0) {
                pHS->digits.dialed_digit[pHS->digits.wptr] = pHS->digits.current_digit;
                pHS->digits.wptr++;
                pHS->digits.wptr &= (DIGIT_LIST_ENTRIES_MAX - 1); /* Wrap the pointer */
                pHS->digits.current_digit = 0;
                pHS->dial_in_progress = 0;
            }
            pHS->hook_state_delayed = pHS->hook_state;
        }
    }
}

void hook_state_ISR(void)
{
    uint32_t time_delta;
    hook_switch_context_t *pHS;
    uint8_t hook_state;
    uint8_t coin_line;
    uint8_t coin_line_hook_state;
    uint8_t prev_coin_line_hook_state;
    static uint8_t prev_hook_state = 0;
    static uint32_t on_hook_start_time[COIN_LINE_MAX] = { 0 };
    uint16_t on_hook_pulse_duration;
    static uint32_t off_hook_start_time[COIN_LINE_MAX] = { 0 };
    uint16_t off_hook_pulse_duration;

    ioc_count++;

    hook_state  = (~(PORTC << 2)) & 0xF8;
    hook_state |= ~(PORTB & 0x07);

    for (coin_line = 0; coin_line < COIN_LINE_MAX; coin_line++) {
        pHS = &hs_context[coin_line];

        coin_line_hook_state = (hook_state >> (coin_line << 1)) & 0x03;
        prev_coin_line_hook_state = (prev_hook_state >> (coin_line << 1)) & 0x03;

        if (pHS->coin_op_in_progress == 1) {
            continue;
        }
        if (prev_coin_line_hook_state == coin_line_hook_state) {
            continue;
        }

        time_delta = timer_tick - pHS->last_tick;
        pHS->last_tick = timer_tick;

        if (coin_line_hook_state == ON_HOOK) {
            on_hook_start_time[coin_line] = timer_tick;
            on_hook_pulse_duration = 0;
            off_hook_pulse_duration = (uint16_t)(timer_tick - off_hook_start_time[coin_line]);
#ifdef DEBUG_PULSES
            pHS->pulse_list[pHS->wptr].pulse_duration = off_hook_pulse_duration;
#endif /* DEBUG_PULSES */
        } else { /* OFF_HOOK */
            off_hook_start_time[coin_line] = timer_tick;
            off_hook_pulse_duration = 0;
            on_hook_pulse_duration = (uint16_t)(timer_tick - on_hook_start_time[coin_line]);
#ifdef DEBUG_PULSES
            pHS->pulse_list[pHS->wptr].pulse_duration = on_hook_pulse_duration;
#endif /* DEBUG_PULSES */
        }

#ifdef DEBUG_PULSES
        /* Store the pulse details in a circular buffer for debugging. */
        pHS->pulse_list[pHS->wptr].hook_state = coin_line_hook_state;
#endif /* DEBUG_PULSES */
        pHS->hook_state = coin_line_hook_state;
        pHS->wptr++;
        pHS->wptr &= (PULSE_LIST_ENTRIES_MAX - 1); /* Wrap the pointer */

        /* Process dial pulses:
         * In the United States, digits are dialed at 10 pulses-per-
         * second, with a 39% make to 61% break ratio. */
        if (on_hook_pulse_duration < 30) {
            /* Ignore glitches */
            continue;
        } else if (on_hook_pulse_duration <= 80) {
            pHS->dial_in_progress = 1;
            /* If the pulse is less than 80ms, it must be a dial pulse. */
            if (pHS->digits.current_digit == 0) {
                pHS->digits.digit_start_time = (uint16_t)timer_tick;
            }
            pHS->digits.digit_duration = (uint16_t)(timer_tick - pHS->digits.digit_start_time);
            pHS->digits.current_digit++;
        }
    }

    prev_hook_state = hook_state;
}

/* Put the line on hold, no guard against spurious hook state interrupts. */
static void set_line_hold(uint8_t coin_line, uint8_t state)
{
    if (coin_line >= COIN_LINE_MAX) {
        DBG_PRINT(("Invalid coin_line %d selected.\n\r", coin_line + 1));
        return;
    }

    DBG_PRINT(("%s coin_line %d\n\r",
                state ? "Holding" : "Releasing", coin_line + 1));

    switch (coin_line) {
    case 0:
        if (state == TRUE) L1_HOLD_ON; else L1_HOLD_OFF;
        break;
    case 1:
        if (state == TRUE) L2_HOLD_ON; else L2_HOLD_OFF;
        break;
    case 2:
        if (state == TRUE) L3_HOLD_ON; else L3_HOLD_OFF;
        break;
    case 3:
        if (state == TRUE) L4_HOLD_ON; else L4_HOLD_OFF;
        break;
    }
}

/* Command wrapper to put the line on hold, guards against spurious hook state interrupts. */
static void set_line_hold_cmd(uint8_t coin_line, uint8_t state)
{
    INTERRUPT_GlobalInterruptLowDisable();

    set_line_hold(coin_line, state);

    delay_ms(100);   /* Wait for relays to settle. */
    clear_ioc_per_line(coin_line);  /* Prevent spurious interrupts. */
    INTERRUPT_GlobalInterruptLowEnable();
}

static void do_coin_ctrl(uint8_t coin_line, uint8_t state)
{
    if (coin_line >= COIN_LINE_MAX) {
        DBG_PRINT(("Invalid coin_line %d selected.\n\r", coin_line + 1));
        return;
    }

    DBG_PRINT(("%s coin_line %d Coin Control\n\r",
               state ? "Enable" : "Disable", coin_line + 1));

    switch (coin_line) {
    case 0:
        if (state == TRUE) L1_COIN_CTRL_ON; else L1_COIN_CTRL_OFF;
        break;
    case 1:
        if (state == TRUE) L2_COIN_CTRL_ON; else L2_COIN_CTRL_OFF;
        break;
    case 2:
        if (state == TRUE) L3_COIN_CTRL_ON; else L3_COIN_CTRL_OFF;
        break;
    case 3:
        if (state == TRUE) L4_COIN_CTRL_ON; else L4_COIN_CTRL_OFF;
        break;
    }
}

/* Collect or refund the coin in the hopper. */
static void collect_coin(uint8_t coin_line, uint8_t collect)
{
    INTERRUPT_GlobalInterruptLowDisable();

     /* Put CO on hold. */
    set_line_hold(coin_line, TRUE);
    
    /* Set REFUND relay off */
    if (collect) {
        DBG_PRINT(("Collecting coin for coin_line %d\n\r", coin_line + 1));
        REFUND_OFF;
    } else {
        DBG_PRINT(("Refunding coin for coin_line %d\n\r", coin_line + 1));
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
    delay_ms(100);   /* Wait for relays to settle. */
    /* Take coin_line off hold. */
    set_line_hold(coin_line, FALSE);

    delay_ms(100);   /* Wait for relays to settle. */
    clear_ioc_per_line(coin_line);  /* Prevent spurious interrupts. */
    INTERRUPT_GlobalInterruptLowEnable();
}

/* Test for stuck coin or initial rate */
static uint8_t test_coin(uint8_t coin_line, uint8_t initial_rate)
{
    uint8_t result;
    hs_context[coin_line].coin_op_in_progress = 1;

    INTERRUPT_GlobalInterruptLowDisable();

    /* Set DISPOSITION relay off (selects test mode) */
    DISPOSITION_OFF;
    
    /* Put CO on hold. */
    set_line_hold(coin_line, TRUE);

    /* Set REFUND relay */
    if (initial_rate) {
        REFUND_ON;
    } else {
        REFUND_OFF;
    }

    /* Apply Coin Control Relay and check status of the TEST_STATUS input */
    do_coin_ctrl(coin_line, TRUE);
    delay_ms(50);   /* Wait for test status to settle. */

    result = (TEST_STATUS == 0);

    do_coin_ctrl(coin_line, FALSE);

    /* Turn REFUND relay off */
    REFUND_OFF;
    delay_ms(200);   /* Wait for relays to settle. */

    /* Remove CO hold. */
    set_line_hold(coin_line, FALSE);
    delay_ms(100);   /* Wait for relays to settle. */
    clear_ioc_per_line(coin_line);  /* Prevent spurious interrupts. */
    INTERRUPT_GlobalInterruptLowEnable();

    hs_context[coin_line].coin_op_in_progress = 0;
    return (result);
}

/* The hook state sensors will detect transitions when the line is held/unheld
 * and while coin operations are carried out.  Clear line-specific IOC pending
 * interrupt state before re-enabling interrupts for the IOC.
 */
void clear_ioc_per_line(uint8_t coin_line)
{
    switch(coin_line) {
        case 0:
            IOCBF0 = 0;     /* RB0 */
            IOCBF1 = 0;     /* RB1 */
            break;
        case 1:
            IOCBF2 = 0;     /* RB2 */
            IOCCF1 = 0;     /* RC1 */
            break;
        case 2:
            IOCCF2 = 0;     /* RC2 */
            IOCCF3 = 0;     /* RC3 */
            break;
        case 3:
            IOCCF4 = 0;     /* RC4 */
            IOCCF5 = 0;     /* RC5 */
            break;
        default:
            DBG_PRINT(("Invalid coin_line %d selected.\n\r", coin_line + 1));
            break;
    }
}

static void coinctrl_reset(void)
{
    uint8_t coin_line;
    uint8_t ioreg;

    /* Make sure all relays are off initially. */
    INTERRUPT_GlobalInterruptLowDisable();

    REFUND_OFF;
    DISPOSITION_OFF;

    for (coin_line = 0; coin_line < COIN_LINE_MAX; coin_line++) {
        DBG_PRINT(("Release coin line %d\n\r", coin_line + 1));
        do_coin_ctrl(coin_line, FALSE);
        set_line_hold(coin_line, RELEASE);
    }
    delay_ms(100);
    IOCBF = 0;
    IOCCF = 0;
    INTERRUPT_GlobalInterruptLowEnable();
}
