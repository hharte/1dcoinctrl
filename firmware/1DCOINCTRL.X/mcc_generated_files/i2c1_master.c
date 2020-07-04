/**
  I2C1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c1.c

  @Summary
    This is the generated driver implementation file for the I2C1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for I2C1.
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

#include "i2c1_master.h"
#include <xc.h>

// I2C1 STATES
typedef enum {
    I2C1_IDLE = 0,
    I2C1_SEND_ADR_READ,
    I2C1_SEND_ADR_WRITE,
    I2C1_TX,
    I2C1_RX,
    I2C1_RCEN,
    I2C1_TX_EMPTY,      
    I2C1_SEND_RESTART_READ,
    I2C1_SEND_RESTART_WRITE,
    I2C1_SEND_RESTART,
    I2C1_SEND_STOP,
    I2C1_RX_ACK,
    I2C1_RX_NACK_STOP,
    I2C1_RX_NACK_RESTART,
    I2C1_RESET,
    I2C1_ADDRESS_NACK,

} i2c1_fsm_states_t;

// I2C1 Event callBack List
typedef enum {
    I2C1_DATA_COMPLETE = 0,
    I2C1_WRITE_COLLISION,
    I2C1_ADDR_NACK,
    I2C1_DATA_NACK,
    I2C1_TIMEOUT,
    I2C1_NULL
} i2c1_callbackIndex_t;

// I2C1 Status Structure
typedef struct
{
    i2c1_callback_t callbackTable[6];
    void *callbackPayload[6];           //  each callBack can have a payload
    uint16_t time_out;                  // I2C1 Timeout Counter between I2C1 Events.
    uint16_t time_out_value;            // Reload value for the timeouts
    i2c1_address_t address;             // The I2C1 Address
    uint8_t *data_ptr;                  // pointer to a data buffer
    size_t data_length;                 // Bytes in the data buffer
    i2c1_fsm_states_t state;            // Driver State
    i2c1_error_t error;
    unsigned addressNackCheck:1;
    unsigned busy:1;
    unsigned inUse:1;
    unsigned bufferFree:1;

} i2c1_status_t;

static void I2C1_SetCallback(i2c1_callbackIndex_t idx, i2c1_callback_t cb, void *ptr);
static void I2C1_Poller(void);
static inline void I2C1_MasterFsm(void);

/* I2C1 interfaces */
static inline bool I2C1_MasterOpen(void);
static inline void I2C1_MasterClose(void);    
static inline uint8_t I2C1_MasterGetRxData(void);
static inline void I2C1_MasterSendTxData(uint8_t data);
static inline void I2C1_MasterEnableRestart(void);
static inline void I2C1_MasterDisableRestart(void);
static inline void I2C1_MasterStartRx(void);
static inline void I2C1_MasterStart(void);
static inline void I2C1_MasterStop(void);
static inline bool I2C1_MasterIsNack(void);
static inline void I2C1_MasterSendAck(void);
static inline void I2C1_MasterSendNack(void);
static inline void I2C1_MasterClearBusCollision(void);

/* Interrupt interfaces */
static inline void I2C1_MasterEnableIrq(void);
static inline bool I2C1_MasterIsIrqEnabled(void);
static inline void I2C1_MasterDisableIrq(void);
static inline void I2C1_MasterClearIrq(void);
static inline void I2C1_MasterSetIrq(void);
static inline void I2C1_MasterWaitForEvent(void);

