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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
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
    PMD_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    TMR0_Initialize();
    UART1_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // NOSC HFINTOSC; NDIV 1; 
    OSCCON1 = 0x60;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; PLLEN enabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x01;
    // HFFRQ 64_MHz; 
    OSCFRQ = 0x08;
    // TUN 0; 
    OSCTUNE = 0x00;
}

void PMD_Initialize(void)
{
    // CLKRMD CLKR enabled; SYSCMD SYSCLK enabled; SCANMD SCANNER enabled; FVRMD FVR enabled; IOCMD IOC enabled; CRCMD CRC enabled; HLVDMD HLVD enabled; 
    PMD0 = 0x00;
    // TMR0MD TMR0 enabled; TMR1MD TMR1 enabled; TMR4MD TMR4 enabled; SMT1MD SMT1 enabled; TMR5MD TMR5 enabled; TMR2MD TMR2 enabled; TMR3MD TMR3 enabled; TMR6MD TMR6 enabled; 
    PMD1 = 0x00;
    // TU1MD UT16A enabled; CANMD CAN enabled; TU2MD UT16B enabled; 
    PMD2 = 0x00;
    // ZCDMD ZCD enabled; DACMD DAC enabled; ADCMD ADC enabled; ACTMD ACT enabled; CM2MD CM2 enabled; CM1MD CM1 enabled; 
    PMD3 = 0x00;
    // NCO1MD NCO1 enabled; NCO2MD NCO2 enabled; DSM1MD DSM1 enabled; CWG3MD CWG3 enabled; CWG2MD CWG2 enabled; CWG1MD CWG1 enabled; NCO3MD NCO3 enabled; 
    PMD4 = 0x00;
    // CCP2MD CCP2 enabled; CCP1MD CCP1 enabled; PWM2MD PWM2 enabled; CCP3MD CCP3 enabled; PWM1MD PWM1 enabled; PWM4MD PWM4 enabled; PWM3MD PWM3 enabled; 
    PMD5 = 0x00;
    // U5MD UART5 enabled; U4MD UART4 enabled; U3MD UART3 enabled; U2MD UART2 enabled; U1MD UART1 enabled; SPI2MD SPI2 enabled; SPI1MD SPI1 enabled; I2C1MD I2C1 enabled; 
    PMD6 = 0x00;
    // CLC5MD CLC5 enabled; CLC6MD CLC6 enabled; CLC3MD CLC3 enabled; CLC4MD CLC4 enabled; CLC7MD CLC7 enabled; CLC8MD CLC8 enabled; CLC1MD CLC1 enabled; CLC2MD CLC2 enabled; 
    PMD7 = 0x00;
    // DMA5MD DMA5 enabled; DMA6MD DMA6 enabled; DMA8MD DMA8 enabled; DMA7MD DMA7 enabled; DMA1MD DMA1 enabled; DMA2MD DMA2 enabled; DMA3MD DMA3 enabled; DMA4MD DMA4 enabled; 
    PMD8 = 0x00;
}


/**
 End of File
*/
