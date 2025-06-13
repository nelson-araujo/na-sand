
// DHT sensors

#include <DHT_U.h>
#include <DHT.h>

#define DHT_PIN 13
#define DHT_TYPE DHT11

float humidity;
float tempC;
float tempF;
float tempK;

DHT dht(DHT_PIN, DHT_TYPE);

void setup(){
    Serial.begin(115200);
    dht.begin();
    // pinMode(DHTPIN, INPUT)
}


void loop(){
    humidity = dht.readHumidity();
    tempC = dht.readTemperature();
    tempF = (tempC*(9.0/5.0)) + 32; // F = [C*(9/5)] +32
    tempK = tempC + 273.0; // K = C + 273

    Serial.print("Sensor Readings - ");
        Serial.print("C: ");
        Serial.print(tempC);
        Serial.print(" | F: ");
        Serial.print(tempF);
        Serial.print(" | K: ");
        Serial.print(tempK);
        Serial.print(" | Huminity: ");
        Serial.println(humidity);
    
    delay(1000);

}