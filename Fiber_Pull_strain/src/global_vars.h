#ifndef VARIABELS_H
#define VARIABLES_H

#include <Arduino.h>  // need String Class 
//load sensor related
extern unsigned long STABILIZING_TIME;
extern boolean _TARE;
extern float CALIBRATION_VALUE;
extern const int CALVAL_EEPROM_ADDRESS;
extern const int SERIAL_PRINT_INTERVAL;
//motor related
extern float MOTOR_SPEED;
extern float ACCELORATION;
// UI commands
extern byte RUN_CALIBRATON;
extern byte RUN_TARE;
extern byte SET_CAL_FACTOR;
extern byte DRIVE_MOTOR;
extern byte RESET_MOTOR_POSITION;
// UI commands
#endif