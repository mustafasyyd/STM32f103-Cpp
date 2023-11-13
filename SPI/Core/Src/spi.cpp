#include "spi.hpp"

typedef enum SPI_CR1
{
	CPHA	 = 0  ,
	CPOL	 = 1  ,
	MSTR	 = 2  ,
	BR 	     = 3  ,
	SPE  	 = 6  ,
	LBFIRST  = 7  ,
	RXONLY 	 = 10 ,
	CRCNEXT  = 12 ,
	CRCEN 	 = 13 ,
	BIDIMODE = 15

}SPI_CR1;

SPI::SPI(uint32_t cr1)
	: cr1(cr1)
	{
		SPI1->CR1 |= cr1;
	}
