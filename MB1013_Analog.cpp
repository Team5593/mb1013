#include "MB1013_Analog.h"

MB1013_Analog::MB1013_Analog(AnalogInput *input, DigitalOutput *enable):
	input(input),
	enable(enable)
{
	SetEnabled(false);
}

double MB1013_Analog::Get()
{
	if isEnabled == false
		SetEnabled(true)

	// Todo: math to make this value meaningful and not just raw
	auto value = (input.Get() / 1023) * 5;

	if isEnabled == false
		SetEnabled(false)

	return value;
}

inline void MB1013_Analog::SetEnabled(bool state)
{
	enable->Set(state);
	isEnabled = state;
}