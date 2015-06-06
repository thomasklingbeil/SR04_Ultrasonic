#include "Arduino.h"
#include "SR04_Ultrasonic.h"

SR04_Ultrasonic::SR04_Ultrasonic(int triggerPin, int echoPin) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
  pinMode(this->triggerPin, OUTPUT);
  pinMode(this->echoPin, INPUT);
}

double SR04_Ultrasonic::measureDistance() {
  // This function returns the distance in cm

  double distance;
  unsigned long duration;

  this->triggerDistanceMeasurement();
  duration = pulseIn(this->echoPin, HIGH);
  //distance = (duration/2.0) * 29.154 ;

  /* sound travels at 343m/s (at 20°C in air) = 34.3cm/ms = 0.0343cm/µs.
     as the way needs to be traveled twice:

                 duration                                     |            µs      cm
     distance =  --------- * 0.0343cm = duration * 0.01715    |    cm  =  ----- * ----
                     2                                        |             2      µs
  */

  distance = duration * 0.01715;

  if (distance >= 300 || distance <= 0){
    return -1;
  }

  return distance;
}

void SR04_Ultrasonic::triggerDistanceMeasurement() {
  digitalWrite(this->triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->triggerPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(this->triggerPin, LOW);
}
