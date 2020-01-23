#include <assert.h>
#include "Stm32f103c8t6_spi_master.hpp"


Stm32f103c8t6_spi_master::Stm32f103c8t6_spi_master(SPI_HandleTypeDef *handle,
												   GPIO_TypeDef *NSS_Port, 
												   uint16_t NSS_Pin) :
												hspi(handle),
												NSS_Port(NSS_Port),
												NSS_Pin(NSS_Pin) {
	__HAL_SPI_ENABLE(hspi);
}

void Stm32f103c8t6_spi_master::Transmit(uint8_t *pData, uint16_t Size) {
	HAL_GPIO_WritePin(NSS_Port, NSS_Pin, GPIO_PIN_RESET);
	HAL_StatusTypeDef ret = HAL_SPI_Transmit(hspi, pData, Size, HAL_MAX_DELAY);
	assert(ret==HAL_OK);
	HAL_GPIO_WritePin(NSS_Port, NSS_Pin, GPIO_PIN_SET);

}