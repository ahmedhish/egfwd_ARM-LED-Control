#include "Inc/Timer.h"

void Time1A_Delay(void)
{
SYSCTL_RCGCTIMER_R |= (1<<1);
TIMER1_CTL_R = 0; 
TIMER1_CFG_R = 0x4; 
TIMER1_TAMR_R= 0x02; 
TIMER1_TAPR_R = 250-1; 
TIMER1_TAILR_R = 64000-1 ; 
TIMER1_ICR_R = 0x1;         
TIMER1_IMR_R |=1; 
TIMER1_CTL_R |= 0x01;        
NVIC_EN0_R |= (1<<21); 
}