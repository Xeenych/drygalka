#pragma once
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_spi.h"

class Stm32f103c8t6_spi_master {
public:
	Stm32f103c8t6_spi_master(SPI_HandleTypeDef *handle, GPIO_TypeDef *NSS_Port, uint16_t NSS_Pin);
	void Transmit(uint8_t *pData, uint16_t Size);
	void TransmitReceive (uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
private:
	SPI_HandleTypeDef *hspi;
	GPIO_TypeDef *NSS_Port;
	const uint16_t NSS_Pin;
};