static i2c1_fsm_states_t I2C1_DO_IDLE(void);
static i2c1_fsm_states_t I2C1_DO_SEND_ADR_READ(void);
static i2c1_fsm_states_t I2C1_DO_SEND_ADR_WRITE(void);
static i2c1_fsm_states_t I2C1_DO_TX(void);
static i2c1_fsm_states_t I2C1_DO_RX(void);
static i2c1_fsm_states_t I2C1_DO_RCEN(void);
static i2c1_fsm_states_t I2C1_DO_TX_EMPTY(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_READ(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_WRITE(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART(void);
static i2c1_fsm_states_t I2C1_DO_SEND_STOP(void);
static i2c1_fsm_states_t I2C1_DO_RX_ACK(void);
static i2c1_fsm_states_t I2C1_DO_RX_NACK_STOP(void);
static i2c1_fsm_states_t I2C1_DO_RX_NACK_RESTART(void);
static i2c1_fsm_states_t I2C1_DO_RESET(void);
static i2c1_fsm_states_t I2C1_DO_ADDRESS_NACK(void);


typedef i2c1_fsm_states_t (*fsmHandlerFunction)(void);
const fsmHandlerFunction fsmStateTable[] = {
    I2C1_DO_IDLE,
    I2C1_DO_SEND_ADR_READ,
    I2C1_DO_SEND_ADR_WRITE,
    I2C1_DO_TX,
    I2C1_DO_RX,
    I2C1_DO_RCEN,
    I2C1_DO_TX_EMPTY,
    I2C1_DO_SEND_RESTART_READ,
    I2C1_DO_SEND_RESTART_WRITE,
    I2C1_DO_SEND_RESTART,
    I2C1_DO_SEND_STOP,
    I2C1_DO_RX_ACK,
    I2C1_DO_RX_NACK_STOP,
    I2C1_DO_RX_NACK_RESTART,
    I2C1_DO_RESET,
    I2C1_DO_ADDRESS_NACK,
};

i2c1_status_t I2C1_Status = {0};

void I2C1_Initialize()
{
    SSP1STAT = 0x00;
    SSP1CON1 = 0x08;
    SSP1CON2 = 0x00;
    SSP1ADD  = 0x77;
    SSP1CON1bits.SSPEN = 0;
}

i2c1_error_t I2C1_Open(i2c1_address_t address)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    
    if(!I2C1_Status.inUse)
    {
        I2C1_Status.address = address;
        I2C1_Status.busy = 0;
        I2C1_Status.inUse = 1;
        I2C1_Status.addressNackCheck = 0;
        I2C1_Status.state = I2C1_RESET;
        I2C1_Status.time_out_value = 500; // MCC should determine a reasonable starting value here.
        I2C1_Status.bufferFree = 1;

        // set all the call backs to a default of sending stop
        I2C1_Status.callbackTable[I2C1_DATA_COMPLETE]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE] = NULL;
        I2C1_Status.callbackTable[I2C1_WRITE_COLLISION]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_WRITE_COLLISION] = NULL;
        I2C1_Status.callbackTable[I2C1_ADDR_NACK]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_ADDR_NACK] = NULL;
        I2C1_Status.callbackTable[I2C1_DATA_NACK]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_DATA_NACK] = NULL;
        I2C1_Status.callbackTable[I2C1_TIMEOUT]=I2C1_CallbackReturnReset;
        I2C1_Status.callbackPayload[I2C1_TIMEOUT] = NULL;
        
        I2C1_MasterClearIrq();
        I2C1_MasterOpen();
        returnValue = I2C1_NOERR;
    }
    return returnValue;
}

i2c1_error_t I2C1_Close(void)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    if(!I2C1_Status.busy)
    {
        I2C1_Status.inUse = 0;
        I2C1_Status.address = 0xff;
        I2C1_MasterClearIrq();
        I2C1_MasterDisableIrq();
        I2C1_MasterClose();
        returnValue = I2C1_Status.error;
    }
    return returnValue;
}

i2c1_error_t I2C1_MasterOperation(bool read)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    if(!I2C1_Status.busy)
    {
        I2C1_Status.busy = true;
        returnValue = I2C1_NOERR;

        if(read)
        {
            I2C1_Status.state = I2C1_SEND_ADR_READ;
        }
        else
        {
            I2C1_Status.state = I2C1_SEND_ADR_WRITE;
        }
        I2C1_MasterStart();
        I2C1_Poller();
    }
    return returnValue;
}

i2c1_error_t I2C1_MasterRead(void)
{
    return I2C1_MasterOperation(true);
}

i2c1_error_t I2C1_MasterWrite(void)
{
    return I2C1_MasterOperation(false);
}

void I2C1_SetTimeOut(uint8_t timeOutValue)
{
    I2C1_MasterDisableIrq();
    I2C1_Status.time_out_value = timeOutValue;
    I2C1_MasterEnableIrq();
}

void I2C1_SetBuffer(void *buffer, size_t bufferSize)
{
    if(I2C1_Status.bufferFree)
    {
        I2C1_Status.data_ptr = buffer;
        I2C1_Status.data_length = bufferSize;
        I2C1_Status.bufferFree = false;
    }
}

void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_DATA_COMPLETE, cb, ptr);
}

void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_WRITE_COLLISION, cb, ptr);
}

void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_ADDR_NACK, cb, ptr);
}

void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_DATA_NACK, cb, ptr);
}

void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_TIMEOUT, cb, ptr);
}

static void I2C1_SetCallback(i2c1_callbackIndex_t idx, i2c1_callback_t cb, void *ptr)
{
    if(cb)
    {
        I2C1_Status.callbackTable[idx] = cb;
        I2C1_Status.callbackPayload[idx] = ptr;
    }
    else
    {
        I2C1_Status.callbackTable[idx] = I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[idx] = NULL;
    }
}

static void I2C1_Poller(void)
{
    while(I2C1_Status.busy)
    {
        I2C1_MasterWaitForEvent();
        I2C1_MasterFsm();
    }
}

