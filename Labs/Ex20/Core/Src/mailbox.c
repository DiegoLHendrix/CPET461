/*
 * mailbox.c
 *
 *  Created on: Apr 2, 2024
 *      Author: Diego
 */

#include "FreeRTOS.h"
#include "semphr.h"
#include "cmsis_os.h"
#include "mailbox.h"

osMessageQId MessageQueHandle;

SemaphoreHandle_t MailBoxMutex;
SemaphoreHandle_t SemaSync1;
SemaphoreHandle_t SemaSync2;

void InitMailBox(void)
{
	/**
	 * Create the queue(s)
	 * definition and creation of MessageQeue
	 */
	osMessageQDef(MessageQue, 1, uint16_t);
	MessageQueHandle = osMessageCreate(osMessageQ(MessageQue), NULL);

	MailBoxMutex = xSemaphoreCreateMutex();
	xSemaphoreGive(MailBoxMutex);
	SemaSync1 = xSemaphoreCreateBinary();
	SemaSync2 = xSemaphoreCreateBinary();

	xSemaphoreTake(SemaSync1, 0);
	xSemaphoreTake(SemaSync2, 0);
}

void Post(int syncMessage)
{
	xSemaphoreGive(SemaSync2);
	xSemaphoreTake(SemaSync1, osWaitForever);
	xQueueSendToBack(MessageQueHandle, &syncMessage, 0);
}

int Pend(void)
{
	int data;
	xSemaphoreGive(SemaSync1);
	xSemaphoreTake(SemaSync2, osWaitForever);
	xQueueReceive(MessageQueHandle, &data, 1000);

	return data;
}

