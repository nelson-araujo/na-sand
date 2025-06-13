// LED pulsades using an analog pin
// Arduino micro

// Globals
int GREEN_LED = 11;
int LED_LUMEN_DELTA = 5;
int LED_DELAY = 25;

int ledLumen = 0;
bool increaseLumen = true;


// Setup
void setup(){
    Serial.begin(115200);

    pinMode(GREEN_LED, OUTPUT);
}

// Loop
void loop(){
    Serial.println((String)increaseLumen + " - " + (String)ledLumen);
    // Serial.println(ledLumen);
    delay(LED_DELAY);

    analogWrite(GREEN_LED, ledLumen);

    if(increaseLumen){
        if(ledLumen >= 255){
            increaseLumen = false;
        } else {
            ledLumen = ledLumen + LED_LUMEN_DELTA;
        }
    } else {
        if(ledLumen <= 10){
            increaseLumen = true;
        } else{
            ledLumen = ledLumen - LED_LUMEN_DELTA;
        }
    }
}