#pragma once

#include <SensorBase.h>
#include <DigitalOutput.h>
#include <SerialPort.h>

class MB1013_UART
{
public:
	MB1013_UART(DigitalOutput* enable, SerialPort::Port port = SerialPort::Port::kOnboard);
	~MB1013_UART();

	double GetRangeInches();
	double GetRangeMM();

	bool IsEnabled();
	void SetEnabled(bool enable);

private:
	unsigned int GetRaw();

	DigitalOutput* enable;
	SerialPort serial;

	bool m_enabled = false;
};