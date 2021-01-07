/*
 * dit is het rtestprogramma voor de epaper
 * na het experimenteren met de paper hadden we ondervonden dat deze bibliotheek te traag was
 * in V2 de andere bibliotheek
 * 
 * 
 */

 
/*---Author information-------------------------------------------------------------
 * email:johannes.coolen@hotmail.com
 * Author: Johannes Coolen
 * Version:V1
 * Status:aborted
 */
 
//---Libraries----------------------------------------------------------------------
#include <epd2in13.h>
#include <epdif.h>
#include <epdpaint.h>
#include <fonts.h>
#include <imagedata.h>
#include <SPI.h>


//---Variabelen----------------------------------------------------------------------
#define COLORED     0
#define UNCOLORED   1

unsigned char image[1024];
Paint paint(image, 0, 0);
Epd epd;
unsigned long time_start_ms;
unsigned long time_now_s;


void setup() {
  Serial.begin(115200);   
  delay(500);
  ESP.wdtDisable();       // disable de watchdog timer
   Serial.println("hallo");
   pinMode(0, OUTPUT);    //set pin 0 naar output
  // put your setup code here, to run once:
  
  if (epd.Init(lut_full_update) != 0) {   //initialisatie epaper
    Serial.print("e-Paper init failed");
    yield();
    return;
  }
  yield();
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black

  paint.SetRotate(ROTATE_0);
  paint.SetWidth(128);    // width should be the multiple of 8
  paint.SetHeight(24);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, HIGH);      //testen met standaard blinkprogramma
      Serial.println("hoog");
      delay(500);
      digitalWrite(0, LOW);
     Serial.print("laag");
      yield();
//paint.Clear(COLORED);
//paint.DrawStringAt(30, 4, "Hello world!", &Font12, UNCOLORED);
//epd.SetFrameMemory(paint.GetImage(), 0, 10, paint.GetWidth(), paint.GetHeight());
}
