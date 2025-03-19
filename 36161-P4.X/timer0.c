#include <xc.h>
#include "timer0.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
	/* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:1 */
	T0CON1 = 0x70;
    
    /* TMR0 output on pin RF3 */
    RF3PPS = 0x39;
    
	/* Load TMR0 with initial value FC17(hex) = 64535(dec) */
    /* (1/64MHz ) x 1000 x 1 = 1 ms */
	TMR0H = 0xFC;
	TMR0L = 0x17;

}


void TIMER0_Start(void)
{
    /* Timer0 enabled; 16-bit */
	T0CON0 |= 0x80;
    
}