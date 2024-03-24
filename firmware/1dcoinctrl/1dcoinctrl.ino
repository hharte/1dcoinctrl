/*************************************************************************
 *                                                                       *
 * https://github.com/hharte/ky11lb                                      *
 *                                                                       *
 * MIT License                                                           *
 *                                                                       *
 * Copyright (c) 2024 Howard M. Harte                                    *
 *                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining *
 * a copy of this software and associated documentation files (the       *
 * "Software"), to deal in the Software without restriction, including   *
 * without limitation the rights to use, copy, modify, merge, publish,   *
 * distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject    *
 * to the following conditions:                                          *
 *                                                                       *
 * The above copyright notice and this permission notice shall be        *
 * included in all copies or substantial portions of the Software.       *
 *                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                 *
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS   *
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN    *
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN     *
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE      *
 * SOFTWARE.                                                             *
 *                                                                       *
 * Module Description:                                                   *
 * Coin Controller for Single-slot payphones.                            *
 *                                                                       *
 * Arduino 1.8.19 or later with DxCore 1.5.11.                           *
 *                                                                       *
 *************************************************************************/

#include <stdarg.h>

#define BAUD_RATE           115200
#define MS_PER_TICK         1
#define COUNT_PER_MS        93.6

#define COIN_LINE_MAX       4 /* Number of coin lines */

/* Pin assignments:
 * ref: https://github.com/SpenceKonde/DxCore/blob/master/megaavr/extras/DA28.md
 */

/* Port A */
#define L1_HOLD_CO          0   /* PA0 L1_HOLD_CO */
#define L2_HOLD_CO          1   /* PA1 L2_HOLD_CO */
#define L3_HOLD_CO          2   /* PA2 L3_HOLD_CO */
#define L4_HOLD_CO          3   /* PA3 L4_HOLD_CO */
//#define UART_TXD          4   /* PA4 UART TXD */
//#define UART_RXD          5   /* PA5 UART RXD */
#define TEST_STATUS_IN      6   /* PA6 */
#define STATUS_LED          7   /* PA7 */
#define STATUS_LED_B        (1 << 7)  /* PA7 */

/* Port C */
#define L1_COIN_CONTROL     8   /* PC0 */
#define L2_COIN_CONTROL     9   /* PC1 */
#define L3_COIN_CONTROL     10  /* PC2 */
#define L4_COIN_CONTROL     11  /* PC3 */

/* Port D: Hook State Inputs */
#define L1_OFF_HOOK_F       12  /* PD0 */
#define L1_OFF_HOOK_R       13  /* PD1 */
#define L2_OFF_HOOK_F       14  /* PD2 */
#define L2_OFF_HOOK_R       15  /* PD3 */
#define L3_OFF_HOOK_F       16  /* PD4 */
#define L3_OFF_HOOK_R       17  /* PD5 */
#define L4_OFF_HOOK_F       18  /* PD6 */
#define L4_OFF_HOOK_R       19  /* PD7 */

/* Port F: REFUND and DISPOSITION relay control. */
#define REFUND              20  /* PF0 */
#define DISPOSITION         21  /* PF1 */

#define LED_ON(x)           VPORTA.OUT &= ~STATUS_LED_B;
#define LED_OFF(x)          VPORTA.OUT |=  STATUS_LED_B;

#define RELEASE             false
#define HOLD                true
#define REFUND_COINS        false
#define COLLECT_COINS       true
#define INITIAL_RATE        true
#define STUCK_COIN          false

#define ON_HOOK             (0)
#define OFF_HOOK_F          (1)
#define OFF_HOOK_R          (2)

