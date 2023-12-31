#if !defined __GPIO__
#define 	 __GPIO__

class PORTCONFIG
{
	public:
	PORTCONFIG();
	~PORTCONFIG();
	PORTCONFIG (GPIO_TypeDef* gpio , PORTS PORT , PINS PIN);
	void write_pin(uint8_t logic);
	uint32_t read_pin();

	private:
	GPIO_TypeDef* gpio;
	PORTS port;
	PINS pin;
};

#endif 		/*__GPIO__*/
