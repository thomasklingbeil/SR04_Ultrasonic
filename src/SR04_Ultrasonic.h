#ifndef SR04_h
#define SR04_h

class SR04_Ultrasonic {
  public:
    // constructor
    SR04_Ultrasonic(int triggerPin, int echoPin);

    double measureDistance();

  private:
    void triggerDistanceMeasurement();

    int triggerPin;
    int echoPin;
};

#endif