static inline void I2C1_MasterFsm(void)
{
    I2C1_MasterClearIrq();

    if(I2C1_Status.addressNackCheck && I2C1_MasterIsNack())
    {
        I2C1_Status.state = I2C1_ADDRESS_NACK;
    }
    I2C1_Status.state = fsmStateTable[I2C1_Status.state]();
}


static i2c1_fsm_states_t I2C1_DO_IDLE(void)
{
    I2C1_Status.busy = false;
    I2C1_Status.error = I2C1_NOERR;
    return I2C1_RESET;
}

static i2c1_fsm_states_t I2C1_DO_SEND_ADR_READ(void)
{
    I2C1_Status.addressNackCheck = 1;
    I2C1_MasterSendTxData(I2C1_Status.address << 1 | 1);
    return I2C1_RCEN;
}

static i2c1_fsm_states_t I2C1_DO_SEND_ADR_WRITE(void)
{
    I2C1_Status.addressNackCheck = 1;
    I2C1_MasterSendTxData(I2C1_Status.address << 1);
    return I2C1_TX;
}

static i2c1_fsm_states_t I2C1_DO_TX(void)
{
    if(I2C1_MasterIsNack())
    {
        switch(I2C1_Status.callbackTable[I2C1_DATA_NACK](I2C1_Status.callbackPayload[I2C1_DATA_NACK]))
        {
            case I2C1_RESTART_READ:
                return I2C1_DO_SEND_RESTART_READ();
            case I2C1_RESTART_WRITE:
                  return I2C1_DO_SEND_RESTART_WRITE();
            default:
            case I2C1_CONTINUE:
            case I2C1_STOP:
                return I2C1_DO_SEND_STOP();
        }
    }
    else
    {
        I2C1_Status.addressNackCheck = 0;
        I2C1_MasterSendTxData(*I2C1_Status.data_ptr++);
        return (--I2C1_Status.data_length)?I2C1_TX:I2C1_TX_EMPTY;
    }
}

static i2c1_fsm_states_t I2C1_DO_RX(void)
{
    *I2C1_Status.data_ptr++ = I2C1_MasterGetRxData();
    if(--I2C1_Status.data_length)
    {
        I2C1_MasterSendAck();
        return I2C1_RCEN;
    }
    else
    {
        I2C1_Status.bufferFree = true;
        switch(I2C1_Status.callbackTable[I2C1_DATA_COMPLETE](I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE]))
        {
            case I2C1_RESTART_WRITE:
            case I2C1_RESTART_READ:
                return I2C1_DO_RX_NACK_RESTART();
            default:
            case I2C1_CONTINUE:
            case I2C1_STOP:
                return I2C1_DO_RX_NACK_STOP();
        }
    }
}

static i2c1_fsm_states_t I2C1_DO_RCEN(void)
{
    I2C1_Status.addressNackCheck = 0;
    I2C1_MasterStartRx();
    return I2C1_RX;
}

static i2c1_fsm_states_t I2C1_DO_TX_EMPTY(void)
{
    I2C1_Status.bufferFree = true;
    switch(I2C1_Status.callbackTable[I2C1_DATA_COMPLETE](I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE]))
    {
        case I2C1_RESTART_READ:
        case I2C1_RESTART_WRITE:
            return I2C1_DO_SEND_RESTART();
        case I2C1_CONTINUE:
            I2C1_MasterSetIrq();
            return I2C1_TX;
        default:
        case I2C1_STOP:
            return I2C1_DO_SEND_STOP();
    }
}

static i2c1_fsm_states_t I2C1_DO_RX_EMPTY(void)
{
    I2C1_Status.bufferFree = true;
    switch(I2C1_Status.callbackTable[I2C1_DATA_COMPLETE](I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE]))
    {
        case I2C1_RESTART_WRITE:
            I2C1_MasterEnableRestart();
            return I2C1_SEND_RESTART_WRITE;
        case I2C1_RESTART_READ:
            I2C1_MasterEnableRestart();
            return I2C1_SEND_RESTART_READ;
        case I2C1_CONTINUE:
            // Avoid the counter stop condition , Counter is incremented by 1
            return I2C1_RX;
        default:
        case I2C1_STOP:
            if(I2C1_Status.state != I2C1_SEND_RESTART_READ)
            {
                I2C1_MasterDisableRestart();
            }
            return I2C1_RESET;
    }
}

static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_READ(void)
{
    I2C1_MasterEnableRestart();
    return I2C1_SEND_ADR_READ;
}

static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_WRITE(void)
{
    I2C1_MasterEnableRestart();
    return I2C1_SEND_ADR_WRITE;
}


