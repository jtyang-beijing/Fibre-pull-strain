#include <Arduino.h>
#include <HX711_ADC.h>
#include <global_vars.h>
#include <load_sensor_operation.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#include <pin_map.h>
#endif
HX711_ADC LoadCell(HX711_dout, HX711_sck);
//LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address and the number of columns and rows

void init_load_cell()
{
  //lcd.begin();  // set up the LCD's number of columns and rows:  
  Serial.println("Starting...");

  LoadCell.begin();
  //LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
  #if defined(ESP8266)|| defined(ESP32)
  //EEPROM.begin(512); // uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from eeprom
  #endif
  EEPROM.get(CALVAL_EEPROM_ADDRESS, CALIBRATION_VALUE); // uncomment this if you want to fetch the calibration value from eeprom
  LoadCell.start(STABILIZING_TIME, _TARE);// clear tare every time start...
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(CALIBRATION_VALUE); // set calibration value (float)
    Serial.println("Startup is complete - " + String(CALIBRATION_VALUE));
  }

}

void readData()
{
  unsigned long t = 0;
  static boolean newDataReady = false;
  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;
  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + SERIAL_PRINT_INTERVAL) {
      float i = LoadCell.getData();
      //Serial.print("Load_cell output val: ");
      Serial.println("l:"+String(i));
      //LCD Print
      //lcd.clear(); // Clears the display 
      //lcd.setCursor(0,0);  // set the cursor to column 0, line 0
      //lcd.print("DIYEngineers.com");
      //lcd.setCursor(0,1);  // set the cursor to column 0, line 1
      //lcd.print("Weight(g): " + String(int(i)));
      newDataReady = false;
      delay(50);
      t = millis();
    }
  }
}

void calibrate() {
  tare(); // tare first...

  boolean _resume = false;
  float known_mass = 0;
  while (_resume == false) {  // wait until mass value input from UI
    LoadCell.update();
    if (Serial.available() > 0) {
      known_mass = Serial.parseFloat();
      if (known_mass != 0) {
        Serial.println("Known mass is: " + String(known_mass,2));
        _resume = true;
      }
    }
  }
  LoadCell.refreshDataSet(); //refresh the dataset to be sure that the known mass is measured correct
  float newCalibrationValue = LoadCell.getNewCalibration(known_mass); //get the new calibration value

  _resume = false;
  while (_resume == false) {
    if (Serial.available() > 0) {
      char inByte = Serial.read();
      if (inByte == 'y') {
        #if defined(ESP8266)|| defined(ESP32)
        EEPROM.begin(512);
        #endif
        EEPROM.put(CALVAL_EEPROM_ADDRESS, newCalibrationValue);
        #if defined(ESP8266)|| defined(ESP32)
        EEPROM.commit();
        #endif
        Serial.print("New Calibration Fator saved");
        _resume = true;
      }
      else if (inByte == 'n') {
        Serial.println("New Calibration Fator not saved");
        _resume = true;
      }
    }
  }
}

void changeSavedCalFactor() {
  float oldCalibrationValue = LoadCell.getCalFactor();
  boolean _resume = false;
  Serial.println(oldCalibrationValue); // report current calibration value
  float newCalibrationValue;
  while (_resume == false) { // wait until input new value from UI via Serial
    if (Serial.available() > 0) {
      newCalibrationValue = Serial.parseFloat();
      if (newCalibrationValue != 0) {
        LoadCell.setCalFactor(newCalibrationValue);
        _resume = true;
      }
    }
  }

  _resume = false;
  while (_resume == false) { // wait until get confirming from UI save new value to EEPROM or not.
    if (Serial.available() > 0) {
      char inByte = Serial.read();
      if (inByte == 'y') {
        #if defined(ESP8266)|| defined(ESP32)
          EEPROM.begin(512);
        #endif
          EEPROM.put(CALVAL_EEPROM_ADDRESS, newCalibrationValue);
        #if defined(ESP8266)|| defined(ESP32)
          EEPROM.commit();
        #endif
        Serial.println("New Value saved");
        _resume = true;
      }
      else if (inByte == 'n') {
        Serial.println("New Value not saved");
        _resume = true;
      }
    }
  }
  Serial.println("End change calibration value");
}

void tare()
{
  LoadCell.update();
  LoadCell.tareNoDelay(); 
}