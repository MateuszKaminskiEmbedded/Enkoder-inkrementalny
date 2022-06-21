#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

#define LED LATEbits.LATE15
#define SWITCH PORTBbits.RB7
#define ENKODER PORTBbits.RB8

volatile int licznik = 0;

void Interrupt_External0Vector(void){
    __builtin_disable_interrupts();     // disable interrupts
     
    INTCONbits.INT0EP = 0;              // interrupt triggers on negative edge = 0, rise = 1
    IPC0bits.INT0IP = 1;                // EXT0 priority 1
    IPC0bits.INT0IS = 0;                // EXT0 sub-priority 0
    IFS0bits.INT0IF = 0;                // clear the interrupt flag
    
    IEC0bits.INT0IE = 1;                // enable interrupt on INT0
   
    INTCONbits.MVEC = 1;                //  Enable the multi vector interrupts

    __builtin_enable_interrupts();      // enable interrupts
    }

void __attribute__((vector(_EXTERNAL_0_VECTOR), interrupt(ipl3soft), nomips16)) external_interruptF0(){
    
    if(ENKODER == 0){
        licznik ++;
    }else{
        licznik --;
    }
    printf("Counter value is %d \n", licznik);
    
    IFS0bits.INT0IF = 0;  // clear interrupt flag     
}

#endif /*__INTERRUPTS_H*/