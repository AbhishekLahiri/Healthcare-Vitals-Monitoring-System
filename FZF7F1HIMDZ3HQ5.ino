/*
This example will show you how to use the KY-039 heart bear sensor.
Its a simple basic heart beat monitor with a LCD1602A. In this example i did not use a I2C for those who dont have it.
 */
#include <Wire.h>
#include <SoftwareSerial.h>
//#include <LiquidCrystal.h> 
//#include <LiquidCrystal_I2C.h>//uncomment when using a I2C
double alpha=0.778;
int period=20;
double refresh=0.0;
static double oldValue=0;
static double oldrefresh=0;
SoftwareSerial s(5,6);
   
void setup(void)
{
   pinMode(A0,INPUT);
   pinMode(A1, OUTPUT);
   Serial.begin(9600);
   s.begin(9600);
}

void loop(void)
{
   
 
   int beat=analogRead(A0);
  
   double value=alpha*oldValue+(1-alpha)*beat;
   double value1=random(72,83);
   refresh=value-oldValue;
   analogWrite(A1, value);   
   Serial.println("Heart Rate Monitor");
   delay(2000);
   Serial.println("Place your finger on the sensor");
   delay(7000);
   Serial.println("Measuring......");
   delay(20000);
   Serial.println("40 seconds left");
   delay(20000);
   Serial.println("20 seconds left");
   delay(20000);
   Serial.println(" Heart Rate: "); 
   Serial.print("    ");
   Serial.println(value);
   if(s.available()>0)
   {
      s.write(value);
   }
   
   oldValue=value;
   oldrefresh=refresh;
   Serial.println("Press reset to take new reading");
   delay(1000000);   

  
}
