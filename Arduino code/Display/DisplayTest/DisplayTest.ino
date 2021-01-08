/*---Author information-------------------------------------------------------------
 * email:johannes.coolen@hotmail.com
 * Author: Johannes Coolen
 * Version: V1.0.0
 * Status: done
 */
 
//---Libraries----------------------------------------------------------------------
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

//---Variabelen----------------------------------------------------------------------
  #define TFT_CS         4    //kies pinnen voor display
  #define TFT_RST        16                                            
  #define TFT_DC         5
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//---Setup--------------------------------------------------------------------------
void setup() {
tft.initR(INITR_BLACKTAB);                //initialiseer display
tft.fillScreen(ST77XX_BLACK);             //maak het scherm zwart
tft.setRotation(1);                       // draai het scherm
tft.setCursor(0, 0);                      // zet de cursor in het begin
tft.setTextColor(ST77XX_YELLOW);          //zet de tekstkleur op geel
  tft.setTextSize(2);                     //grootte tekst op 2
  tft.println("G.R.E.T.A in the house");  //print tekst
}

//---Loop---------------------------------------------------------------------------
void loop() {
 
}

//----------------------------------------------------------------------------------
//Gemaakt door de groep Luchtkwaliteit
//Graduaat IoT
//Klas 1.1
