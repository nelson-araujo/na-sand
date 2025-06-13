// Blinking LEDs
// Elegoo mega2560

int BLUE_LED = 13;
int DELAY = 1000;

// Setup function
void setup(){
    pinMode(BLUE_LED, OUTPUT);   
}

// Loop function
void loop(){
    digitalWrite(BLUE_LED, HIGH);
    delay(DELAY);
    digitalWrite(BLUE_LED, LOW);
    delay(DELAY);
}