#define REFUND_ON           digitalWrite(REFUND, HIGH)
#define REFUND_OFF          digitalWrite(REFUND, LOW)
#define DISPOSITION_ON      digitalWrite(DISPOSITION, HIGH)
#define DISPOSITION_OFF     digitalWrite(DISPOSITION, LOW)
#define L1_HOLD_ON          digitalWrite(L1_HOLD_CO, HIGH)
#define L1_HOLD_OFF         digitalWrite(L1_HOLD_CO, LOW)
#define L2_HOLD_ON          digitalWrite(L2_HOLD_CO, HIGH)
#define L2_HOLD_OFF         digitalWrite(L2_HOLD_CO, LOW)
#define L3_HOLD_ON          digitalWrite(L3_HOLD_CO, HIGH)
#define L3_HOLD_OFF         digitalWrite(L3_HOLD_CO, LOW)
#define L4_HOLD_ON          digitalWrite(L4_HOLD_CO, HIGH)
#define L4_HOLD_OFF         digitalWrite(L4_HOLD_CO, LOW)

#define L1_COIN_CTRL_ON     digitalWrite(L1_COIN_CONTROL, HIGH)
#define L1_COIN_CTRL_OFF    digitalWrite(L1_COIN_CONTROL, LOW)
#define L2_COIN_CTRL_ON     digitalWrite(L2_COIN_CONTROL, HIGH)
#define L2_COIN_CTRL_OFF    digitalWrite(L2_COIN_CONTROL, LOW)
#define L3_COIN_CTRL_ON     digitalWrite(L3_COIN_CONTROL, HIGH)
#define L3_COIN_CTRL_OFF    digitalWrite(L3_COIN_CONTROL, LOW)
#define L4_COIN_CTRL_ON     digitalWrite(L4_COIN_CONTROL, HIGH)
#define L4_COIN_CTRL_OFF    digitalWrite(L4_COIN_CONTROL, LOW)

#define TEST_STATUS(x)      digitalRead(TEST_STATUS_IN)

#define INTERRUPT_GlobalInterruptLowDisable(x)
#define INTERRUPT_GlobalInterruptLowEnable(x)

#define wdt_reset() __asm__ __volatile__ ("wdr"::)  /* reset watchdog timer. */

//#define RELAY_DEBUG

const char menu[] = "\n\rCommands:\n\r" \
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
    "AT? Help\n\n\r"
#ifdef RELAY_DEBUG
    "Debugging commands:\n\r" \
    "ATO DISPOSITION Relay ON\r\n" \
    "ATP DISPOSITION Relay OFF\r\n" \
    "ATX COIN_CONTROL Relay ON\r\n" \
    "ATX COIN_CONTROL Relay OFF\r\n\n"
#endif /* RELAY_DEBUG */
    "Line number (1-4) may be specified after the AT command,\n\r" \
    "for example: ATC2 will collect line 2.\n\r";

bool debug = false;
bool pet_watchdog = true;
volatile uint32_t timer_tick = 0;
unsigned long millis1, millis2, timedelta = 0;
char outstr[255];

typedef struct ky11lb_state {
  uint32_t adrs_reg;    /* UNIBUS Address Register */
  uint32_t temp_reg;    /* Temporary Register */
} ky11lb_state_t;

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

uint8_t coin_line;
uint32_t ioc_count;

typedef int (kp_func_ptr_t)(bool, uint8_t);

typedef struct kp_def {
  const char *str;    /* Name of the key */
  uint8_t kevent;     /* Key Event(s) desired (KEY_DOWN, KEY_UP, KEY_BOTH) */
  uint8_t value;      /* Value of numerical keys */
  bool intr;          /* Whether or not to generate an interrupt to the host. */
  kp_func_ptr_t *fn;  /* Handler function */
} kp_def_t;

ky11lb_state_t fp;

void print_fp_status(void);
static void delay_ms(uint16_t ms);
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

void DEBUG_ERROR(char const * fmt, ...)
{
  char buf[80] = {0};

  va_list args;
  va_start(args, fmt);
  vsnprintf(buf, 80, fmt, args);
  va_end(args);
  Serial.println(buf);
}

#define DEBUG_INFO  DEBUG_ERROR

