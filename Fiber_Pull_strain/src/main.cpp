#include <Arduino.h>
#include <load_sensor_operation.h>
#include <serial_communication.h>


void setup() {
  Serial.begin(115200); delay(10);
  init_load_cell();
}
void loop() {
  monitorUI();
  readData();
}