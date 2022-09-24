#include "Inc/Dio.h"

void Dio_Init(Dio_PortType PortId,Dio_ChannelType ChannelId,Port_PinDirectionType dir)
{
	SYSCTL_RCGCGPIO_R |= 0x00000020;

  switch(PortId)
  {
    
  case A:
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    GPIO_PORTA_CR_R = 0xFF;
    
    if(dir==output)
      GPIO_PORTA_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTA_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTA_PUR_R,ChannelId);

    }
    GPIO_PORTA_DEN_R = 0xFF;
    break;
  case B:
    
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    GPIO_PORTB_CR_R = 0xFF;
    if(dir==output)
      GPIO_PORTB_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTB_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTB_PUR_R,ChannelId);
    }
    GPIO_PORTB_DEN_R = 0xFF;
    break;
  case C:
        
    GPIO_PORTC_LOCK_R = 0x4C4F434B;
    GPIO_PORTC_CR_R = 0xFF; 
    if(dir==output)
      GPIO_PORTC_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTC_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTC_PUR_R,ChannelId);
    } 
    GPIO_PORTC_DEN_R = 0xFF;
    break;
  case D:
        
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    GPIO_PORTD_CR_R = 0xFF;
    if(dir==output)
      GPIO_PORTD_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTD_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTD_PUR_R,ChannelId);
    }
    GPIO_PORTD_DEN_R = 0xFF;
    break;
  case E:
        
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    GPIO_PORTE_CR_R = 0x3F;
    if(dir==output)
      GPIO_PORTE_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTE_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTE_PUR_R,ChannelId);
    }
    GPIO_PORTE_DEN_R = 0x3F;
    break;
  case F:
        
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
    if(dir==output)
      GPIO_PORTF_DIR_R|=(1<<ChannelId);
    
    else if(dir==input)
    {
      CLEAR_BIT(GPIO_PORTF_DIR_R,ChannelId);
      SET_BIT(GPIO_PORTF_PUR_R,ChannelId);
    }
    GPIO_PORTF_DEN_R = 0x1F;
    break;
  }
}

Dio_LevelType Dio_ReadChannel(Dio_PortType PortId,Dio_ChannelType ChannelId)
{
	uint8 Bit;
  switch(PortId)
  {

  case A:
     Bit= GET_BIT(GPIO_PORTA_DATA_R,ChannelId); 
    break;
  case B:
     Bit= GET_BIT(GPIO_PORTB_DATA_R,ChannelId); 
    break;
  case C:
     Bit= GET_BIT(GPIO_PORTC_DATA_R,ChannelId); 
    break;
  case D:
     Bit= GET_BIT(GPIO_PORTD_DATA_R,ChannelId); 
    break;
  case E:
    Bit= GET_BIT(GPIO_PORTE_DATA_R,ChannelId); 
    break;
  case F:
    Bit= GET_BIT(GPIO_PORTF_DATA_R , ChannelId); 
    break;
  }
  if (Bit !=0)
    return HIGH ;
	else
		return LOW;
}

void Dio_WriteChannel(Dio_PortType PortId,Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	switch(PortId)
  {

  case A:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTA_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTA_DATA_R,ChannelId);
    break;
  case B:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTB_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTB_DATA_R,ChannelId);
    break;
  case C:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTC_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTC_DATA_R,ChannelId);
    break;
  case D:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTD_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTD_DATA_R,ChannelId);
    break;
  case E:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTE_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTE_DATA_R,ChannelId);
    break;
  case F:
		if (Level == HIGH)
      SET_BIT(GPIO_PORTF_DATA_R,ChannelId);
		else
			CLEAR_BIT(GPIO_PORTF_DATA_R,ChannelId);
    break;
  }
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	switch(PortId)
  {

  case A:
      return GPIO_PORTA_DATA_R&7;
    break;
  case B:
      return GPIO_PORTB_DATA_R&7;
    break;
  case C:
      return GPIO_PORTC_DATA_R&7;
    break;
  case D:
      return GPIO_PORTD_DATA_R&7;
    break;
  case E:
      return GPIO_PORTE_DATA_R&7;
    break;
  case F:
      return GPIO_PORTF_DATA_R&7;
    break;
  }
}
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
	switch(PortId)
  {

  case A:
      GPIO_PORTA_DATA_R=level;
    break;
  case B:
      GPIO_PORTB_DATA_R=level;
    break;
  case C:
      GPIO_PORTC_DATA_R=level;
    break;
  case D:
      GPIO_PORTD_DATA_R=level;
    break;
  case E:
      GPIO_PORTE_DATA_R=level;
    break;
  case F:
      GPIO_PORTF_DATA_R=level;
    break;
  }
}
void Dio_FlipChannel(Dio_PortType PortId,Dio_ChannelType ChannelId)
{
	switch(PortId)
  {

  case A:
      GPIO_PORTA_DATA_R^=(1<<ChannelId);
    break;
  case B:
      GPIO_PORTB_DATA_R^=(1<<ChannelId);
    break;
  case C:
      GPIO_PORTC_DATA_R^=(1<<ChannelId);
    break;
  case D:
      GPIO_PORTD_DATA_R^=(1<<ChannelId);
    break;
  case E:
      GPIO_PORTE_DATA_R^=(1<<ChannelId);
    break;
  case F:
      GPIO_PORTF_DATA_R^=(1<<ChannelId);
    break;
  }
}
