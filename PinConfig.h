#ifndef __PINCONFIG_H
#define __PINCONFIG_H

void PinConfig(void){
    // Ustaw porty jako cyfrowe
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELE = 0;
    ANSELG = 0;
    
    // UART 5
	U5RXR = 0b1100; // RF0 = U5RX
	RPE15R = 0b01011; // RC9 = U5TX
	TRISFbits.TRISF0 = 1; // Make RF0 an input
    
    // External interrupts
    TRISEbits.TRISE15 = 0;  // set PINB14 as output
    TRISBbits.TRISB7  = 1;  // set PINB7 as input
    TRISBbits.TRISB8  = 1;  // set PINB8 as input
}

#endif /*__PINCONFIG_H*/