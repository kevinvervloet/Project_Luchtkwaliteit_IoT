/*---Author information-------------------------------------------------------------
 * email: kevin.vervloet@student.kdg.be
 * Author: Air Quality Boys
 * Version: 1.0
 * Status: Bezig
 */

//---Libraries----------------------------------------------------------------------
#include "Adafruit_CCS811.h"       

Adafruit_CCS811 ccs;

//---variabelen----------------------------------------------------------------------
const unsigned long IntervalGas = 10000;    // dit is de interval tijd 
unsigned long previousTimeGas = 0;          // Vorige tijd


//---Setup--------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);

  Serial.println("CCS811 test");

  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");    // Bug controle
    while(1);
  }

  
  while(!ccs.available());      // wacht tot de sensor beschikbaar is -> ga dan naar de loop
}

//---Loop--------------------------------------------------------------------------
void loop() {
  unsigned long currentTimeGas = millis(); // huidige tijd van millis die constant veranderd

  if(currentTimeGas - previousTimeGas >= IntervalGas {
    if(ccs.available()){
      if(!ccs.readData()){
        Serial.print("CO2: ");
        Serial.print(ccs.geteCO2());
        Serial.print("ppm, TVOC: ");
        Serial.println(ccs.getTVOC());
        previousTime = currentTimeGas     // Update de waarde van millis
      }
      else{
        Serial.println("ERROR!");
        while(1);
    }
    
  }
 
}

//--------------------------------------------------------------------------------
//Gemaakt door de groep Luchtkwaliteit
//Graduaat IoT
//Klas 1.1
