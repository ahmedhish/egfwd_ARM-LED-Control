#include "..\Mcal\Inc\Dio.h"
#include "..\Mcal\Inc\GPT_interface.h"
volatile unsigned int T_ON=0;
volatile unsigned int T_OFF=0;
volatile unsigned int counter=0;

void LED_Blink(void)
{
	counter++;
	//Ton=5 & Toff=3
		#ifdef Testing
		Dio_FlipChannel(F,pin1);
		#else
		if(counter <= T_ON)
			Dio_WriteChannel(F,pin1,HIGH);
		else
			Dio_WriteChannel(F,pin1,LOW);
		
		
		if(counter == (T_ON + T_OFF))
			counter=0;
		#endif
}


int main(void)
{
	Dio_Init(F,pin1,output);//red
	Dio_Init(F,pin0,input);//sw1
	Dio_Init(F,pin4,input);//sw2
	GPT_Init();
	GPT_EnableNotification(T1);
	GPT_Notification_T1(LED_Blink);
	GPT_StartTimer(T1,16000000);
	
	while(1)
	{
		if(~Dio_ReadChannel(F,pin0))
		{
			if(~Dio_ReadChannel(F,pin4))
			{
				T_ON++;
				while(~Dio_ReadChannel(F,pin0));
			}
			else
			{
				T_OFF++;
				while(~Dio_ReadChannel(F,pin0));
			}
		}
	}
	
	return 0;
}
