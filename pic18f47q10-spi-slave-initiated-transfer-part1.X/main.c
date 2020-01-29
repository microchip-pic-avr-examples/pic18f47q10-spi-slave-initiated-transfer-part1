/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC18F47Q10
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

//#define __DEBUG__    // Un-comment this Macro to print debugging messages

#define SPI_TX_BLOCK_SIZE              (16)
#define SPI_RX_BLOCK_SIZE              (SPI_TX_BLOCK_SIZE*2)

#define SPI_SLAVE_SELECT()             SS_SetLow()
#define SPI_SLAVE_RELEASE()            SS_SetHigh()
#define SLAVE_REQ_PIN_VALUE()          SREQ_GetValue() 

#define SLAVE_SYNC_DELAY               (100) // delay count in mS
#define SLAVE_SYNC_DELAY_ms(mS)        __delay_ms(mS) //custom name for delay in milliseconds

volatile uint8_t slaveDataRequestStart = 0; // slave request interrupt variable
volatile uint8_t slaveDataRequestEnd = 0;   // slave request interrupt variable
volatile uint8_t txBlock[SPI_TX_BLOCK_SIZE]="I_AM_MASTER"; // Transmitter buffer for SPI transmission
volatile uint8_t rxBlock[SPI_RX_BLOCK_SIZE] = {0};      // Receiver buffer for SPI transmission
uint8_t exchangeByteCount = 0;                          // counter for exchanged bytes

void IOCBF4_UserInterruptHandler(void);


/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("\n\nSPI_Master: System Started \r\n");
    IOCBF4_SetInterruptHandler(IOCBF4_UserInterruptHandler);// register User ISR for IOC on RB4
    printf("SPI_Master: Registered User interrupt Handler for SlaveInterrupt \r\n");
    SPI_SLAVE_RELEASE(); // Initially release SPI Slave device
#ifdef  __DEBUG__
    printf("SPI_Master: S_INT Pin Value: %d \r\n",SLAVE_REQ_PIN_VALUE());
    printf("SPI_Master: Reset(Release) Select Slave PIN, PIN Value: %d  \r\n",SS_GetValue());
#endif
    while (1)
    {
        // Add your application code
        if(slaveDataRequestStart == 1)
        {
            //reset all parameters
            slaveDataRequestStart = 0;
            slaveDataRequestEnd = 0;
            spiMaster[MASTER0].spiClose();
            SPI_SLAVE_RELEASE();
            LED0_Toggle(); 
            
            printf("\r\nSPI_Master: Received Request from Slave \r\n");
                
#ifdef  __DEBUG__  
            printf("SPI_Master: Closing SPI whether it is opened or not... \r\n");
            printf("SPI_Master: Reset(Release) Select Slave PIN, PIN Value: %d  \r\n",SS_GetValue());
            printf("SPI_Master: S_INT Pin Value: %d \r\n",SLAVE_REQ_PIN_VALUE());
#endif
            if(SLAVE_REQ_PIN_VALUE() == HIGH)   // Slave request is present 
            {
                if (spiMaster[MASTER0].spiOpen())
                {   
                    printf("\rSPI_Master: SPI Open \r\n");
                    printf("\rSPI_Master: Slave selected \r\n");
                    SPI_SLAVE_SELECT();      
#ifdef  __DEBUG__
                    printf("SPI_Master: SS Pin Value: %d \r\n",SS_GetValue());
                    printf("SPI_Master: Slave Sync Delay \r\n");
                    printf("SPI_Master: byteCount: %d \r\n",exchangeByteCount);
                    printf("SPI_Master: rxBlock: %s \r\n",rxBlock);
#endif
                    SLAVE_SYNC_DELAY_ms(SLAVE_SYNC_DELAY);    // Time to slave for setting up SPI
                    printf("\rSPI_Master: Starting Data Exchange\r\n");
                    
                    // Exchange data as long as slave request is present and data present in master TX array 
                    while((HIGH == SLAVE_REQ_PIN_VALUE())&& (exchangeByteCount < SPI_TX_BLOCK_SIZE))
                    {
                        rxBlock[exchangeByteCount] = spiMaster[MASTER0].exchangeByte(txBlock[exchangeByteCount]);
                        exchangeByteCount++;
                    }   
                    
                    printf("SPI_Master: Data exchange completed \r\n");
                    SPI_SLAVE_RELEASE();
                    printf("\rSPI_Master: Slave Released \r\n");
#ifdef  __DEBUG__
                    printf("SPI_Master: Release SPI Slave  \r\n");
                    printf("SPI_Master: SS Pin Value: %d \r\n",SS_GetValue());
#endif
                    printf("SPI_Master: Sent Data            : %s \r\n",txBlock);
                    printf("SPI_Master: Received Data        : %s \r\n",rxBlock);
                    printf("SPI_Master: No of Bytes Exchanged: %d \r\n",exchangeByteCount);
                    exchangeByteCount = 0;
                    rxBlock[exchangeByteCount] = 0x00;
                }
                else
                {
                    spiMaster[MASTER0].spiClose();
                    printf("SPI_Master: Deselect SPI Slave  \r\n");
                    
                }
            }
            else
            {
                spiMaster[MASTER0].spiClose();
                printf("SPI_Master: Deselect SPI Slave  \r\n");
            }
            
        }
        if(slaveDataRequestEnd == 1)
        {
#ifdef  __DEBUG__  
            printf("SPI_Master: S_INT Pin Value: %d \r\n",SLAVE_REQ_PIN_VALUE());
#endif
            slaveDataRequestEnd = 0;
            spiMaster[MASTER0].spiClose();
            printf("SPI_Master: SPI Closed \r\n\r\n");  
        }
    }
}

/**
  User interrupt handler for IOCBF4 (SW0 press)
*/
void IOCBF4_UserInterruptHandler(void)
{
    // add your IOCBF4 interrupt custom code
    // or set custom function using IOCBF4_SetInterruptHandler()
    if (HIGH == SLAVE_REQ_PIN_VALUE())
    {
        slaveDataRequestStart = 1;
    } 
    else if(LOW == SLAVE_REQ_PIN_VALUE())
    {
        slaveDataRequestEnd = 1;
    }
}
/**
 End of File
*/