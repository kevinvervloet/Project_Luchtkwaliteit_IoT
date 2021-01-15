//variabelen temperatuursensor
#include <Adafruit_Sensor.h>
#include <DHT.h>
// DHT pin instellen
#define DHTPIN 12

// DHT type instellen
#define DHTTYPE DHT11   // DHT 11 

DHT dht = DHT(DHTPIN, DHTTYPE);

//vairabelen millis die ik gebruik voor de temperatuursensor
const int meetTijd = 30000;
unsigned long currentTime = 0;
unsigned long previousTime = 0;


void setup() {
 //setup temperatuursensor
 Serial.begin(9600);
 dht.begin();

}

void loop() {
  // de code voor de temperatuursensor
  currentTime = millis();
  if (currentTime - previousTime > meetTijd) {


    printVochtigheid() ;
    printTemperatuur() ;
    previousTime = currentTime;
  }
}

void printTemperatuur() {
  float t = dht.readTemperature();
  Serial.print(F("% Temperatuur: "));
  Serial.print(t);
  Serial.print(F("°C |  "));
  Serial.print('\n');
}
void printVochtigheid() {
  float h = dht.readHumidity();
  Serial.print(F("Vochtigheid: "));
  Serial.print(h);
}
