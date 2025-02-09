/*
 * PoolObject.c
 *
 *  Created on: Mar 20, 2024
 *      Author: diego
 */
#include "FreeRTOS.h"
#include "semphr.h"
#include "PoolObject.h"

/*Definition of data pool using a structure*/
typedef struct
{
	int GreenTaskFlashRate;
	int RedTaskFlashRate;
} FlashingRate;

/*Initialization of data pool variables and assigning default values*/
FlashingRate FlashingDataPool = {10, 1};

/*Declaration of FreeRTOS Semaphore*/
SemaphoreHandle_t CriticalResourceSemaphore;

void InitSemaphores(void)
{
	/*Create and Give (i.e. RELEASE) a Semaphore*/
	CriticalResourceSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(CriticalResourceSemaphore);
}

void SetGreenFlashRate(int x)
{
	xSemaphoreTake(CriticalResourceSemaphore, portMAX_DELAY);
	FlashingDataPool.GreenTaskFlashRate = x;
	xSemaphoreGive(CriticalResourceSemaphore);
}

int GetGreenFlashRate(void)
{
	return FlashingDataPool.GreenTaskFlashRate;
}

void SetRedFlashRate(int x)
{
	xSemaphoreTake(CriticalResourceSemaphore, portMAX_DELAY);
	FlashingDataPool.RedTaskFlashRate = x;
	xSemaphoreGive(CriticalResourceSemaphore);
}

int GetRedFlashRate(void)
{
	return FlashingDataPool.RedTaskFlashRate;
}

