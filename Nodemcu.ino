#define BLYNK_MAX_SENDBYTES 1200
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
//#include <ThingSpeak.h>
SoftwareSerial s(D6,D5);
//#include <DHT.h>
int data;

char auth[] = "2a5ccab7134747769aa2004910660f77";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "user_id";
char pass[] = "password";
//char *thingSpeakAddress = "api.thingspeak.com";
//unsigned long channelID = 780005;
//char* readAPIKey = "4S5T8DLBCRSXZ2A8";
//char* writeAPIKey = "6C1YKF44IIMR6KLG";


//#define DHTPIN D6          // What digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

//DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
unsigned int dataFieldOne = 1;  
//WiFiClient client;  

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
//int write2TSData( long TSChannel, unsigned int TSField1, float field1Data){
//
//  ThingSpeak.setField( TSField1, field1Data );
//  int writeSuccess = ThingSpeak.writeFields( TSChannel, writeAPIKey );
//  return writeSuccess;
//}
void sendSensor()
{
  s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);//float t = dht.readTemperature(true); // or dht.readTemperature(true) for Fahrenheit

  }
  
 
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, data);

  if(data<60 && data!=0){
    Blynk.email("Heart Rate Alert", "Heart Rate less than normal.");  //"sankhasubhrasenapati@gmail.com",
    Blynk.notify("Heart Rate Alert - Heart Rate less than normal.");
  }
  else if(data>100){
    Blynk.email("Heart Rate Alert", "Heart Rate higher than normal.");
    Blynk.notify("Heart Rate Alert - Heart Rate higher than normal.");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  s.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(A0,INPUT);
//  WiFi.begin(ssid,pass);
//  ThingSpeak.begin( client );

//  Blynk.virtualWrite(V5, h);
  // Setup a function to be called every second
  timer.setInterval(10000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}


