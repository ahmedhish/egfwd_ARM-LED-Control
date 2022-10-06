/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Inc/STD_types.h"
#include "Inc/bitwise_operations.h"

extern volatile unsigned int T_ON;
extern volatile unsigned int T_OFF;
extern volatile unsigned int counter;
#include "Inc/GPT_Interface.h"
#include "../Config/GPT_Configure.h"
#include "Inc/tm4c123gh6pm.h"
#include "Inc/GPT_Private.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define 	NULL  			((void*)0)

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
void (*TimerCallBack[6]) (void) = {	NULL , NULL , NULL ,NULL ,
										NULL , NULL  };



/**********************************************************************************************************************
*  NOTIFICATION CALL BACK
*********************************************************************************************************************/
										
void GPT_Notification_T0 (void (*Timer0CallBack) (void) )
{
	TimerCallBack[0] = Timer0CallBack ;
}

void 	GPT_Notification_T1 (void (*Timer1CallBack) (void) )
{
	TimerCallBack[1] = Timer1CallBack ;
}
void 	GPT_Notification_T2 (void (*Timer2CallBack) (void) )
{
	TimerCallBack[2] = Timer2CallBack ;
}
void 	GPT_Notification_T3 (void (*Timer3CallBack) (void) )
{
	TimerCallBack[3] = Timer3CallBack ;
}
void 	GPT_Notification_T4 (void (*Timer4CallBack) (void) )
{
	TimerCallBack[4] = Timer4CallBack ;
}
void 	GPT_Notification_T5 (void (*Timer5CallBack) (void) )
{
	TimerCallBack[5] = Timer5CallBack ;
}



/**********************************************************************************************************************
 *  Interrupt Service Routines (ISR)
 *********************************************************************************************************************/
void TIMER0A_Handler(void)
{
	if( TimerCallBack[0] != NULL )
	{
		/*execute passed function*/
		TimerCallBack[0]();
		GPTMICR(T0).B.TATOCINT = 1;
	}
}
void TIMER1A_Handler(void)
{
	if( TimerCallBack[1] != NULL )
	{
		TimerCallBack[1]();
		GPTMICR(T1).B.TATOCINT = 1;
	}
}
void TIMER2A_Handler(void)
{
	if( TimerCallBack[2] != NULL )
	{
		TimerCallBack[2]();
	}
}
void TIMER3A_Handler(void)
{
	if( TimerCallBack[3] != NULL )
	{
		TimerCallBack[3]();
	}
}
void TIMER4A_Handler(void)
{
	if( TimerCallBack[4] != NULL )
	{
		TimerCallBack[4]();
	}
}
void TIMER5A_Handler(void)
{
	if( TimerCallBack[5] != NULL )
	{
		TimerCallBack[5]();
	}
}

void GPT_Init(void)
{

	u8 i =0;
	SYSCTL_RCGCTIMER_R	 = 0xff;
	SYSCTL_RCGCWTIMER_R = 0xff;
	NVIC_EN0_R |= (1<<21); 
	for( i=0 ; i<11 ; i++)
	{	
		GPTMCTL(GPT_ConfigArray[i].ChannelId).B.TAEN 	= DISABLE;
		GPTMCFG(GPT_ConfigArray[i].ChannelId).B.GPTMCFG = 0x00000000;
		GPTMTAMR(GPT_ConfigArray[i].ChannelId).B.TAMR 	= GPT_ConfigArray[i].ChannelMode;
		GPTMTAMR(GPT_ConfigArray[i].ChannelId).B.TACDIR	= COUNT_DOWN;
		GPTMTAPR(GPT_ConfigArray[i].ChannelId).R 		= GPT_ConfigArray[i].ChannelTickFreq;
		GPTMTAILR(GPT_ConfigArray[i].ChannelId).R 		= GPT_ConfigArray[i].ChannelTickValueMax;
		GPTMIMR(GPT_ConfigArray[i].ChannelId).R			= 0x00000000;
	}
}

void	GPT_DisableNotification(Gpt_ChannelType Channel)
{
	GPTMIMR(Channel).R	= 0x00000000;
}
void	GPT_EnableNotification(Gpt_ChannelType Channel)
{
	GPTMIMR(Channel).B.TATOIM = ENABLE;
	GPTMICR(Channel).B.TATOCINT = ENABLE;
	
}

void GPT_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Counts)
{
	
	GPTMTAILR(Channel).R = Counts;
	GPTMCTL(Channel).B.TAEN 	= ENABLE;
	while( (GPTMRIS(Channel).B.TATORIS) != 1);
}

void GPT_StopTimer( Gpt_ChannelType Channel)
{
	GPTMCTL(Channel).B.TAEN 	= DISABLE;
}

Gpt_ValueType GPT_GetTimeElapsed( Gpt_ChannelType Channel)
{
	return ((GPTMTAILR(Channel).R)-(GPTMTAV(Channel)));
}
Gpt_ValueType GPT_GetTimeRemaining( Gpt_ChannelType Channel)
{
	return GPTMTAV(Channel);
}

u32 GPT_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer )
{
	
	u32 ret=0;
	if(PredefTimer == GPT_PREDEF_TIEMR_1uS_16BIT )
	{
		ret = (GPTMTAV(PredefTimer)>> 4) & 0x0000ffff;
	}
	else if(PredefTimer == GPT_PREDEF_TIEMR_1uS_24BIT)
	{
		ret = (GPTMTAV(PredefTimer) >> 4) & 0x00ffffff;
	}
	else if(PredefTimer == GPT_PREDEF_TIEMR_1uS_32BIT )
	{
		ret = (GPTMTAV(PredefTimer) >> 4);
	}
	else if(PredefTimer == GPT_PREDEF_TIEMR_125uS_32BIT )
	{
		ret = GPTMTAV(PredefTimer) >> 7;
	}
	return ret;
}

void GPT_nSecondsDelay(u32 seconds , Gpt_ChannelType Tx)
{
	u32 sec_count=0;
	GPTMCTL(Tx).B.TAEN = ENABLE;
	while(sec_count!=seconds)
	{
		while( (GPTMRIS(Tx).B.TATORIS) != 1);
		GPTMICR(Tx).B.TATOCINT = 1;
		sec_count++; 
	}
	GPTMCTL(Tx).B.TAEN = DISABLE;
}




/**********************************************************************************************************************
 *  END OF FILE: GPT_Program.c
 *********************************************************************************************************************/
