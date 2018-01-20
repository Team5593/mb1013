#include "MB1013_Pulse.h"

MB1013_Pulse::MB1013_Pulse(DigitalInput *input): input(input), output(output)
{
	output->Set(false);
}

double MB1013_Pulse::Get()
{
	bool timeout_start;

	output->Set(true); // enable sensor

	timeout_start = getTime();
	while (input->Get() == false)
	{
		if (getTime() - timeout_start) >= timeout
			return -1;
	}

	double start_time = getTime();

	timeout_start = getTime();
	while (input->Get() == false)
	{
		if (getTime() - timeout_start) >= timeout
			return -1;
	}

	double end_time = getTime();

	double reading = end_time - start_time;
	reading /= 1000000; // convert from seconds to uS
	reading *= 1000; // convert from mm to meters

	output->Set(false); // disable sensor

	return reading;
}

inline double MB1013_Pulse::getTime()
{
	return Timer::GetFPGATimestamp();
}