#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int interruptPin = 2;

unsigned long timeRising;
unsigned long timeRisingOld;
unsigned long umdrehungsZeit;
float drehzahl;


void setup()
{
 lcd.init();

 pinMode(interruptPin, INPUT);

 attachInterrupt(digitalPinToInterrupt(interruptPin), magnetInterrupt, RISING);

 
}


void loop()
{
 lcd.backlight();
 //Nachricht ausgeben
 lcd.setCursor(0,0);
 lcd.print(" RPM:");
 lcd.setCursor(0,1);
 umdrehungsZeit = timeRising - timeRisingOld;
 drehzahl = 60000.f / umdrehungsZeit;
 
 lcd.print("                ");
 lcd.setCursor(0,1);
 lcd.print(drehzahl);
}

void magnetInterrupt(){
 timeRisingOld = timeRising;
 timeRising = millis();
}
