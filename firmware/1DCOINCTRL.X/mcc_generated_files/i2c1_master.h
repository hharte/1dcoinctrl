/**
  I2C1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c1.h

  @Summary
    This is the generated header file for the I2C1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for I2C1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC18F45K50
        Driver Version    :  1.0.0
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

#ifndef I2C1_MASTER_H
#define I2C1_MASTER_H

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    I2C1_NOERR, // The message was sent.
    I2C1_BUSY,  // Message was not sent, bus was busy.
    I2C1_FAIL   // Message was not sent, bus failure
               // If you are interested in the failure reason,
               // Sit on the event call-backs.
} i2c1_error_t;

typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} i2c1_operations_t;

typedef uint8_t i2c1_address_t;
typedef i2c1_operations_t (*i2c1_callback_t)(void *funPtr);

// common callback responses
i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr);
i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr);

/**
 * \brief Initialize I2C1 interface
 *
 * \return Nothing
 */
void I2C1_Initialize(void);

/**
 * \brief Open the I2C1 for communication
 *
 * \param[in] address The slave address to use in the transfer
 *
 * \return Initialization status.
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_Open(i2c1_address_t address);

/**
 * \brief Close the I2C1 interface
 *
 * \return Status of close operation.
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_Close(void);

/**
 * \brief Start an operation on an opened I2C1 interface
 *
 * \param[in] read Set to true for read, false for write
 *
 * \return Status of operation
 * \retval I2C1_NOERR The I2C1 open was successful
 * \retval I2C1_BUSY  The I2C1 open failed because the interface is busy
 * \retval I2C1_FAIL  The I2C1 open failed with an error
 */
i2c1_error_t I2C1_MasterOperation(bool read);

/**
 * \brief Identical to I2C1_MasterOperation(false);
 */
i2c1_error_t I2C1_MasterWrite(void); // to be depreciated

/**
 * \brief Identical to I2C1_MasterOperation(true);
 */
i2c1_error_t I2C1_MasterRead(void); // to be depreciated

/**
 * \brief Set timeout to be used for I2C1 operations. Uses the Timeout driver.
 *
 * \param[in] to Timeout in ticks
 *
 * \return Nothing
 */
void I2C1_SetTimeout(uint8_t timeOut);

/**
 * \brief Sets up the data buffer to use, and number of bytes to transfer
 *
 * \param[in] buffer Pointer to data buffer to use for read or write data
 * \param[in] bufferSize Number of bytes to read or write from slave
 *
 * \return Nothing
 */
void I2C1_SetBuffer(void *buffer, size_t bufferSize);

// Event Callback functions.

/**
 * \brief Set callback to be called when all specifed data has been transferred.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there has been a bus collision and arbitration was lost.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted address was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when the transmitted data was Nack'ed.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr);

/**
 * \brief Set callback to be called when there was a bus timeout.
 *
 * \param[in] cb Pointer to callback function
 * \param[in] ptr  Pointer to the callback function's parameters
 *
 * \return Nothing
 */
void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr);

#endif //I2C1_MASTER_H