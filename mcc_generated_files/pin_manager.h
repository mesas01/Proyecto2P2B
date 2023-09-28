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
        Device            :  PIC18F46K42
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

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set channel_ANA1 aliases
#define channel_ANA1_TRIS                 TRISAbits.TRISA1
#define channel_ANA1_LAT                  LATAbits.LATA1
#define channel_ANA1_PORT                 PORTAbits.RA1
#define channel_ANA1_WPU                  WPUAbits.WPUA1
#define channel_ANA1_OD                   ODCONAbits.ODCA1
#define channel_ANA1_ANS                  ANSELAbits.ANSELA1
#define channel_ANA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_ANA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_ANA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_ANA1_GetValue()           PORTAbits.RA1
#define channel_ANA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_ANA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_ANA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_ANA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_ANA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define channel_ANA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define channel_ANA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define channel_ANA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set DAC aliases
#define DAC_TRIS                 TRISBbits.TRISB4
#define DAC_LAT                  LATBbits.LATB4
#define DAC_PORT                 PORTBbits.RB4
#define DAC_WPU                  WPUBbits.WPUB4
#define DAC_OD                   ODCONBbits.ODCB4
#define DAC_ANS                  ANSELBbits.ANSELB4
#define DAC_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define DAC_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define DAC_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define DAC_GetValue()           PORTBbits.RB4
#define DAC_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define DAC_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define DAC_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define DAC_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define DAC_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define DAC_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define DAC_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define DAC_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

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

// get/set LED_0 aliases
#define LED_0_TRIS                 TRISDbits.TRISD0
#define LED_0_LAT                  LATDbits.LATD0
#define LED_0_PORT                 PORTDbits.RD0
#define LED_0_WPU                  WPUDbits.WPUD0
#define LED_0_OD                   ODCONDbits.ODCD0
#define LED_0_ANS                  ANSELDbits.ANSELD0
#define LED_0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED_0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED_0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED_0_GetValue()           PORTDbits.RD0
#define LED_0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED_0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LED_0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LED_0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LED_0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LED_0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LED_0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define LED_0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISDbits.TRISD1
#define LED_1_LAT                  LATDbits.LATD1
#define LED_1_PORT                 PORTDbits.RD1
#define LED_1_WPU                  WPUDbits.WPUD1
#define LED_1_OD                   ODCONDbits.ODCD1
#define LED_1_ANS                  ANSELDbits.ANSELD1
#define LED_1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED_1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED_1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED_1_GetValue()           PORTDbits.RD1
#define LED_1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED_1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED_1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED_1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LED_1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LED_1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LED_1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set SPI aliases
#define SPI_TRIS                 TRISEbits.TRISE0
#define SPI_LAT                  LATEbits.LATE0
#define SPI_PORT                 PORTEbits.RE0
#define SPI_WPU                  WPUEbits.WPUE0
#define SPI_OD                   ODCONEbits.ODCE0
#define SPI_ANS                  ANSELEbits.ANSELE0
#define SPI_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define SPI_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define SPI_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define SPI_GetValue()           PORTEbits.RE0
#define SPI_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define SPI_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define SPI_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define SPI_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define SPI_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define SPI_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define SPI_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define SPI_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

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