#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <AccelStepper.h>
//#include <elapsedMillis.h>

void initMotor();
void driveMotor(long destination);
void resetMotorPosition();
#endif