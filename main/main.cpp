#include "Arduino.h"

#include "PMW3901.h"

// Using digital pin 26 as chip select, but it can be any pin
PMW3901 flow(26);

void setup() {
  Serial.begin(115200);

  if (!flow.begin()) {
    Serial.println("Initialization of the flow sensor failed");
    while(1) { }
  }
}

int16_t deltaX,deltaY;
uint8_t squal;

void loop() {
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY, &squal);

  Serial.print("X: ");
  Serial.print(deltaX);
  Serial.print(", Y: ");
  Serial.print(deltaY);
  Serial.print(", SQUAL: ");
  Serial.print(squal);
  Serial.print("\n");

  delay(100);
}
