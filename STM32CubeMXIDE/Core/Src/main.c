/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "stdlib.h"
#include "string.h"
#include <stdio.h>
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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
TaskHandle_t HPThandler;
void HPT_TASK(void *pvParameter);

TaskHandle_t MPThandler;
void MPT_TASK(void *pvParameter);

TaskHandle_t LPThandler;
void LPT_TASK(void *pvParameter);

TaskHandle_t VLPThandler;
void VLPT_TASK(void *pvParameter);

SemaphoreHandle_t CountingSem;

//Resource Related
int resource[4] = {111,222,333,444};
int indx = 0;

//uart related
uint8_t rx_data = 0;

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
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
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  HAL_UART_Receive_IT(&huart2,&rx_data,1);

  CountingSem = xSemaphoreCreateCounting(8,0);
  if(CountingSem == NULL)
  {
	  printf("Unable to create Semaphore\r\n\r\n");
  }
  else
  {
	  printf("Counting Semaphore created successfully\r\n\r\n");
  }

  xTaskCreate(HPT_TASK,"HPT",300,NULL,3,&HPThandler);
  xTaskCreate(MPT_TASK,"MPT",300,NULL,2,&MPThandler);
  xTaskCreate(LPT_TASK,"LPT",300,NULL,1,&LPThandler);
  xTaskCreate(VLPT_TASK,"VLPT",300,NULL,0,&VLPThandler);

  vTaskStartScheduler();


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

int __io_putchar(int data)
{
    HAL_UART_Transmit(&huart2,(uint8_t*)&data,1,0xFFFF);
    return data;
}

void HPT_TASK(void *parameters)
{
	int semcount = 0;

	//Give three semaphores at beginning of task
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);
	xSemaphoreGive(CountingSem);

	while(1)
	{
		semcount = uxSemaphoreGetCount(CountingSem);
		printf("Entered HPT Task\r\n About to ACQUIRE the Semaphore\n\rTokens available are: %d \n\r\n\r", semcount);

		xSemaphoreTake(CountingSem,portMAX_DELAY);

		printf("Leaving HPT Task \r\n Data ACCESSED is:: %d\r\n Not Releasing the semaphore \r\n\r\n\r\n",resource[indx]);

		indx++;

		if(indx > ((sizeof(resource)/sizeof(int))-1))
		{
			indx = 0;
		}

		vTaskDelay(3000);
		//vTaskDelete(NULL);
	}
}

void MPT_TASK(void *parameters)
{
	int semcount = 0;

	while(1)
	{
		semcount = uxSemaphoreGetCount(CountingSem);
		printf("Entered MPT Task\r\n About to ACQUIRE the Semaphore\n\rTokens available are: %d \n\r\n\r", semcount);

		xSemaphoreTake(CountingSem,portMAX_DELAY);

		printf("Leaving MPT Task \r\n Data ACCESSED is:: %d\r\n Not Releasing the semaphore \r\n\r\n\r\n",resource[indx]);

		indx++;

		if(indx > ((sizeof(resource)/sizeof(int))-1))
		{
			indx = 0;
		}

		vTaskDelay(2000);
		//vTaskDelete(NULL);
	}
}

void LPT_TASK(void *parameters)
{
	int semcount = 0;

	while(1)
	{
		semcount = uxSemaphoreGetCount(CountingSem);
		printf("Entered LPT Task\r\n About to ACQUIRE the Semaphore\n\rTokens available are: %d \n\r\n\r", semcount);

		xSemaphoreTake(CountingSem,portMAX_DELAY);

		printf("Leaving LPT Task \r\n Data ACCESSED is:: %d\r\n Not Releasing the semaphore \r\n\r\n\r\n",resource[indx]);

		indx++;

		if(indx > ((sizeof(resource)/sizeof(int))-1))
		{
			indx = 0;
		}

		vTaskDelay(1000);
		//vTaskDelete(NULL);
	}
}

void VLPT_TASK(void *parameters)
{
	int semcount = 0;

	while(1)
	{
		semcount = uxSemaphoreGetCount(CountingSem);
		printf("Entered VLPT Task\r\n About to ACQUIRE the Semaphore\n\rTokens available are: %d \n\r\n\r", semcount);

		xSemaphoreTake(CountingSem,portMAX_DELAY);

		printf("Leaving VLPT Task \r\n Data ACCESSED is:: %d\r\n Not Releasing the semaphore \r\n\r\n\r\n",resource[indx]);

		indx++;

		if(indx > ((sizeof(resource)/sizeof(int))-1))
		{
			indx = 0;
		}

		vTaskDelay(500);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart2,&rx_data,1);

	if(rx_data == 'r')
	{
		//release semaphore

		BaseType_t xHigherPriorityTaskWoken;

		xSemaphoreGiveFromISR( CountingSem, &xHigherPriorityTaskWoken );
		xSemaphoreGiveFromISR( CountingSem, &xHigherPriorityTaskWoken );
		xSemaphoreGiveFromISR( CountingSem, &xHigherPriorityTaskWoken );

		portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
#ifdef USE_FULL_ASSERT
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
