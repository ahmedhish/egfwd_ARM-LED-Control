#include "..\Mcal\Inc\Dio.h"
#include "..\Mcal\Inc\Timer.h"
unsigned int T_ON=0;
unsigned int T_OFF=0;
unsigned int counter=0;

int main(void)
{
	Dio_Init(F,pin1,output);//red
	Dio_Init(F,pin0,input);//sw1
	Dio_Init(F,pin4,input);//sw2
	Time1A_Delay();
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

void TIMER1A_Handler (void)
{ 
	counter++;
	//Ton=5 & Toff=3
	if(TIMER1_MIS_R & 0x1)
	{
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
	TIMER1_ICR_R=1;
}
