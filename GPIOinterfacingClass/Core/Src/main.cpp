#include "main.h"

#define GP_OUT_PUSHPULL 3
#define FLOATING_INPUT_MODE 4

typedef enum
{
	PORTA = 2,
	PORTB	 ,
	PORTC 	 ,
	PORTD 	 ,
	PORTE 	 ,
	PORTF 	 ,
	PORTG

}PORTS;


typedef enum
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

class PortCofig
{
	public:
	PortCofig( GPIO_TypeDef* gpio , PORTS PORT , PINS PIN)
		: gpio(gpio) , pin(PIN) , port(PORT)
	{
		RCC->APB2ENR |= 1<< port;
		if(pin<8 && pin >=0)
		{
			gpio->CRL = GP_OUT_PUSHPULL << 4*pin;
		}
		else if( pin>=8 && pin < 15 )
		{
			gpio->CRH = GP_OUT_PUSHPULL << 4*(pin%8);
		}
		void Write_Pin(uint8_t logic)
		{
			gpio->ODR |= logic << pin;
		}

//		void Write_Pin()
//		{
//			return gpio->IDR = pin;
//		}

	}

	private:
	GPIO_TypeDef* gpio
	PORTS port;
	PINS pin;
};

void SystemClock_Config(void);

int main(void)
{
  SystemClock_Config();

  PortCofig pin_1(GPIOA ,PORTA , PIN_1);

  while (1)
  {
	  GPIOA->ODR = 1<<PIN_3;
	  for (int i=0; i<1000000000000 ; i++);
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
