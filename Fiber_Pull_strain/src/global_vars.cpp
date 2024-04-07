#include <Arduino.h>
#include <global_vars.h>

unsigned long stabilizingtime = 2000;
boolean _tare = true;
float calibrationValue = 696.0;
const int calVal_eepromAdress = 0;
const int serialPrintInterval = 50;
// UI commands
byte RUN_CALIBRATON = 'r';
byte RUN_TARE = 't';
byte SET_CAL_FACTOR = 'c';