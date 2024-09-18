/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void display7SEG(int num){


	    uint8_t segments[10] = {
	        0b00111111, // 0
	        0b00000110, // 1
	        0b01011011, // 2
	        0b01001111, // 3
	        0b01100110, // 4
	        0b01101101, // 5
	        0b01111101, // 6
	        0b00000111, // 7
	        0b01111111, // 8
	        0b01101111  // 9
	    };


	    uint8_t segment_value = segments[num];


	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, (segment_value & 0x01) ? RESET : SET);  // Segment A
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, (segment_value & 0x02) ? RESET : SET);  // Segment B
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (segment_value & 0x04) ? RESET : SET);  // Segment C
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (segment_value & 0x08) ? RESET : SET);  // Segment D
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (segment_value & 0x10) ? RESET : SET);  // Segment E
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (segment_value & 0x20) ? RESET : SET);  // Segment F
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (segment_value & 0x40) ? RESET : SET);  // Segment G
	}
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int red = 1;
  int green = 0;
  int yellow = 2;
  int led_color_1 = 0;
  int led_color_2 = 1;
  int counter_1 = 0;
  int counter_2 = 0;
  while (1)
  {


	  	  	  if(led_color_1 == green && counter_1 == 3){
	  	  		  led_color_1 = 2;
	  	  		  counter_1 = 0;
	  	  	  }
	  	  	  if(led_color_1 == red && counter_1 == 5){
	  	  		  led_color_1 = 0;
	  	  		  counter_1 = 0;
	  	  	  }
	  	  	  if(led_color_1 == yellow && counter_1 == 2){
	  	  		  led_color_1 = 1;
	  	  		  counter_1 = 0;
	  	  	  }
	  	  	  if(led_color_2 == green && counter_2 == 3){
	  	  		  led_color_2 = 2;
	  	  		  counter_2 = 0;
	  	  	  }
	  	  	  if(led_color_2 == red && counter_2 == 5){
	  	  		  led_color_2 = 0;
	  	  		  counter_2 = 0;
	  	  	  }
	  	  	  if(led_color_2 == yellow && counter_2 == 2){
	  	  		  led_color_2 = 1;
	  	  		  counter_2 = 0;
	  	  	  }
	  	  	  if(led_color_1 == green){
	  	  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);	//  led green on
	  	  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);   //  led green on
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	  	  	  }
		  	  else if(led_color_1 == yellow){
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET); 	// led yellow on
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);	// led yellow on
		  	  }
		  	  else if(led_color_1 == red){
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET); //led red on
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET); // led red on
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		  	  }

			  if(led_color_2 == red){
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);   // led red on
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);  //led red on
		  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
			  }
		  	  else if(led_color_2 == yellow){
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);	// led yellow on
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET); // led yellow on
		  	  }
		  	  else if(led_color_2 == green){
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET); // led green on
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET); // led green on
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			  	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		  	  }
		  	  counter_1++;
		  	  counter_2++;
		  	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
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

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_11_Pin
                          |LED_12_Pin|LED_4_Pin|LED_5_Pin|LED_6_Pin
                          |LED_7_Pin|LED_8_Pin|LED_9_Pin|LED_10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_11_Pin
                           LED_12_Pin LED_4_Pin LED_5_Pin LED_6_Pin
                           LED_7_Pin LED_8_Pin LED_9_Pin LED_10_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_11_Pin
                          |LED_12_Pin|LED_4_Pin|LED_5_Pin|LED_6_Pin
                          |LED_7_Pin|LED_8_Pin|LED_9_Pin|LED_10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_0_Pin SEG_1_Pin SEG_2_Pin SEG_3_Pin
                           SEG_4_Pin SEG_5_Pin SEG_6_Pin */
  GPIO_InitStruct.Pin = SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
                          |SEG_4_Pin|SEG_5_Pin|SEG_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
