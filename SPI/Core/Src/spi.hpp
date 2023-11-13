#if !defined __SPI__
#define 	 __SPI__

class SPI
{
	public:
	SPI();
	~SPI();
	SPI(uint32_t cr1);

	private:
	uint32_t cr1;
};


#endif		/*__SPI__*/
