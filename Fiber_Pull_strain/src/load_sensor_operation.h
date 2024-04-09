#ifndef LOAD_SENSOR_OPERATION_H
#define LOAD_SENSOR_OPERATION_H
#endif
#include <HX711_ADC.h>
void init_load_cell();
void calibrate();
void changeSavedCalFactor();
void readData();
void tare();