static i2c1_fsm_states_t I2C1_DO_SEND_RESTART(void)
{
    I2C1_MasterEnableRestart();
    return I2C1_SEND_ADR_READ;
}

static i2c1_fsm_states_t I2C1_DO_SEND_STOP(void)
{
    I2C1_MasterStop();
    return I2C1_IDLE;
}

static i2c1_fsm_states_t I2C1_DO_RX_ACK(void)
{
    I2C1_MasterSendAck();
    return I2C1_RCEN;
}


static i2c1_fsm_states_t I2C1_DO_RX_NACK_STOP(void)
{
    I2C1_MasterSendNack();
    return I2C1_SEND_STOP;
}

static i2c1_fsm_states_t I2C1_DO_RX_NACK_RESTART(void)
{
    I2C1_MasterSendNack();
    return I2C1_SEND_RESTART;
}

static i2c1_fsm_states_t I2C1_DO_RESET(void)
{
    I2C1_Status.busy = false;
    I2C1_Status.error = I2C1_NOERR;
    return I2C1_RESET;
}
static i2c1_fsm_states_t I2C1_DO_ADDRESS_NACK(void)
{
    I2C1_Status.addressNackCheck = 0;
    I2C1_Status.error = I2C1_FAIL;
    switch(I2C1_Status.callbackTable[I2C1_ADDR_NACK](I2C1_Status.callbackPayload[I2C1_ADDR_NACK]))
    {
        case I2C1_RESTART_READ:
        case I2C1_RESTART_WRITE:
            return I2C1_DO_SEND_RESTART();
        default:
            return I2C1_DO_SEND_STOP();
    }
}

void I2C1_BusCollisionIsr(void)
{
    I2C1_MasterClearBusCollision();
    I2C1_Status.state = I2C1_RESET;
}

i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr)
{
    return I2C1_STOP;
}

i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr)
{
    return I2C1_RESET_LINK;
}

i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr)
{
    return I2C1_RESTART_WRITE;
}

i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr)
{
    return I2C1_RESTART_READ;
}



/* I2C1 Register Level interfaces */
static inline bool I2C1_MasterOpen(void)
{
    if(!SSP1CON1bits.SSPEN)
    {
        SSP1STAT = 0x00;
        SSP1CON1 = 0x08;
        SSP1CON2 = 0x00;
        SSP1ADD = 0x77;
        SSP1CON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

static inline void I2C1_MasterClose(void)
{
    //Disable I2C1
    SSP1CON1bits.SSPEN = 0;
}

static inline uint8_t I2C1_MasterGetRxData(void)
{
    return SSP1BUF;
}

static inline void I2C1_MasterSendTxData(uint8_t data)
{
    SSP1BUF  = data;
}

static inline void I2C1_MasterEnableRestart(void)
{
    SSP1CON2bits.RSEN = 1;
}

static inline void I2C1_MasterDisableRestart(void)
{
    SSP1CON2bits.RSEN = 0;
}

static inline void I2C1_MasterStartRx(void)
{
    SSP1CON2bits.RCEN = 1;
}

static inline void I2C1_MasterStart(void)
{
    SSP1CON2bits.SEN = 1;
}

static inline void I2C1_MasterStop(void)
{
    SSP1CON2bits.PEN = 1;
}

static inline bool I2C1_MasterIsNack(void)
{
    return SSP1CON2bits.ACKSTAT;
}

static inline void I2C1_MasterSendAck(void)
{
    SSP1CON2bits.ACKDT = 0;
    SSP1CON2bits.ACKEN = 1;
}

static inline void I2C1_MasterSendNack(void)
{
    SSP1CON2bits.ACKDT = 1;
    SSP1CON2bits.ACKEN = 1;
}

static inline void I2C1_MasterClearBusCollision(void)
{
    PIR2bits.BCL1IF = 0;
}

static inline bool I2C1_MasterIsRxBufFull(void)
{
    return SSP1STATbits.BF;
}

static inline void I2C1_MasterEnableIrq(void)
{
    PIE1bits.SSP1IE = 1;
}

static inline bool I2C1_MasterIsIrqEnabled(void)
{
    return PIE1bits.SSP1IE;
}

static inline void I2C1_MasterDisableIrq(void)
{
    PIE1bits.SSP1IE = 0;
}

static inline void I2C1_MasterClearIrq(void)
{
    PIR1bits.SSP1IF = 0;
}

static inline void I2C1_MasterSetIrq(void)
{
    PIR1bits.SSP1IF = 1;
}

static inline void I2C1_MasterWaitForEvent(void)
{
    while(1)
    {
        if(PIR1bits.SSP1IF)
        {    
            break;
        }
    }
}
