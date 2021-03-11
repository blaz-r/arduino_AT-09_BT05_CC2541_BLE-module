#include <SoftwareSerial.h>

// pins can be changed, but do mind you need to connect 
// RXD pin on module to assigned TX pin on arduino, and TXD on module to RX on arduino
SoftwareSerial Serial1(3, 4); // RX->3  TX->4

void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {
  // reads what comes from the module
  if(Serial1.available())
  {
    byte a=Serial1.read();
    Serial.write(a);
  }
  // sends data from serial to module
  if(Serial.available())
  {
    byte a=Serial.read();
    Serial.write(a); // writes current command to serial, for feedback
    Serial1.write(a);
  }
}
