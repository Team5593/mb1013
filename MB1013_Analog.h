#pragma once

#include <AnalogInput.h>
#include <DigitalOutput.h>

class MB1013_Analog
{
public:
	MB1013_Analog(AnalogInput *input, DigitalOutput *enable);
	~MB1013_Analog();
	
	double Get();

	void SetEnabled(bool state);
	
private:
	AnalogInput *input;
	DigitalOutput *enable;

	bool isEnabled = false;
};