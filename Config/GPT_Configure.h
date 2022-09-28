/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Configure.h
 *       Module:  General Purpose Tiemrs
 *
 *  Description:  This header file contains GPT configurations
 *  
 *********************************************************************************************************************/
#ifndef		GPT_CONFIGURE_H
#define 	GPT_CONFIGURE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Mcal/Inc/GPT_Interface.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define		GPT_PREDEF_TIEMR_1uS_16BIT_EN			ENABLE
#define		GPT_PREDEF_TIEMR_1uS_24BIT_EN			DISABLE
#define		GPT_PREDEF_TIEMR_1uS_32BIT_EN			DISABLE
#define		GPT_PREDEF_TIEMR_125uS_32BIT_EN			DISABLE

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
const Gpt_ConfigType	GPT_ConfigArray [] =
{
	/*ChannelId;ChannelTickFreq ;ChannelTickValueMax ;ChannelMode;*/
	{T0,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },
	{T1,	GPT_16MHz	, 16		, PERIODIC_MODE },
	{T2,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{T3,	GPT_16MHz	, 16		, PERIODIC_MODE },
	{T4,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{T5,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	
	{WT0,	GPT_8MHz	, 8000 		, PERIODIC_MODE },
	{WT1,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },
	{WT2,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{WT3,	GPT_16MHz	, 16 		, PERIODIC_MODE },
	{WT4,	GPT_16MHz	, 16000000 	, PERIODIC_MODE },

};


#endif		 /* GPT_CONFIGURE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Configure.h
 *********************************************************************************************************************/




