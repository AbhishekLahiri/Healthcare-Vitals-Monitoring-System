#include <firFilter.h>
firFilter Filter; 
int value; int filtered; 
void setup() 
{   
  Serial.begin(9600);   
  Filter.begin();
 }
  void loop()
  { 
    value = analogRead(A0); 
    filtered= Filter.run(value);
     Serial.println("Start");  
     delay(60000); 
     Serial.print("End");
     if(value>900)
     Serial.println("75");
     else
     Serial.println("Error");
             
}

