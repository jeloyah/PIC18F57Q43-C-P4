#include <xc.h>
#include "timer0.h"
#include "pps.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{
    /* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:1 */
	T0CON1 = 0x70;
    
    /* sequence for unlock PPS */
    PPS_unlock();
    
    /* TMR0 output on pin RF3 */
    RF3PPS = 0x39;
    
    /* sequence for lock PPS */
    PPS_lock();
    
  	/* Load TMR0 with initial value (hex) */
    /* tCLK1 x counts  x prescaler = TMR0 counting time */
    /* 1/64MHz * (65535-64535) * 1 = 15.625 us */
	TMR0H = 0xFC;
	TMR0L = 0x17;
}


void TIMER0_Start(void)
{
    /* Timer0 enabled; 16-bit */
	T0CON0 |= 0x80;
    
}