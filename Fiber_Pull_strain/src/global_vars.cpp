#include <Arduino.h>
#include <global_vars.h>
//load sensor related
unsigned long STABILIZING_TIME = 2000;
boolean _TARE = true;
float CALIBRATION_VALUE = 901.67;
const int CALVAL_EEPROM_ADDRESS = 0;
const int SERIAL_PRINT_INTERVAL = 50;
// motor related
float MOTOR_SPEED = 20000;
float ACCELORATION = 25000;
// UI commands
byte RUN_CALIBRATON = 'c';
byte RUN_TARE = 't';
byte SET_CAL_FACTOR = 'r';
byte DRIVE_MOTOR = 'm';
byte RESET_MOTOR_POSITION = 'o';