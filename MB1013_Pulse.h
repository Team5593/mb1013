#pragma once

#include "MB1013_Base.h"
#include <DigitalInput.h>
#include <DigitalOutput.h>
#include <time.h>

class MB1301_Pulse: public MB1013_Base
{
public:
	MB1301_Pulse(DigitalInput *input, DigitalOutput *output);
	~MB1301_Pulse();

	double Get(); // returns distance in meters

private:
	DigitalInput *input;
	DigitalOutput *output;

	double timeout = 0.2;

	// helper functions
	double getTime();
};