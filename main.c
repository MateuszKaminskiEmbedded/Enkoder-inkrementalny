#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "DeviceConfig.h"
#include "delay.h"
#include "UART.h"
#include "interrupts.h"
#include "PinConfig.h"

void main(){
    PinConfig();                    // Ustaw uzywane piny I/O
	Set_MaxSpeed_Mode();            // Ustaw parametry konfiguracyje mikrokontrolera
    Interrupt_Init();               // Inicjalizacja przerwania zewnetrznego external_0
	UART_Init();                    // Inicjalizacja UART 5
    
	while (1){
        
    }
}