static void print_version(void)
{
    DEBUG_ERROR("Western Electric 1D Coin Controller Iss 4 Firmware v1.1\n\r" \
                "(c) 2020-2024 Howard M. Harte, WZ2Q\n\r" \
                "http://github.com/hharte/1dcoinctrl\n\r");
}

/* Runs once during boot. */
void setup(void) {

  /* Initialize serial port */
  Serial.swap(1); /* Use PA4/PA5 for UART */
  Serial.begin(BAUD_RATE);

  VPORTC.OUT = 0xFF;
  VPORTD.OUT = 0xFF;

  /* Initialize GPIO Pins */
  pinMode (L1_COIN_CONTROL, OUTPUT);
  pinMode (L2_COIN_CONTROL, OUTPUT);
  pinMode (L3_COIN_CONTROL, OUTPUT);
  pinMode (L4_COIN_CONTROL, OUTPUT);
  pinMode (L1_HOLD_CO,      OUTPUT);
  pinMode (L2_HOLD_CO,      OUTPUT);
  pinMode (L3_HOLD_CO,      OUTPUT);
  pinMode (L4_HOLD_CO,      OUTPUT);
  pinMode (STATUS_LED,      OUTPUT);
  pinMode (REFUND,          OUTPUT);
  pinMode (DISPOSITION,     OUTPUT);

  pinMode (TEST_STATUS_IN,  INPUT_PULLUP);
  pinMode (L1_OFF_HOOK_F,   INPUT_PULLUP);
  pinMode (L1_OFF_HOOK_R,   INPUT_PULLUP);
  pinMode (L2_OFF_HOOK_F,   INPUT_PULLUP);
  pinMode (L2_OFF_HOOK_R,   INPUT_PULLUP);
  pinMode (L3_OFF_HOOK_F,   INPUT_PULLUP);
  pinMode (L3_OFF_HOOK_R,   INPUT_PULLUP);
  pinMode (L4_OFF_HOOK_F,   INPUT_PULLUP);
  pinMode (L4_OFF_HOOK_R,   INPUT_PULLUP);

  takeOverTCA0();
  TCA0.SINGLE.CTRLB = TCA_SINGLE_WGMODE_NORMAL_gc;
  TCA0.SINGLE.EVCTRL &= ~(TCA_SINGLE_CNTEI_bm);
  TCA0.SINGLE.PER = MS_PER_TICK * COUNT_PER_MS;
  TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm; /* Enable timer overflow interrupt */
  TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV256_gc | TCA_SINGLE_ENABLE_bm;

  /* Enable Interrupt on Change for Port D (Hook State) */
  PORTD.PIN0CTRL &= ~(0b00000111);
  PORTD.PIN0CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN1CTRL &= ~(0b00000111);
  PORTD.PIN1CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN2CTRL &= ~(0b00000111);
  PORTD.PIN2CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN3CTRL &= ~(0b00000111);
  PORTD.PIN3CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN4CTRL &= ~(0b00000111);
  PORTD.PIN4CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN5CTRL &= ~(0b00000111);
  PORTD.PIN5CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN6CTRL &= ~(0b00000111);
  PORTD.PIN6CTRL |= PORT_ISC_BOTHEDGES_gc;
  PORTD.PIN7CTRL &= ~(0b00000111);
  PORTD.PIN7CTRL |= PORT_ISC_BOTHEDGES_gc;

  print_version();

  coinctrl_reset();
  coin_line = 0;                      // Set default coin_line

  DEBUG_ERROR("\r\nOK\r\n");
}

