#pragma once

#include <DigitalInput.h>
#include <DigitalOutput.h>
#include <Timer.h>

class MB1013_Pulse
{
public:
	MB1013_Pulse(DigitalInput *input, DigitalOutput *output);
	~MB1013_Pulse();

	double Get(); // returns distance in meters

private:
	DigitalInput *input;
	DigitalOutput *output;

	double timeout = 0.2;

	// helper functions
	double getTime();
};