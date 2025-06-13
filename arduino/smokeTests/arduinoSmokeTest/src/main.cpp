#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // Initialize built in LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int DELAY = 5000;

  // Blink LED
  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);
}