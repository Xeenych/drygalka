#pragma once
#include "Stm32f103c8t6_spi_master.hpp"

class Application {
public:
	Application(Stm32f103c8t6_spi_master& spi);
	void Run();
private:
	Stm32f103c8t6_spi_master& spi_master;
};