/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Interface.h
 *       Module:  General Purpose Timers
 *
 *  Description:  This header file contains functions prototypes and essintial data types and macros
 *  
 *********************************************************************************************************************/
#ifndef		GPT_INTERFACE_H
#define 	GPT_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define 	ENABLE			1
#define 	DISABLE			0


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	T0=0,
	T1,
 	T2,
 	T3,
 	T4,
	T5,
	WT0,
	WT1,
	WT2=0xC,
	WT3,
	WT4,
	WT5
}Gpt_ChannelType;

typedef u32 Gpt_ValueType;

typedef enum 
{
	ONESHOT_MODE=1,
	PERIODIC_MODE
}Gpt_ModeType;

typedef enum
{
	Sec,
	mS,
	uS
}Gpt_UnitTime;
typedef enum 
{
	GPT_16MHz=0,
	GPT_8MHz=1,
	GPT_4MHz=3
}Gpt_TickFreq;


typedef enum 
{
	GPT_PREDEF_TIEMR_1uS_16BIT,
	GPT_PREDEF_TIEMR_1uS_24BIT,
	GPT_PREDEF_TIEMR_1uS_32BIT,
	GPT_PREDEF_TIEMR_125uS_32BIT
}Gpt_PredefTimerType;

typedef enum 
{
	COUNT_DOWN=0,
	COUNT_UP,
}Gpt_CountDir;

typedef struct
{
	Gpt_ChannelType ChannelId;
	Gpt_ValueType 	ChannelTickFreq ;
	Gpt_ValueType 	ChannelTickValueMax ;
	Gpt_ModeType	ChannelMode;
	//Notification
}Gpt_ConfigType;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void	GPT_Init( void );
void	GPT_DisableNotification(Gpt_ChannelType Channel);
void	GPT_EnableNotification(Gpt_ChannelType Channel);
void 	GPT_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Counts);
void 	GPT_StopTimer( Gpt_ChannelType Channel);
Gpt_ValueType GPT_GetTimeElapsed( Gpt_ChannelType Channel);
Gpt_ValueType GPT_GetTimeRemaining( Gpt_ChannelType Channel);
u32 GPT_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer );
void 	GPT_nSecondsDelay(u32 time , Gpt_ChannelType Tx);
void 	GPT_Notification_T0 (void (*Timer0CallBack) (void) );
void 	GPT_Notification_T1 (void (*Timer1CallBack) (void) );
void 	GPT_Notification_T2 (void (*Timer2CallBack) (void) );
void 	GPT_Notification_T3 (void (*Timer3CallBack) (void) );
void 	GPT_Notification_T4 (void (*Timer4CallBack) (void) );
void 	GPT_Notification_T5 (void (*Timer5CallBack) (void) );
void 	GPT_Notification_WT0 (void (*WideTimer0CallBack) (void) );
void 	GPT_Notification_WT1 (void (*WideTimer1CallBack) (void) );
void 	GPT_Notification_WT2 (void (*WideTimer2CallBack) (void) );
void 	GPT_Notification_WT3 (void (*WideTimer3CallBack) (void) );
void 	GPT_Notification_WT4 (void (*WideTimer4CallBack) (void) );
void	GPT_Notification_WT5 (void (*WideTimer5CallBack) (void) );





#endif		/* GPT_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Interface.h
 *********************************************************************************************************************/

