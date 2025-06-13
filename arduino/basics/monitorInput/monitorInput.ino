// Monitor input
// Arduino micro

int PIN = 1;

void setup(){
    Serial.begin(115200);

    pinMode(PIN, INPUT);
}

void loop(){
    int pinReadOut = analogRead(PIN);

    Serial.println(pinReadOut);
}