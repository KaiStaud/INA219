/*
 * INA219.cpp
 *
 *  Created on: Jun 2, 2021
 *      Author: Kai Staud
 */

#include <stdint.h>
#include "stm32g4xx_hal.h"

namespace ADC {
namespace ShuntAmplifier{


enum BusVoltage
{
	Vb_16V,
	Vb_32V
};


enum ShuntVoltage
{
	Vs_40mV,
	Vs_80mV,
	Vs_160mV,
	Vs_320mV,
};

enum AdcResolution
{
	Res_9Bit,
	Res_10Bit,
	Res_11Bit,
	Res_12Bit,
};

enum SamplingMode
{
	PowerDown,
	Vs_triggered,
	Vb_triggered,
	VsVb_triggered,
	ADC_Off,
	Vs_continous,
	Vb_contious,
	VsVb_continous
};

class INA219 {

public:
	INA219();
	~INA219();
	INA219(uint8_t addr, I2C_HandleTypeDef i2c_port);

	// Set ADC Resolution and Voltage Range
	void Configure(BusVoltage vb, ShuntVoltage vs, AdcResolution vs_res,AdcResolution vb_res);

	// Set Sampling Mode ( triggered,continous, VBus, VShunt)
	void SetMode(SamplingMode md);

	// Reset ADC to default settings
	void Reset();

	// Calibrate ADC
	void Calibrate(uint16_t cal,double AmpPerLSB);

	// Read Output Data
	signed int ReadCurrent();
	uint16_t ReadBusVoltage();
	double ReadCalibratedCurrent();
	float ReadPower();

private:
	HAL_StatusTypeDef WriteRegister(uint8_t reg, uint16_t data);
	HAL_StatusTypeDef ReadRegister(uint8_t reg, uint8_t *pData);
	uint16_t configRegister;
	ShuntVoltage vshunt;
	uint8_t address;
	double ampPerLSB;
	I2C_HandleTypeDef hi2c;
};
 } /* namespace ShuntAmplifier */

} /* namespace ADC */
