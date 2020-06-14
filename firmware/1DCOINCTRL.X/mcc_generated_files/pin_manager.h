/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F45K50
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set L3_HOLD_CO aliases
#define L3_HOLD_CO_TRIS                 TRISBbits.TRISB0
#define L3_HOLD_CO_LAT                  LATBbits.LATB0
#define L3_HOLD_CO_PORT                 PORTBbits.RB0
#define L3_HOLD_CO_WPU                  WPUBbits.WPUB0
#define L3_HOLD_CO_ANS                  ANSELBbits.ANSB0
#define L3_HOLD_CO_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define L3_HOLD_CO_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define L3_HOLD_CO_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define L3_HOLD_CO_GetValue()           PORTBbits.RB0
#define L3_HOLD_CO_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define L3_HOLD_CO_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define L3_HOLD_CO_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define L3_HOLD_CO_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define L3_HOLD_CO_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define L3_HOLD_CO_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set L4_COIN_CONTROL aliases
#define L4_COIN_CONTROL_TRIS                 TRISBbits.TRISB1
#define L4_COIN_CONTROL_LAT                  LATBbits.LATB1
#define L4_COIN_CONTROL_PORT                 PORTBbits.RB1
#define L4_COIN_CONTROL_WPU                  WPUBbits.WPUB1
#define L4_COIN_CONTROL_ANS                  ANSELBbits.ANSB1
#define L4_COIN_CONTROL_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define L4_COIN_CONTROL_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define L4_COIN_CONTROL_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define L4_COIN_CONTROL_GetValue()           PORTBbits.RB1
#define L4_COIN_CONTROL_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define L4_COIN_CONTROL_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define L4_COIN_CONTROL_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define L4_COIN_CONTROL_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define L4_COIN_CONTROL_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define L4_COIN_CONTROL_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set L1_OFF_HOOK aliases
#define L1_OFF_HOOK_TRIS                 TRISBbits.TRISB2
#define L1_OFF_HOOK_LAT                  LATBbits.LATB2
#define L1_OFF_HOOK_PORT                 PORTBbits.RB2
#define L1_OFF_HOOK_WPU                  WPUBbits.WPUB2
#define L1_OFF_HOOK_ANS                  ANSELBbits.ANSB2
#define L1_OFF_HOOK_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define L1_OFF_HOOK_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define L1_OFF_HOOK_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define L1_OFF_HOOK_GetValue()           PORTBbits.RB2
#define L1_OFF_HOOK_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define L1_OFF_HOOK_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define L1_OFF_HOOK_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define L1_OFF_HOOK_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define L1_OFF_HOOK_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define L1_OFF_HOOK_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set L2_OFF_HOOK aliases
#define L2_OFF_HOOK_TRIS                 TRISBbits.TRISB3
#define L2_OFF_HOOK_LAT                  LATBbits.LATB3
#define L2_OFF_HOOK_PORT                 PORTBbits.RB3
#define L2_OFF_HOOK_WPU                  WPUBbits.WPUB3
#define L2_OFF_HOOK_ANS                  ANSELBbits.ANSB3
#define L2_OFF_HOOK_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define L2_OFF_HOOK_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define L2_OFF_HOOK_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define L2_OFF_HOOK_GetValue()           PORTBbits.RB3
#define L2_OFF_HOOK_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define L2_OFF_HOOK_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define L2_OFF_HOOK_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define L2_OFF_HOOK_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define L2_OFF_HOOK_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define L2_OFF_HOOK_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set L3_OFF_HOOK aliases
#define L3_OFF_HOOK_TRIS                 TRISBbits.TRISB4
#define L3_OFF_HOOK_LAT                  LATBbits.LATB4
#define L3_OFF_HOOK_PORT                 PORTBbits.RB4
#define L3_OFF_HOOK_WPU                  WPUBbits.WPUB4
#define L3_OFF_HOOK_ANS                  ANSELBbits.ANSB4
#define L3_OFF_HOOK_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define L3_OFF_HOOK_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define L3_OFF_HOOK_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define L3_OFF_HOOK_GetValue()           PORTBbits.RB4
#define L3_OFF_HOOK_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define L3_OFF_HOOK_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define L3_OFF_HOOK_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define L3_OFF_HOOK_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define L3_OFF_HOOK_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define L3_OFF_HOOK_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set L4_OFF_HOOK aliases
#define L4_OFF_HOOK_TRIS                 TRISBbits.TRISB5
#define L4_OFF_HOOK_LAT                  LATBbits.LATB5
#define L4_OFF_HOOK_PORT                 PORTBbits.RB5
#define L4_OFF_HOOK_WPU                  WPUBbits.WPUB5
#define L4_OFF_HOOK_ANS                  ANSELBbits.ANSB5
#define L4_OFF_HOOK_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define L4_OFF_HOOK_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define L4_OFF_HOOK_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define L4_OFF_HOOK_GetValue()           PORTBbits.RB5
#define L4_OFF_HOOK_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define L4_OFF_HOOK_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define L4_OFF_HOOK_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define L4_OFF_HOOK_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define L4_OFF_HOOK_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define L4_OFF_HOOK_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set TEST_STATUS aliases
#define TEST_STATUS_TRIS                 TRISCbits.TRISC0
#define TEST_STATUS_LAT                  LATCbits.LATC0
#define TEST_STATUS_PORT                 PORTCbits.RC0
#define TEST_STATUS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TEST_STATUS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TEST_STATUS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TEST_STATUS_GetValue()           PORTCbits.RC0
#define TEST_STATUS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TEST_STATUS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set L1_HOLD_CO aliases
#define L1_HOLD_CO_TRIS                 TRISDbits.TRISD0
#define L1_HOLD_CO_LAT                  LATDbits.LATD0
#define L1_HOLD_CO_PORT                 PORTDbits.RD0
#define L1_HOLD_CO_ANS                  ANSELDbits.ANSD0
#define L1_HOLD_CO_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define L1_HOLD_CO_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define L1_HOLD_CO_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define L1_HOLD_CO_GetValue()           PORTDbits.RD0
#define L1_HOLD_CO_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define L1_HOLD_CO_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define L1_HOLD_CO_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define L1_HOLD_CO_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set DISPOSITION aliases
#define DISPOSITION_TRIS                 TRISDbits.TRISD1
#define DISPOSITION_LAT                  LATDbits.LATD1
#define DISPOSITION_PORT                 PORTDbits.RD1
#define DISPOSITION_ANS                  ANSELDbits.ANSD1
#define DISPOSITION_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define DISPOSITION_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define DISPOSITION_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define DISPOSITION_GetValue()           PORTDbits.RD1
#define DISPOSITION_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define DISPOSITION_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define DISPOSITION_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define DISPOSITION_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set REFUND aliases
#define REFUND_TRIS                 TRISDbits.TRISD2
#define REFUND_LAT                  LATDbits.LATD2
#define REFUND_PORT                 PORTDbits.RD2
#define REFUND_ANS                  ANSELDbits.ANSD2
#define REFUND_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define REFUND_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define REFUND_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define REFUND_GetValue()           PORTDbits.RD2
#define REFUND_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define REFUND_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define REFUND_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define REFUND_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set L4_HOLD_CO aliases
#define L4_HOLD_CO_TRIS                 TRISDbits.TRISD3
#define L4_HOLD_CO_LAT                  LATDbits.LATD3
#define L4_HOLD_CO_PORT                 PORTDbits.RD3
#define L4_HOLD_CO_ANS                  ANSELDbits.ANSD3
#define L4_HOLD_CO_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define L4_HOLD_CO_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define L4_HOLD_CO_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define L4_HOLD_CO_GetValue()           PORTDbits.RD3
#define L4_HOLD_CO_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define L4_HOLD_CO_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define L4_HOLD_CO_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define L4_HOLD_CO_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set L1_COIN_CONTROL aliases
#define L1_COIN_CONTROL_TRIS                 TRISDbits.TRISD4
#define L1_COIN_CONTROL_LAT                  LATDbits.LATD4
#define L1_COIN_CONTROL_PORT                 PORTDbits.RD4
#define L1_COIN_CONTROL_ANS                  ANSELDbits.ANSD4
#define L1_COIN_CONTROL_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define L1_COIN_CONTROL_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define L1_COIN_CONTROL_GetValue()           PORTDbits.RD4
#define L1_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define L1_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set L2_HOLD_CO aliases
#define L2_HOLD_CO_TRIS                 TRISDbits.TRISD5
#define L2_HOLD_CO_LAT                  LATDbits.LATD5
#define L2_HOLD_CO_PORT                 PORTDbits.RD5
#define L2_HOLD_CO_ANS                  ANSELDbits.ANSD5
#define L2_HOLD_CO_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define L2_HOLD_CO_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define L2_HOLD_CO_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define L2_HOLD_CO_GetValue()           PORTDbits.RD5
#define L2_HOLD_CO_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define L2_HOLD_CO_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define L2_HOLD_CO_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define L2_HOLD_CO_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set L3_COIN_CONTROL aliases
#define L3_COIN_CONTROL_TRIS                 TRISDbits.TRISD6
#define L3_COIN_CONTROL_LAT                  LATDbits.LATD6
#define L3_COIN_CONTROL_PORT                 PORTDbits.RD6
#define L3_COIN_CONTROL_ANS                  ANSELDbits.ANSD6
#define L3_COIN_CONTROL_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define L3_COIN_CONTROL_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define L3_COIN_CONTROL_GetValue()           PORTDbits.RD6
#define L3_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define L3_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set L2_COIN_CONTROL aliases
#define L2_COIN_CONTROL_TRIS                 TRISDbits.TRISD7
#define L2_COIN_CONTROL_LAT                  LATDbits.LATD7
#define L2_COIN_CONTROL_PORT                 PORTDbits.RD7
#define L2_COIN_CONTROL_ANS                  ANSELDbits.ANSD7
#define L2_COIN_CONTROL_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define L2_COIN_CONTROL_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define L2_COIN_CONTROL_GetValue()           PORTDbits.RD7
#define L2_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define L2_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/