/*---Author information-------------------------------------------------------------
 * email: kevin.vervloet@student.kdg.be
 * email: sven.devisscher@student.kdg.be
 * email:johannes.coolen@hotmail.com
 * Author: Air Quality Boys
 * Version: 1.0.0
 * 
 */

//---Libraries----------------------------------------------------------------------
#include "Adafruit_CCS811.h"   
#include <Adafruit_Sensor.h>
#include <DHT.h>    
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
Adafruit_CCS811 ccs;

//---variabelen----------------------------------------------------------------------
const unsigned long IntervalGas = 10000;    // dit is de interval tijd 
unsigned long previousTimeGas = 0;          // Vorige tijd
#define DHTPIN 12
#define DHTTYPE DHT11   // DHT 11 
#define TFT_CS         4    //kies pinnen voor display
#define TFT_RST        16                                            
#define TFT_DC         5
DHT dht = DHT(DHTPIN, DHTTYPE);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//---Setup--------------------------------------------------------------------------
void setup() {
 dht.begin();
tft.initR(INITR_BLACKTAB);                //initialiseer display
tft.fillScreen(ST77XX_BLACK);             //maak het scherm zwart
tft.setRotation(1);                       // draai het scherm
tft.setCursor(0, 0);                      // zet de cursor in het begin
tft.setTextColor(ST77XX_YELLOW);          //zet de tekstkleur op geel
  tft.setTextSize(2);                     //grootte tekst op 2
  tft.println("G.R.E.T.A in the house");  //print tekst
  
  if(!ccs.begin()){
    
    while(1);
  }

  
  while(!ccs.available());      // wacht tot de sensor beschikbaar is -> ga dan naar de loop
}

//---Loop--------------------------------------------------------------------------
void loop() {
  unsigned long currentTimeGas = millis(); // huidige tijd van millis die constant veranderd

  if(currentTimeGas - previousTimeGas >= IntervalGas) {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
    if(ccs.available()){
      if(!ccs.readData()){
        
        Serial.print(ccs.geteCO2());
        
        Serial.println(ccs.getTVOC());
        previousTimeGas = currentTimeGas;     // Update de waarde van millis
      }
      
    }
    tft.fillScreen(ST77XX_BLACK);             //maak het scherm zwart
tft.setCursor(0, 0);                      // zet de cursor in het begin
tft.setTextColor(ST77XX_YELLOW);          //zet de tekstkleur op geel
  tft.setTextSize(2);                     //grootte tekst op 2
  tft.println("CO2 = "+ccs.geteCO2());  //print tekst
  tft.println("TVCO = "+ccs.getTVOC());
  tft.println("T = "+String(t));
  tft.println("h = "+String(h));
  }
 
}

//--------------------------------------------------------------------------------
//Gemaakt door de groep Luchtkwaliteit
//Graduaat IoT
//Klas 1.1