/* Main loop: Process serial console and board inputs */
void loop() {
  hook_switch_context_t *pHS;
  uint8_t coin_line;
  char c = 0;
  char atcmd[80];
  uint16_t len = 0;
  uint16_t i;
  uint8_t pps;
  uint8_t digit;
  uint16_t digit_duration;

  if (pet_watchdog) {
    wdt_reset();  /* Pet watchdog timer. */
  }

  while (1) {
    while (c != '\r') {
      if (Serial.available() > 0) {
        /* Read character from the serial port. */
        c = Serial.read();

        if ((c == 0x08) || (c == 0x7F)) {
            len--;
            atcmd[len] = 0;
              Serial.write(0x7F);
        } else {
            atcmd[len] = (char)toupper(c);
            len++;
            Serial.write(c);
        }
      }
    }
    atcmd[len - 1 ] = 0;
    Serial.print("\r");
    c = 0;
    len = 0;

    if (atcmd[0] == 'A' && atcmd[1] == 'T') {
      if (atcmd[3] >= '1' && atcmd[3] < (COIN_LINE_MAX + '1')) {
        coin_line = atcmd[3] - '1';
      } else if (atcmd[3] != 0) {
        Serial.println("ERROR");
        continue;
      }

      DEBUG_INFO("Timer_tick: %lu (last: %lu), ioc_int: %lu, Current Line: %d, hook state: %d -> %d (%d delayed), dial in progress: %d, last dialed_digit: %d",
              timer_tick,
              hs_context[coin_line].last_tick,
              ioc_count,
              coin_line + 1,
              hs_context[coin_line].prev_hook_state,
              hs_context[coin_line].hook_state,
              hs_context[coin_line].hook_state_delayed,
              hs_context[coin_line].dial_in_progress,
              hs_context[coin_line].digits.dialed_digit[(hs_context[coin_line].digits.wptr - 1) & (DIGIT_LIST_ENTRIES_MAX - 1)]);

      switch (atcmd[2]) {
      case 'D': /* Dump current state. */
        digit = hs_context[coin_line].digits.dialed_digit[(hs_context[coin_line].digits.wptr - 1) & (DIGIT_LIST_ENTRIES_MAX - 1)];
        if (digit > 1) {
          /* Calculate PPS */
          digit_duration = hs_context[coin_line].digits.digit_duration;
          pps = (uint8_t)(((digit - 1) * 1000) / (digit_duration / 10));
        }
        DEBUG_ERROR(outstr, sizeof(outstr), "Timer_tick: %lu, Current Line: %d, hook state: %d -> %d, dial in progress: %d, last dialed_digit: %d, %u.%upps",
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
            DEBUG_ERROR("%d: [%u ms] 0x%02x", hs_context[i].rptr,
                    pHS->pulse_list[pHS->rptr].pulse_duration,
                    pHS->pulse_list[pHS->rptr].hook_state);
            pHS->rptr++;
            pHS->rptr &= (PULSE_LIST_ENTRIES_MAX - 1);
          }

          if (pHS->digits.rptr == pHS->digits.wptr) {
            continue;
          }
#endif /* DEBUG_PULSES */
          DEBUG_ERROR("Line %d dialed digits: ", i + 1);

          while (pHS->digits.rptr != pHS->digits.wptr) {
            DEBUG_ERROR("%d, ", pHS->digits.dialed_digit[pHS->digits.rptr]);
            pHS->digits.rptr++;
            pHS->digits.rptr &= (DIGIT_LIST_ENTRIES_MAX - 1); /* Wrap the pointer */
          }
        }
        Serial.println("OK");
        break;
      case 'H':
        set_line_hold_cmd(coin_line, HOLD);
        Serial.println("OK");
        break;
      case 'U':
        set_line_hold_cmd(coin_line, RELEASE);
        Serial.println("OK");
        break;
      case 'C':
        collect_coin(coin_line, COLLECT_COINS);
        Serial.println("OK");
        break;
      case 'R':
        collect_coin(coin_line, REFUND_COINS);
        Serial.println("OK");
        break;
      case 'I':
        DEBUG_ERROR("Initial Rate: %d", test_coin(coin_line, INITIAL_RATE));
        break;
      case 'V':
        print_version();
        Serial.println("OK");
        break;
      case 'S':
        DEBUG_ERROR("Stuck Coin: %d", test_coin(coin_line, STUCK_COIN));
        break;
      case 'T':
        DEBUG_ERROR("Starting test, RESET to exit....");
        while (1) {
          process_coin_lines();
        }
        break;
      case 'Q':
        DEBUG_ERROR("Hook State: %d", hs_context[coin_line].hook_state);
        break;
      case 'L':
        DEBUG_ERROR("%d", coin_line + 1);
        break;
      case 'E':
        for (i = 0; i < 100 ; i++) {
          DEBUG_ERROR("%d: ", i);
          collect_coin(coin_line, REFUND_COINS);
          delay_ms(1000);
        }
        Serial.println("OK");
        break;
#ifdef RELAY_DEBUG
      case 'O':
        DEBUG_ERROR("DISPOSITION_ON");
        DISPOSITION_ON;
        break;
      case 'P':
        DEBUG_ERROR("DISPOSITION_OFF");
        DISPOSITION_OFF;
        break;
      case 'X': /* Activate Coin Control relay */
        DEBUG_ERROR("COIN CONTROL ON");
        do_coin_ctrl(coin_line, true);
        break;
      case 'Y': /* Release Coin Control relay */
        DEBUG_ERROR("COIN CONTROL OFF");
        do_coin_ctrl(coin_line, false);
        break;
#endif /* RELAY_DEBUG */
      case 'Z': /* Reset */
        coinctrl_reset();
        coin_line = 0;  // Set default coin_line
        /* Fall through */
      case 0:
        Serial.println("OK");
        break;
      case '?':
        DEBUG_ERROR(menu);
        Serial.println("OK");
        break;
      default:
        Serial.println("ERROR");
        break;
      }
    }
  }
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
      DEBUG_ERROR("Hook state for line %d changed from %d to %d.",
               coin_line + 1,
               prev_hook_state,
               hook_state);

      switch(hook_state) {
      case ON_HOOK:
        if (prev_hook_state == OFF_HOOK_F) {
          DEBUG_ERROR("Refund coin, line %d.", coin_line + 1);
          collect_coin(coin_line, REFUND_COINS);
        } else if (prev_hook_state == OFF_HOOK_R) {
          DEBUG_ERROR("Collect coin, line %d", coin_line + 1);
          collect_coin(coin_line, COLLECT_COINS);
        }
        break;
      case OFF_HOOK_R:
        if (prev_hook_state == OFF_HOOK_F) {
          DEBUG_ERROR("Collect coin2, line %d", coin_line + 1);
          collect_coin(coin_line, COLLECT_COINS);
        }
      }
      pHS->prev_hook_state = pHS->hook_state_delayed;
    }
  }
}

