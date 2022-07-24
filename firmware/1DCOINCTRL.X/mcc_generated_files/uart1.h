/**
  UART1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    uart1.h

  @Summary
    This is the generated header file for the UART1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for UART1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.4.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
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

#ifndef UART1_H
#define UART1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

#define UART1_DataReady  (UART1_is_rx_ready())

/**
  Section: Data Type Definitions
*/

typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}uart1_status_t;


/**
  Section: UART1 APIs
*/

/**
  @Summary
    Initialization routine that takes inputs from the UART1 GUI.

  @Description
    This routine initializes the UART1 driver.
    This routine must be called before any other UART1 routine is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment

  @Example
*/
void UART1_Initialize(void);

/**
  @Summary
    Checks if the UART1 receiver ready for reading

  @Description
    This routine checks if UART1 receiver has received data 
    and ready to be read

  @Preconditions
    UART1_Initialize() function should be called
    before calling this function
    UART1 receiver should be enabled before calling this 
    function

  @Param
    None

  @Returns
    Status of UART1 receiver
    TRUE: UART1 receiver is ready for reading
    FALSE: UART1 receiver is not ready for reading
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            // Logic to echo received data
            if(UART1_is_rx_ready())
            {
                rxData = UART1_Read();
                if(UART1_is_tx_ready())
                {
                    UART1_Write(rxData);
                }
            }
        }
    }
    </code>
*/
bool UART1_is_rx_ready(void);

/**
  @Summary
    Checks if the UART1 transmitter is ready to transmit data

  @Description
    This routine checks if UART1 transmitter is ready 
    to accept and transmit data byte

  @Preconditions
    UART1_Initialize() function should have been called
    before calling this function.
    UART1 transmitter should be enabled before calling 
    this function

  @Param
    None

  @Returns
    Status of UART1 transmitter
    TRUE: UART1 transmitter is ready
    FALSE: UART1 transmitter is not ready
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            // Logic to echo received data
            if(UART1_is_rx_ready())
            {
                rxData = UART1_Read();
                if(UART1_is_tx_ready())
                {
                    UART1_Write(rxData);
                }
            }
        }
    }
    </code>
*/
bool UART1_is_tx_ready(void);

/**
  @Summary
    Checks if UART1 data is transmitted

  @Description
    This function return the status of transmit shift register

  @Preconditions
    UART1_Initialize() function should be called
    before calling this function
    UART1 transmitter should be enabled and UART1_Write
    should be called before calling this function

  @Param
    None

  @Returns
    Status of UART1 transmit shift register
    TRUE: Data completely shifted out if the UART shift register
    FALSE: Data is not completely shifted out of the shift register
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            if(UART1_is_tx_ready())
            {
                LED_0_SetHigh();
                UART1Write(rxData);
            }
            if(UART1_is_tx_done()
            {
                LED_0_SetLow();
            }
        }
    }
    </code>
*/
bool UART1_is_tx_done(void);

/**
  @Summary
    Gets the error status of the last read byte.

  @Description
    This routine gets the error status of the last read byte.

  @Preconditions
    UART1_Initialize() function should have been called
    before calling this function. The returned value is only
    updated after a read is called.

  @Param
    None

  @Returns
    the status of the last read byte

  @Example
	<code>
    void main(void)
    {
        volatile uint8_t rxData;
        volatile uart1_status_t rxStatus;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        // Enable the Global Interrupts
        INTERRUPT_GlobalInterruptEnable();
        
        while(1)
        {
            // Logic to echo received data
            if(UART1_is_rx_ready())
            {
                rxData = UART1_Read();
                rxStatus = UART1_get_last_status();
                if(rxStatus.ferr){
                    LED_0_SetHigh();
                }
            }
        }
    }
    </code>
 */
uart1_status_t UART1_get_last_status(void);

/**
  @Summary
    Read a byte of data from the UART1.

  @Description
    This routine reads a byte of data from the UART1.

  @Preconditions
    UART1_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if the receiver is not empty before calling this function.
	
	UART1_DataReady is a macro which checks if any byte is received.
	Call this macro before using this function.

  @Param
    None

  @Returns
    A data byte received by the driver.
	
  @Example
	<code>
            void main(void) {
                            // initialize the device
                            SYSTEM_Initialize();
                            uint8_t data;

                            // Enable the Global Interrupts
                            INTERRUPT_GlobalInterruptEnable();

                            // Enable the Peripheral Interrupts
                            INTERRUPT_PeripheralInterruptEnable();

                            printf("\t\tTEST CODE\n\r");		//Enable redirect STDIO to USART before using printf statements
                            printf("\t\t---- ----\n\r");
                            printf("\t\tECHO TEST\n\r");
                            printf("\t\t---- ----\n\n\r");
                            printf("Enter any string: ");
                            do{
                            data = UART1_Read();		// Read data received
                            UART1_Write(data);			// Echo back the data received
                            }while(!UART1_DataReady);		//check if any data is received

                    }
    </code>
*/
uint8_t UART1_Read(void);

 /**
  @Summary
    Writes a byte of data to the UART1.

  @Description
    This routine writes a byte of data to the UART1.

  @Preconditions
    UART1_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if transmitter is not busy before calling this function.

  @Param
    txData  - Data byte to write to the UART1

  @Returns
    None
  
  @Example
      <code>
          Refer to UART1_Read() for an example	
      </code>
*/
void UART1_Write(uint8_t txData);



/**
  @Summary
    Set UART1 Framing Error Handler

  @Description
    This API sets the function to be called upon UART1 framing error

  @Preconditions
    Initialize  the UART1 before calling this API

  @Param
    Address of function to be set as framing error handler

  @Returns
    None
*/
void UART1_SetFramingErrorHandler(void (* interruptHandler)(void));

/**
  @Summary
    Set UART1 Overrun Error Handler

  @Description
    This API sets the function to be called upon UART1 overrun error

  @Preconditions
    Initialize  the UART1 module before calling this API

  @Param
    Address of function to be set as overrun error handler

  @Returns
    None
*/
void UART1_SetOverrunErrorHandler(void (* interruptHandler)(void));

/**
  @Summary
    Set UART1 Error Handler

  @Description
    This API sets the function to be called upon UART1 error

  @Preconditions
    Initialize  the UART1 module before calling this API

  @Param
    Address of function to be set as error handler

  @Returns
    None
*/
void UART1_SetErrorHandler(void (* interruptHandler)(void));











#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // UART1_H
/**
 End of File
*/
