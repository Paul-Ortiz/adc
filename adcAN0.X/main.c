/*
 * File:   main.c
 * Author: Paul
 *
 * Created on January 21, 2024, 12:02 AM
 */


#include <xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000 // 4Mhz

#define led PORTDbits.RD0

void main(void) {
    ADON = 1;
    // FOSC/64
    ADCS2 = 1;
    ADCS1 = 1;
    ADCS0 = 0;
    
    // AN0 Analog selected port
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
    
    ADFM = 1; //Right justified
    // VREF+ = VDD      VREF- = GND
    PCFG3 = 0;
    PCFG2 = 0;
    PCFG1 = 0;
    PCFG0 = 0;
    
    TRISD0 = 0;
    
    while (1){
        
        GO_DONE = 1;
        
        while(ADCON0bits.GO_DONE){
            __delay_ms(1);
        }
        
        int val = ADRESH * 256 + ADRESL;            //Convert from 10 bits to integer
        
        if(val > 512 ){
            led = 1;
        }else{
            led = 0;
        }
        
        }
            
    return;
}
