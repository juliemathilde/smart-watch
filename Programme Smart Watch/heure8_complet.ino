#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Wire.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
Adafruit_SH1106 display(23); 

#include "SparkFunBME280.h"
#include "SparkFunBME280.h"
#include<SoftwareSerial.h>
#define RX 10
#define TX 11




BME280 mySensor;

void setup() {
  Serial.begin(9600);
  display.begin();  // initialisation de l'afficheur
  display.clearDisplay();
  Wire.begin();
  mySensor.setI2CAddress(0x76);
  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("not respond");
    while(1); //Freeze
  }
  while (!Serial) ; // wait for serial
  delay(200);
}

void loop() {
  
  display.setTextColor(WHITE);
  display.setTextSize(1);  // taille par défaut

  display.setCursor(30,20);  // coordonnées du point de départ du texte
  display.print("A:");
  display.print(mySensor.readFloatAltitudeFeet()/3.2808);
  Serial.println(mySensor.readFloatAltitudeFeet()/3.2808);
  display.print(" m");
  display.setCursor(30,30);
  display.print("T:");
  display.print((mySensor.readTempF()-32)/1.8);
  display.print(" C");
  display.setCursor(30,40);
  display.print("P:");
  display.print((mySensor.readFloatPressure()));
  display.print(" Pa");
  
  tmElements_t tm;
  if (RTC.read(tm)) {
    //heure
    display.setCursor(30,0);  // coordonnées du point de départ du texte
    display.print(tm.Hour);
    display.print(":");
    display.print(tm.Minute);
    //date
    display.setCursor(30,10);
    display.print(tm.Day);
    display.print("/");
    display.print(tm.Month);
    display.print("/");
    display.print(tmYearToCalendar(tm.Year));
    
  display.display();  // affichage à l'écran
  delay(1000);
  display.clearDisplay();
 
  }
}
