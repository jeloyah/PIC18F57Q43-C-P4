
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
    
    /* PortB initialization */
    PortB_Initialize();
    
    /* PortC initialization */
    PortC_Initialize();
    
    /* PortD initialization */
    PortD_Initialize();
    
    /* PortE initialization */
    PortE_Initialize();
    
    /* PortF initialization */
    PortF_Initialize();
   
    /* TIMER0 Initialization */
    TIMER0_Initialize();
    
    /* TIMER0 enabled, start counting */
    TIMER0_Start();
    
    /* Infinite loop */
    while(1)
    {
    
        /* Wait for TMR0IF = 1 */
        while ((PIR3 & 0x80) != 0x80)
                ;
        
        /* Clear TMR0IF bit */
        PIR3 &= 0x7F;
        
    } // while
    
    return;
} // main
