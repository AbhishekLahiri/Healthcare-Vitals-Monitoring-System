
#define heartratePin A0
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = "2a5ccab7134747769aa2004910660f77";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "NETGEAR_HANRA";    // Your WiFi credentials.
char pass[] = "Scpapa@1961";  // Set password to "" for open networks.

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000, sendUptime);

}

void sendUptime()
{
  
  //uint8_t rateValue;
   int beat=analogRead(heartratePin);
   Blynk.virtualWrite(V5,beat);
  
  
}
void loop() {

  Blynk.run();
  timer.run();
 
}


