/*
  ReadDistanceSerial
  Triggers the measurement on pin 5, reads the result from A0 (can be any other pins) and writes it to the serial monitor.

  This example code is in the public domain.
 */

#include <SR04_Ultrasonic.h>

SR04_Ultrasonic sr04(5, A0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double distance = sr04.measureDistance();
  Serial.println(distance);
  delay(500);
}
