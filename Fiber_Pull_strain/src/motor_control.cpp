#include <motor_control.h>
#include <pin_map.h>
#include <Arduino.h>
#include <global_vars.h>

AccelStepper myStepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
void initMotor()
{
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(FAR_END, INPUT_PULLUP); //limit sensor
    pinMode(CLOSE_END, INPUT_PULLUP);
    myStepper.setAcceleration(ACCELORATION);
    myStepper.setMaxSpeed(MOTOR_SPEED);
}
void driveMotor(long destination)
{
    myStepper.moveTo(destination);
    while(myStepper.currentPosition() != destination 
    && digitalRead(FAR_END)
    && digitalRead(CLOSE_END)) myStepper.run();
}

void resetMotorPosition()
{
    myStepper.setCurrentPosition(0);
}