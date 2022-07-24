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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set L1_OFF_HOOK_F aliases
#define L1_OFF_HOOK_F_TRIS                 TRISBbits.TRISB0
#define L1_OFF_HOOK_F_LAT                  LATBbits.LATB0
#define L1_OFF_HOOK_F_PORT                 PORTBbits.RB0
#define L1_OFF_HOOK_F_WPU                  WPUBbits.WPUB0
#define L1_OFF_HOOK_F_OD                   ODCONBbits.ODCB0
#define L1_OFF_HOOK_F_ANS                  ANSELBbits.ANSELB0
#define L1_OFF_HOOK_F_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define L1_OFF_HOOK_F_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define L1_OFF_HOOK_F_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define L1_OFF_HOOK_F_GetValue()           PORTBbits.RB0
#define L1_OFF_HOOK_F_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define L1_OFF_HOOK_F_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define L1_OFF_HOOK_F_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define L1_OFF_HOOK_F_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define L1_OFF_HOOK_F_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define L1_OFF_HOOK_F_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define L1_OFF_HOOK_F_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define L1_OFF_HOOK_F_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set L1_OFF_HOOK_R aliases
#define L1_OFF_HOOK_R_TRIS                 TRISBbits.TRISB1
#define L1_OFF_HOOK_R_LAT                  LATBbits.LATB1
#define L1_OFF_HOOK_R_PORT                 PORTBbits.RB1
#define L1_OFF_HOOK_R_WPU                  WPUBbits.WPUB1
#define L1_OFF_HOOK_R_OD                   ODCONBbits.ODCB1
#define L1_OFF_HOOK_R_ANS                  ANSELBbits.ANSELB1
#define L1_OFF_HOOK_R_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define L1_OFF_HOOK_R_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define L1_OFF_HOOK_R_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define L1_OFF_HOOK_R_GetValue()           PORTBbits.RB1
#define L1_OFF_HOOK_R_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define L1_OFF_HOOK_R_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define L1_OFF_HOOK_R_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define L1_OFF_HOOK_R_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define L1_OFF_HOOK_R_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define L1_OFF_HOOK_R_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define L1_OFF_HOOK_R_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define L1_OFF_HOOK_R_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set L3_HOLD_CO aliases
#define L3_HOLD_CO_TRIS                 TRISBbits.TRISB3
#define L3_HOLD_CO_LAT                  LATBbits.LATB3
#define L3_HOLD_CO_PORT                 PORTBbits.RB3
#define L3_HOLD_CO_WPU                  WPUBbits.WPUB3
#define L3_HOLD_CO_OD                   ODCONBbits.ODCB3
#define L3_HOLD_CO_ANS                  ANSELBbits.ANSELB3
#define L3_HOLD_CO_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define L3_HOLD_CO_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define L3_HOLD_CO_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define L3_HOLD_CO_GetValue()           PORTBbits.RB3
#define L3_HOLD_CO_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define L3_HOLD_CO_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define L3_HOLD_CO_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define L3_HOLD_CO_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define L3_HOLD_CO_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define L3_HOLD_CO_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define L3_HOLD_CO_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define L3_HOLD_CO_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set L4_HOLD_CO aliases
#define L4_HOLD_CO_TRIS                 TRISBbits.TRISB4
#define L4_HOLD_CO_LAT                  LATBbits.LATB4
#define L4_HOLD_CO_PORT                 PORTBbits.RB4
#define L4_HOLD_CO_WPU                  WPUBbits.WPUB4
#define L4_HOLD_CO_OD                   ODCONBbits.ODCB4
#define L4_HOLD_CO_ANS                  ANSELBbits.ANSELB4
#define L4_HOLD_CO_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define L4_HOLD_CO_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define L4_HOLD_CO_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define L4_HOLD_CO_GetValue()           PORTBbits.RB4
#define L4_HOLD_CO_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define L4_HOLD_CO_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define L4_HOLD_CO_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define L4_HOLD_CO_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define L4_HOLD_CO_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define L4_HOLD_CO_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define L4_HOLD_CO_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define L4_HOLD_CO_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set L4_COIN_CONTROL aliases
#define L4_COIN_CONTROL_TRIS                 TRISBbits.TRISB5
#define L4_COIN_CONTROL_LAT                  LATBbits.LATB5
#define L4_COIN_CONTROL_PORT                 PORTBbits.RB5
#define L4_COIN_CONTROL_WPU                  WPUBbits.WPUB5
#define L4_COIN_CONTROL_OD                   ODCONBbits.ODCB5
#define L4_COIN_CONTROL_ANS                  ANSELBbits.ANSELB5
#define L4_COIN_CONTROL_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define L4_COIN_CONTROL_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define L4_COIN_CONTROL_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define L4_COIN_CONTROL_GetValue()           PORTBbits.RB5
#define L4_COIN_CONTROL_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define L4_COIN_CONTROL_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define L4_COIN_CONTROL_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define L4_COIN_CONTROL_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define L4_COIN_CONTROL_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define L4_COIN_CONTROL_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define L4_COIN_CONTROL_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define L4_COIN_CONTROL_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set TEST_STATUS aliases
#define TEST_STATUS_TRIS                 TRISCbits.TRISC0
#define TEST_STATUS_LAT                  LATCbits.LATC0
#define TEST_STATUS_PORT                 PORTCbits.RC0
#define TEST_STATUS_WPU                  WPUCbits.WPUC0
#define TEST_STATUS_OD                   ODCONCbits.ODCC0
#define TEST_STATUS_ANS                  ANSELCbits.ANSELC0
#define TEST_STATUS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TEST_STATUS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TEST_STATUS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TEST_STATUS_GetValue()           PORTCbits.RC0
#define TEST_STATUS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TEST_STATUS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define TEST_STATUS_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define TEST_STATUS_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define TEST_STATUS_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define TEST_STATUS_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define TEST_STATUS_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define TEST_STATUS_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSELC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_WPU                  WPUCbits.WPUC3
#define IO_RC3_OD                   ODCONCbits.ODCC3
#define IO_RC3_ANS                  ANSELCbits.ANSELC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_RC3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSELC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set L1_HOLD_CO aliases
#define L1_HOLD_CO_TRIS                 TRISDbits.TRISD0
#define L1_HOLD_CO_LAT                  LATDbits.LATD0
#define L1_HOLD_CO_PORT                 PORTDbits.RD0
#define L1_HOLD_CO_WPU                  WPUDbits.WPUD0
#define L1_HOLD_CO_OD                   ODCONDbits.ODCD0
#define L1_HOLD_CO_ANS                  ANSELDbits.ANSELD0
#define L1_HOLD_CO_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define L1_HOLD_CO_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define L1_HOLD_CO_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define L1_HOLD_CO_GetValue()           PORTDbits.RD0
#define L1_HOLD_CO_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define L1_HOLD_CO_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define L1_HOLD_CO_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define L1_HOLD_CO_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define L1_HOLD_CO_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define L1_HOLD_CO_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define L1_HOLD_CO_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define L1_HOLD_CO_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set DISPOSITION aliases
#define DISPOSITION_TRIS                 TRISDbits.TRISD1
#define DISPOSITION_LAT                  LATDbits.LATD1
#define DISPOSITION_PORT                 PORTDbits.RD1
#define DISPOSITION_WPU                  WPUDbits.WPUD1
#define DISPOSITION_OD                   ODCONDbits.ODCD1
#define DISPOSITION_ANS                  ANSELDbits.ANSELD1
#define DISPOSITION_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define DISPOSITION_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define DISPOSITION_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define DISPOSITION_GetValue()           PORTDbits.RD1
#define DISPOSITION_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define DISPOSITION_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define DISPOSITION_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define DISPOSITION_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define DISPOSITION_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define DISPOSITION_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define DISPOSITION_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define DISPOSITION_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set REFUND aliases
#define REFUND_TRIS                 TRISDbits.TRISD2
#define REFUND_LAT                  LATDbits.LATD2
#define REFUND_PORT                 PORTDbits.RD2
#define REFUND_WPU                  WPUDbits.WPUD2
#define REFUND_OD                   ODCONDbits.ODCD2
#define REFUND_ANS                  ANSELDbits.ANSELD2
#define REFUND_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define REFUND_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define REFUND_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define REFUND_GetValue()           PORTDbits.RD2
#define REFUND_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define REFUND_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define REFUND_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define REFUND_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define REFUND_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define REFUND_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define REFUND_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define REFUND_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set I2C_RESET_N aliases
#define I2C_RESET_N_TRIS                 TRISDbits.TRISD3
#define I2C_RESET_N_LAT                  LATDbits.LATD3
#define I2C_RESET_N_PORT                 PORTDbits.RD3
#define I2C_RESET_N_WPU                  WPUDbits.WPUD3
#define I2C_RESET_N_OD                   ODCONDbits.ODCD3
#define I2C_RESET_N_ANS                  ANSELDbits.ANSELD3
#define I2C_RESET_N_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define I2C_RESET_N_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define I2C_RESET_N_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define I2C_RESET_N_GetValue()           PORTDbits.RD3
#define I2C_RESET_N_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define I2C_RESET_N_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define I2C_RESET_N_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define I2C_RESET_N_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define I2C_RESET_N_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define I2C_RESET_N_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define I2C_RESET_N_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define I2C_RESET_N_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set L1_COIN_CONTROL aliases
#define L1_COIN_CONTROL_TRIS                 TRISDbits.TRISD4
#define L1_COIN_CONTROL_LAT                  LATDbits.LATD4
#define L1_COIN_CONTROL_PORT                 PORTDbits.RD4
#define L1_COIN_CONTROL_WPU                  WPUDbits.WPUD4
#define L1_COIN_CONTROL_OD                   ODCONDbits.ODCD4
#define L1_COIN_CONTROL_ANS                  ANSELDbits.ANSELD4
#define L1_COIN_CONTROL_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define L1_COIN_CONTROL_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define L1_COIN_CONTROL_GetValue()           PORTDbits.RD4
#define L1_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define L1_COIN_CONTROL_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define L1_COIN_CONTROL_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define L1_COIN_CONTROL_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define L1_COIN_CONTROL_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define L1_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set L2_HOLD_CO aliases
#define L2_HOLD_CO_TRIS                 TRISDbits.TRISD5
#define L2_HOLD_CO_LAT                  LATDbits.LATD5
#define L2_HOLD_CO_PORT                 PORTDbits.RD5
#define L2_HOLD_CO_WPU                  WPUDbits.WPUD5
#define L2_HOLD_CO_OD                   ODCONDbits.ODCD5
#define L2_HOLD_CO_ANS                  ANSELDbits.ANSELD5
#define L2_HOLD_CO_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define L2_HOLD_CO_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define L2_HOLD_CO_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define L2_HOLD_CO_GetValue()           PORTDbits.RD5
#define L2_HOLD_CO_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define L2_HOLD_CO_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define L2_HOLD_CO_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define L2_HOLD_CO_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define L2_HOLD_CO_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define L2_HOLD_CO_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define L2_HOLD_CO_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define L2_HOLD_CO_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set L3_COIN_CONTROL aliases
#define L3_COIN_CONTROL_TRIS                 TRISDbits.TRISD6
#define L3_COIN_CONTROL_LAT                  LATDbits.LATD6
#define L3_COIN_CONTROL_PORT                 PORTDbits.RD6
#define L3_COIN_CONTROL_WPU                  WPUDbits.WPUD6
#define L3_COIN_CONTROL_OD                   ODCONDbits.ODCD6
#define L3_COIN_CONTROL_ANS                  ANSELDbits.ANSELD6
#define L3_COIN_CONTROL_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define L3_COIN_CONTROL_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define L3_COIN_CONTROL_GetValue()           PORTDbits.RD6
#define L3_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define L3_COIN_CONTROL_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define L3_COIN_CONTROL_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define L3_COIN_CONTROL_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define L3_COIN_CONTROL_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define L3_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set L2_COIN_CONTROL aliases
#define L2_COIN_CONTROL_TRIS                 TRISDbits.TRISD7
#define L2_COIN_CONTROL_LAT                  LATDbits.LATD7
#define L2_COIN_CONTROL_PORT                 PORTDbits.RD7
#define L2_COIN_CONTROL_WPU                  WPUDbits.WPUD7
#define L2_COIN_CONTROL_OD                   ODCONDbits.ODCD7
#define L2_COIN_CONTROL_ANS                  ANSELDbits.ANSELD7
#define L2_COIN_CONTROL_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define L2_COIN_CONTROL_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define L2_COIN_CONTROL_GetValue()           PORTDbits.RD7
#define L2_COIN_CONTROL_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define L2_COIN_CONTROL_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define L2_COIN_CONTROL_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define L2_COIN_CONTROL_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define L2_COIN_CONTROL_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define L2_COIN_CONTROL_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

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
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF3 pin functionality
 * @Example
    IOCCF3_ISR();
 */
void IOCCF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_InterruptHandler);

*/
extern void (*IOCCF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_DefaultInterruptHandler);

*/
void IOCCF3_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF4 pin functionality
 * @Example
    IOCCF4_ISR();
 */
void IOCCF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_InterruptHandler);

*/
extern void (*IOCCF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);

*/
void IOCCF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/