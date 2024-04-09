#include <Arduino.h>
#include <global_vars.h>

unsigned long STABILIZING_TIME = 2000;
boolean _TARE = true;
float CALIBRATION_VALUE = 901.67;
const int CALVAL_EEPROM_ADDRESS = 0;
const int SERIAL_PRINT_INTERVAL = 50;
// UI commands
byte RUN_CALIBRATON = 'c';
byte RUN_TARE = 't';
byte SET_CAL_FACTOR = 'r';