/* Use the 1ms timer tick to delay for the specified number of milliseconds. */
static void delay_ms(uint16_t ms)
{
  uint32_t end_time;

  end_time = timer_tick + ms;

  while (timer_tick < end_time);
}


/* The TCA0 Timer Tick Interrupt must be higher-priority than the IOC ISR. */
ISR(TCA0_OVF_vect) {
  hook_switch_context_t *pHS;
  uint8_t coin_line;
  uint32_t time_delta;

  TCA0.SINGLE.INTFLAGS  = TCA_SINGLE_OVF_bm; /* Clear interrupt flags */
  timer_tick += 1;

  millis2 = millis1;
  millis1 = millis();

  if ((timer_tick % 500) == 0) {
    bool led_state = VPORTA.OUT & STATUS_LED_B;
    if (led_state) {
      LED_ON();
    } else {
      LED_OFF();
    }
  }

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

/* Hook State ISR */
ISR(PORTD_PORT_vect) {
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

  byte flags = PORTD.INTFLAGS;
  PORTD.INTFLAGS = flags; //clear flags

  ioc_count++;

  hook_state  = ~VPORTD.IN;

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

    DEBUG_ERROR("Line %d, hook_state=%d", coin_line + 1, coin_line_hook_state);

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
    DEBUG_ERROR("Invalid coin_line %d selected.", coin_line + 1);
    return;
  }

  DEBUG_ERROR("%s coin_line %d",
              state ? "Holding" : "Releasing", coin_line + 1);

  switch (coin_line) {
  case 0:
    if (state == true) L1_HOLD_ON; else L1_HOLD_OFF;
    break;
  case 1:
    if (state == true) L2_HOLD_ON; else L2_HOLD_OFF;
    break;
  case 2:
    if (state == true) L3_HOLD_ON; else L3_HOLD_OFF;
    break;
  case 3:
    if (state == true) L4_HOLD_ON; else L4_HOLD_OFF;
    break;
  }
}

