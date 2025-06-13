// traffic light
// Elegoo mega2560

int RED_LED = 13;
int YELLOW_LED = 12;
int GREEN_LED = 8;
int ON_DELAY = 5000;
int YELLOW_ON_DELAY = 2000;

bool firstTime = true;

// Setup
void setup(){
    Serial.begin(115200);
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
}

void loop(){
    // Signal start of pattern
    Serial.println(firstTime);

    if(firstTime){
      firstTime = startPattern();
    }

    

    // Red light
    digitalWrite(RED_LED, HIGH);
    delay(ON_DELAY);
    digitalWrite(RED_LED, LOW);

    // Yellow light
    digitalWrite(YELLOW_LED, HIGH);
    delay(YELLOW_ON_DELAY);
    digitalWrite(YELLOW_LED, LOW);

    // Green light
    digitalWrite(GREEN_LED, HIGH);
    delay(ON_DELAY);
    digitalWrite(GREEN_LED, LOW);

}

bool startPattern(){
    Serial.println("Start pattern started...");

    int blinkOnDelay = 1000;

    digitalWrite(RED_LED,HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(blinkOnDelay);
    
    digitalWrite(RED_LED,LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(blinkOnDelay);

    digitalWrite(RED_LED,HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(blinkOnDelay);
    
    digitalWrite(RED_LED,LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(blinkOnDelay);

    digitalWrite(RED_LED,HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(blinkOnDelay);
    
    digitalWrite(RED_LED,LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(blinkOnDelay);

    Serial.println("Start pattern ended...");

    return false;
}