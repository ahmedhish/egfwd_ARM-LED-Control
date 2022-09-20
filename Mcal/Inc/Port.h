#ifndef PORT__H_
#define PORT__H_


typedef enum {
	input,
	output
}Port_PinDirectionType;

typedef enum{
	PULL_UP,
	PULL_DOWN,
	OPEN_DRAIN,
	NA
}Port_PinInternalAttachType;

typedef enum{
	C2mA=2,
	C4mA=4,
	C8mA=8,
	NoC
}Port_PinOutputCurrentType;

typedef struct{
	Port_PinDirectionType Dir;
	Port_PinInternalAttachType attach;
	Port_PinOutputCurrentType Current;
}Port_ConfigType;




void Port_Init(const Port_ConfigType* ConfigPtr);
#endif
