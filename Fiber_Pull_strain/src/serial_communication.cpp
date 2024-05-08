#include <load_sensor_operation.h>
#include <global_vars.h>
#include <motor_control.h>
/*  monitorUI will run in main loop, followed by readData.
    When there is serial data in, monitorUI will hold main
    loop and make justment for what to do:
    'c' = RUN_CALIBRATON, means run calibration.
        calibration action will run in 3 steps:
        1 - run tare first. without any warnning message.
            make sure that the load sensor should be 
            placed on flat surface without any load on it.
        2 - wait know mass value input. put mass first onto the 
            load sensor, and then input its real weight value through
            serial.the new mass value will be immediately applied to
            load cell. a new calibratrion factor will be updated.
        3 - wait to confirm save the new calibration factor or 
            not. 'y' will store in to EEPROM, 'n' will cause
            new value ignored.
    'r' = SET_CAL_FACTOR, means change calibration factor manually.
        manually modify calibration factor take 3 steps:
        1 - readout stored value and output to serial port.
        2 - wait input new value from serial
        3 - wait confirming store or not. 'y' will store in to EEPROM, 
            'n' will cause new value ignored.
    't' = RUN_TARE, means run tare. 

*/
void monitorUI()
{
    if (Serial.available() > 0) 
    {
      char inByte = Serial.read();
      if (inByte == RUN_CALIBRATON) {calibrate();}
      else if (inByte == SET_CAL_FACTOR) {changeSavedCalFactor();}
      else if (inByte == RUN_TARE) {tare();}
      else if (inByte == RESET_MOTOR_POSITION){resetMotorPosition();}
      else if (inByte == DRIVE_MOTOR)
      {
        String destination = Serial.readString();
        char charBuffer[20];
        destination.toCharArray(charBuffer,20);
        char *dest;
        long Destination = strtol(charBuffer,&dest,10);

        driveMotor(Destination);
      };
    }
}