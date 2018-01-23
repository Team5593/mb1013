#pragma once

#include <SensorBase.h>
#include <DigitalInput.h>
#include <DigitalOutput.h>
#include <Timer.h>

class MB1013_Pulse
{
public:
	MB1013_Pulse(DigitalInput *input, DigitalOutput *enable);
	~MB1013_Pulse();

	double Get(); // returns distance in meters

private:
	DigitalInput *input;
	DigitalOutput *enable;

	double timeout = 0.2;

	// helper functions
	double getTime();
};