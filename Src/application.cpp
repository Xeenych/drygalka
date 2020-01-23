#include "application.hpp"
#include "main.h"

Application::Application(Stm32f103c8t6_spi_master& spi): spi_master(spi) {}

uint8_t tx[32] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
				 0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
				 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
				 0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f};
uint8_t rx[32];
				 
void Application::Run() {
	
	while (true) {
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		for (volatile int i=0; i<100000;i++);
			
		spi_master.TransmitReceive(tx, rx, 32);
		for (int i=0;i<32;i++)
			if (tx[i]!=rx[i])
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		
		for (volatile int j=0; j<100000;j++);
	}
}