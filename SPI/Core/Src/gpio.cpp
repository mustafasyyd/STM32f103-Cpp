#include "gpio.hpp"


typedef enum PORTS
{
	PORTA = 2,
	PORTB	 ,
	PORTC 	 ,
	PORTD 	 ,
	PORTE 	 ,
	PORTF 	 ,
	PORTG

}PORTS;


typedef enum PINS
{
	PIN_0 = 0,
	PIN_1    ,
	PIN_2    ,
	PIN_3  	 ,
	PIN_4  	 ,
	PIN_5  	 ,
	PIN_6  	 ,
	PIN_7  	 ,
	PIN_8  	 ,
	PIN_9  	 ,
	PIN_10 	 ,
	PIN_11 	 ,
	PIN_12 	 ,
	PIN_13 	 ,
	PIN_14 	 ,
	PIN_15 	 ,

}PINS;

PORTCONFIG::PORTCONFIG( GPIO_TypeDef* gpio , PORTS PORT , PINS PIN)
	: gpio(gpio) , pin(PIN) , port(PORT)
	{
		RCC->APB2ENR |= 1<< port;
		if(pin<8 && pin >=0)
			gpio->CRL = GP_OUT_PUSHPULL << 4*pin;

		else if( pin>=8 && pin < 15 )
			gpio->CRH = GP_OUT_PUSHPULL << 4*(pin%8);
	}

void PORTCONFIG::write_pin(uint8_t logic)
{
	gpio->ODR |= logic << pin;
}

uint32_t PORTCONFIG::read_pin()
{
	unint32_t p = gpio->IDR;
	return p &= (1<<pin);
}



