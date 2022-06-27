#include <xc.h>

#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#define ENKODER PORTBbits.RB8

volatile int licznik = 0;

void Interrupt_Init(void){
    IEC0bits.INT0IE = 0;                // disable interrupt
    INTCONbits.INT0EP = 0;              // interrupt triggers on negative edge = 0, rise = 1
    IPC0bits.INT0IP = 1;                // EXT0 priority 1
    IPC0bits.INT0IS = 0;                // EXT0 sub-priority 0
    IFS0bits.INT0IF = 0;                // clear the interrupt flag
    
    IEC0bits.INT0IE = 1;                // enable interrupt on INT0
    INTCONbits.MVEC = 1;                // Enable the multi vector interrupts
}

void __attribute__((vector(_EXTERNAL_0_VECTOR), interrupt(ipl3soft))) External_InterruptF0(){
    
    IFS0bits.INT0IF = 0;  // clear interrupt flag 
    
    if(ENKODER == 0){
        licznik ++;
    }else{
        licznik --;
    }
    printf("%d\t", licznik);
}

#endif /*__INTERRUPTS_H*/