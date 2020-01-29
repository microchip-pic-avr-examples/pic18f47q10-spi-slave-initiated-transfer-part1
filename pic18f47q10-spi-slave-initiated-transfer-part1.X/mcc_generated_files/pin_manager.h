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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

// get/set SS aliases
#define SS_TRIS                 TRISBbits.TRISB3
#define SS_LAT                  LATBbits.LATB3
#define SS_PORT                 PORTBbits.RB3
#define SS_WPU                  WPUBbits.WPUB3
#define SS_OD                   ODCONBbits.ODCB3
#define SS_ANS                  ANSELBbits.ANSELB3
#define SS_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SS_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SS_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SS_GetValue()           PORTBbits.RB3
#define SS_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SS_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SS_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SS_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SS_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SS_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SS_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SS_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SREQ aliases
#define SREQ_TRIS                 TRISBbits.TRISB4
#define SREQ_LAT                  LATBbits.LATB4
#define SREQ_PORT                 PORTBbits.RB4
#define SREQ_WPU                  WPUBbits.WPUB4
#define SREQ_OD                   ODCONBbits.ODCB4
#define SREQ_ANS                  ANSELBbits.ANSELB4
#define SREQ_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SREQ_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SREQ_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SREQ_GetValue()           PORTBbits.RB4
#define SREQ_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SREQ_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SREQ_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SREQ_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SREQ_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SREQ_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SREQ_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SREQ_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISEbits.TRISE0
#define LED0_LAT                  LATEbits.LATE0
#define LED0_PORT                 PORTEbits.RE0
#define LED0_WPU                  WPUEbits.WPUE0
#define LED0_OD                   ODCONEbits.ODCE0
#define LED0_ANS                  ANSELEbits.ANSELE0
#define LED0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED0_GetValue()           PORTEbits.RE0
#define LED0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED0_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/