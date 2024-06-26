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
extern int MOTOR_SPEED;
extern int ACCELORATION;
extern long CURRENT_POSITION;
extern long DESTINATION;
// UI commands
extern byte RUN_CALIBRATON;
extern byte RUN_TARE;
extern byte SET_CAL_FACTOR;
extern byte DRIVE_MOTOR;
extern byte RESET_MOTOR_POSITION;
extern byte HAND_SHAKE;
// UI commands
#endif