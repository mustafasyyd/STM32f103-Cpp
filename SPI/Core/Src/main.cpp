#include "main.h"
#include "gpio.hpp"
#include "spi.hpp"
#include "spi.hpp"

#define FOSC 8000000
#define BAUD 9600
#define GP_OUT_PUSHPULL 3
#define FLOATING_INPUT_MODE 4

//system clock configuration.
void SystemClock_Config(void);

int main(void)
{
  SystemClock_Config();

  //SPI communication protocol
  RCC->APB2ENR |= ( 1<<AFIOEN
		  	  	  | 1<<SPI1EN
				  | 1<<IOPAEN );

  	  //PA5, A6 , A7 configuration.
  PortCofig spi_sck  (GPIOA, PORTA , PIN_5);
  PortCofig spi_miso (GPIOA, PORTA , PIN_6);
  PortCofig spi_mosi (GPIOA, PORTA , PIN_7);

  	  //SPI_1 configuration.
  SPI spi1 ( ( 1<<BIDIMODECRCEN )
		     |(1<<BIDIMODE)
		     |(1<<MSTR)
		     |(3<<BR)
		     |(1<<RXONLY)
		     |(1<<CRCNEXT)
		     |(1<<CRCEN)       );


  while (1)
  {

  }

}



/*******************************************************/
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

void Error_Handler(void)
{
    __disable_irq();
  while (1)
  {
  }

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
