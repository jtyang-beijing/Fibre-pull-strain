#ifndef VARIABELS_H
#define VARIABLES_H

#include <Arduino.h>  // need String Class 

extern unsigned long STABILIZING_TIME;
extern boolean _TARE;
extern float CALIBRATION_VALUE;
extern const int CALVAL_EEPROM_ADDRESS;
extern const int SERIAL_PRINT_INTERVAL;

// UI commands
extern byte RUN_CALIBRATON;
extern byte RUN_TARE;
extern byte SET_CAL_FACTOR;
// UI commands
#endif