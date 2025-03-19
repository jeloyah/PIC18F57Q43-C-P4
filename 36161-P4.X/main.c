
#include <xc.h>
#include "clock.h" 
#include "gpio.h"
#include "timer0.h"


void main(void) {
    
    /* Peripheral and System Initialization*/
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* PortA initialization */
    PortA_Initialize();

    /* AGREGAR LA CONFIGURACI�N DE LOS OTROS PUERTOS*/

    
    /* TIMER0 Initialization */
    TIMER0_Initialize();
    
    
    /* Infinite loop */
    while(1)
    {
     
      /* AGREGAR LA L�GICA PRINCIPAL DEL PROGRAMA */
        
        
        
    } // while
    
    return;
} // main
