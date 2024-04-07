#ifndef VARIABELS_H
#define VARIABLES_H

#include <Arduino.h>  // need String Class 

extern unsigned long stabilizingtime;
extern boolean _tare;
extern float calibrationValue;
extern const int calVal_eepromAdress;
extern const int serialPrintInterval;

// UI commands
extern byte RUN_CALIBRATON;
extern byte RUN_TARE;
extern byte SET_CAL_FACTOR;
// UI commands
#endif