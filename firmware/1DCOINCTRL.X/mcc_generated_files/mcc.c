/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F45K50
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.30
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

#include "mcc.h"


void SYSTEM_Initialize(void)
{

    INTERRUPT_Initialize();
    I2C1_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    USBDeviceInit();
    EXT_INT_Initialize();
    TMR0_Initialize();
    USBDeviceAttach();
    EUSART1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; IDLEN disabled; IRCF 16MHz; 
    OSCCON = 0x70;
    // INTSRC INTRC_31_25KHz; PLLEN disabled; PRISD disabled; SOSCGO disabled; 
    OSCCON2 = 0x00;
    // SPLLMULT 3xPLL; TUN 0; 
    OSCTUNE = 0x80;
    // ACTSRC SOSC; ACTUD enabled; ACTEN disabled; 
    ACTCON = 0x00;
    // Wait for PLL to stabilize
    while(PLLRDY == 0)
    {
    }
}


/**
 End of File
*/