/* Command wrapper to put the line on hold, guards against spurious hook state interrupts. */
static void set_line_hold_cmd(uint8_t coin_line, uint8_t state)
{
  set_line_hold(coin_line, state);

  delay_ms(100);   /* Wait for relays to settle. */
  clear_ioc_per_line(coin_line);  /* Prevent spurious interrupts. */
}

static void do_coin_ctrl(uint8_t coin_line, uint8_t state)
{
  if (coin_line >= COIN_LINE_MAX) {
    DEBUG_ERROR("Invalid coin_line %d selected.", coin_line + 1);
    return;
  }

  DEBUG_ERROR("%s coin_line %d Coin Control",
           state ? "Enable" : "Disable", coin_line + 1);

  switch (coin_line) {
  case 0:
    if (state == true) L1_COIN_CTRL_ON; else L1_COIN_CTRL_OFF;
    break;
  case 1:
    if (state == true) L2_COIN_CTRL_ON; else L2_COIN_CTRL_OFF;
    break;
  case 2:
    if (state == true) L3_COIN_CTRL_ON; else L3_COIN_CTRL_OFF;
    break;
  case 3:
    if (state == true) L4_COIN_CTRL_ON; else L4_COIN_CTRL_OFF;
    break;
  }
}

/* Collect or refund the coin in the hopper. */
static void collect_coin(uint8_t coin_line, uint8_t collect)
{
  INTERRUPT_GlobalInterruptLowDisable();

   /* Put CO on hold. */
  set_line_hold(coin_line, true);

  /* Set REFUND relay off */
  if (collect) {
    DEBUG_ERROR("Collecting coin for coin_line %d", coin_line + 1);
    REFUND_OFF;
  } else {
    DEBUG_ERROR("Refunding coin for coin_line %d", coin_line + 1);
    REFUND_ON;
  }

  /* Set DISPOSITION relay on */
  DISPOSITION_ON;

  /* Operate Line COIN Control Relay for 600ms */
  do_coin_ctrl(coin_line, true);
  delay_ms(600);
  do_coin_ctrl(coin_line, false);

  /* Turn DISPOSITION relay off */
  REFUND_OFF;
  DISPOSITION_OFF;
  delay_ms(100);   /* Wait for relays to settle. */
  /* Take coin_line off hold. */
  set_line_hold(coin_line, false);

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
  set_line_hold(coin_line, true);

  /* Set REFUND relay */
  if (initial_rate) {
    REFUND_ON;
  } else {
    REFUND_OFF;
  }

  /* Apply Coin Control Relay and check status of the TEST_STATUS input */
  do_coin_ctrl(coin_line, true);
  delay_ms(50);   /* Wait for test status to settle. */

  result = (TEST_STATUS() == 0);

  do_coin_ctrl(coin_line, false);

  /* Turn REFUND relay off */
  REFUND_OFF;
  delay_ms(200);   /* Wait for relays to settle. */

  /* Remove CO hold. */
  set_line_hold(coin_line, false);
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
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      DEBUG_ERROR("Invalid coin_line %d selected.", coin_line + 1);
      break;
  }
}

static void coinctrl_reset(void)
{
  uint8_t coin_line;

  /* Make sure all relays are off initially. */
  REFUND_OFF;
  DISPOSITION_OFF;

  for (coin_line = 0; coin_line < COIN_LINE_MAX; coin_line++) {
    DEBUG_ERROR("Release coin line %d", coin_line + 1);
    do_coin_ctrl(coin_line, false);
    set_line_hold(coin_line, RELEASE);
  }
  delay_ms(100);
}
