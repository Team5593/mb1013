#include "MB1013_UART.h"

MB1013_UART::MB1013_UART(DigitalOutput* enable, SerialPort::Port port) :
	enable(enable),
	serial(port)
{

}

double MB1013_UART::GetRangeInches() {
	return GetRaw();
}

double MB1013_UART::GetRangeMM() {
	return GetRaw() * 25.4;
}

unsigned int MB1013_UART::GetRaw() {
	enable->Set(true);

	unsigned int value = 0;
	int byte_count = serial.GetBytesReceived();

	char *buffer = new char[byte_count];
	serial.Read(buffer, byte_count);
	for (int i = byte_count; i > 1; --i) {
		value += (int)buffer[i] * pow(10,i);
	}
	serial.Flush();

	enable->Set(false);

	return value;
}