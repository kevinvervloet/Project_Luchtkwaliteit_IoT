/*---Author information-------------------------------------------------------------
   email: kevin.vervloet@student.kdg.be
   email: sven.devisscher@student.kdg.be
   email: johannes.coolen@student.kdg.be
   email: raf.vermeylen@student.kdg.be
   email: ruben.vandermeiren@student.kdg.be
   Author: Air Quality Boys
   Version: 1.1.1

*/

//---Libraries----------------------------------------------------------------------
#include "Adafruit_CCS811.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

//---variabelen----------------------------------------------------------------------
const int IntervalGas = 10000;    // dit is de interval tijd
unsigned long previousTimeGas = 0;          // Vorige tijd
#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11 
#define TFT_CS         3    //kies pinnen voor display
#define TFT_RST        16
#define TFT_DC         1
#define LED            15
DHT dht = DHT(DHTPIN, DHTTYPE);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//---Setup--------------------------------------------------------------------------
Adafruit_CCS811 ccs;
void setup() {  
  pinMode(LED, OUTPUT);
  dht.begin();
  Serial.begin(115200);
  delay(1);                                 // omdat de watchdog anders reset
  
  /*if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }*/
  tft.initR(INITR_BLACKTAB);                //initialiseer display
  tft.fillScreen(ST77XX_BLACK);             //maak het scherm zwart
  tft.setRotation(1);                       // draai het scherm
  tft.setCursor(0, 0);                      // zet de cursor in het begin
  tft.setTextColor(ST77XX_YELLOW);          //zet de tekstkleur op geel
  tft.setTextSize(2);                     //grootte tekst op 2
  tft.println("G.R.E.T.A in the house");  //print tekst
  // Wait for the sensor to be ready
  while(!ccs.available());
   
}
//---Loop--------------------------------------------------------------------------
void loop() {
  
   unsigned long currentTimeGas = millis(); // huidige tijd van millis die constant veranderd
    if (currentTimeGas - previousTimeGas >= IntervalGas) {
      float t = dht.readTemperature();      //lees temperatuur en vochtigheid
      float h = dht.readHumidity();
      //if (ccs.available()) {                //lees de co2 waarden uit
        //if (!ccs.readData()) {            
          tft.fillScreen(ST77XX_BLACK);             //maak het scherm zwart
      tft.setCursor(0, 0);                      // zet de cursor in het begin
      tft.setTextColor(ST77XX_YELLOW);          //zet de tekstkleur op geel
      tft.setTextSize(2);                     //grootte tekst op 1
     // tft.println("CO2 = " + String(ccs.geteCO2())+" ppm"); //print tekst
      tft.println("T = " + String(t)+ " C");
      tft.println("h = " + String(h)+ " %");
          previousTimeGas = currentTimeGas;     // Update de waarde van millis
      /* }
      }*/
     
    if (ccs.geteCO2() >= 900) {
      digitalWrite(LED, HIGH);
    }
    else {
      digitalWrite(LED, LOW);
    }
    delay(1);
  }
  
  delay(1);
}
//--------------------------------------------------------------------------------
//Gemaakt door de groep Luchtkwaliteit
//Graduaat IoT
//Klas 1.1
