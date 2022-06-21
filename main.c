#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "DeviceConfig.h"
#include "delay.h"
#include "UART.h"
#include "interrupts.h"
#include "PinConfig.h"

void main(){
    // Ustaw u?ywane piny
    PinConfig();
    // Ustaw parametry konfiguracyje mikrokontrolera
	Set_MaxSpeed_Mode();
    // Inicjalizacja przerwania zewnetrznego external_0
    Interrupt_External0Vector();
    // Inicjalizacja UART 5
	UART_Init();
    
	while (1){
        
    }
}