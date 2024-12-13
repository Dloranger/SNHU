#include "TemperatureConvert.h"

int TemperatureConvert::fToC(int TempF) {
	return ((TempF - 32) * 5 / 9);   // convert temp from F to C 
}
