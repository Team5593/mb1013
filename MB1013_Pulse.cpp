#include "MB1013_Pulse.h"

MB1013_Pulse::MB1013_Pulse(DigitalInput *input): input(input), output(output)
{
	output->Set(false);
}

double MB1013_Pulse::Get()
{
	output->Set(true); // enable sensor

	while (input->Get() == false);

	double start_time = getTime();

	while (input->Get() == true);

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