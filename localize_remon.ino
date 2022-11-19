#include "ESP8266WiFi.h"
#include "FirebaseArduino.h"
//#include "FirebaseESP8266.h"

#include <ArduinoJson.h>

#define FIREBASE_HOST "localization-9c698.firebaseio.com"
#define FIREBASE_AUTH "Oiya9yqr9KO4wa1HQelBdKkBwLDlPH3cRyAzLjoH"
#define SCAN_PERIOD 5000


long lastScanMillis;
const char* ssid = "STUDBME2" ;
const char* password = "BME2Stud";
int j=0;
int d1=0;
int sector=1;
const int resetpin=5;

int rssi ,rssi1,rssi2,rssi3,rssi4,rssi5,rssi6=-99;
String ssId;

void SendData(int NumberOfNetworks){
   
  for (int i = 0; i < NumberOfNetworks; i++)
    {
      Serial.print("wifiName: ");
      ssId = WiFi.SSID(i);
      Serial.println(ssId); 
      Serial.print("strenght:");
      rssi=WiFi.RSSI(i);
      Serial.println(rssi);
      if (ssId=="STUDBME2"){
       rssi1=rssi;
       }
       else if(ssId=="StudBME1"){
       rssi2=rssi; 
       }
       else if(ssId=="DoLa"){
       rssi3=rssi;
        }
        else if(ssId=="SBME_STAFF3"){
        rssi4=rssi;
        }
         else if(ssId=="Redmi 9"){
        rssi5=rssi;
        }
        else if(ssId=="Honor Play"){
        rssi6=rssi;
        }
     }
}

void setup()
 {
  Serial.begin(115200);
  Serial.println("working...");
  pinMode(resetpin, INPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
        
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
   }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//--------------
Serial.println("CLEARSHEET");
Serial.println("LABEL,count,STUDBME2,StudBME1,DoLa,SBME_STAFF3,Redmi 9,Honar Play,sector");

  
}

void loop()
{
  if (j<61)
  {
  WiFi.scanNetworksAsync(SendData);
    if (j != 0){
    Serial.println("DATA,"+String(j)+","+String(rssi1)+","+String(rssi2)+","+String(rssi3)+","+String(rssi4)+","+String(rssi5)+","+String(rssi6)+","+String(sector));    
    }
//  
//        Firebase.setInt("WIFIs/wifi1",rssi1);
//        if (Firebase.failed()) { 
//          Serial.print("setting /number failed:"); 
//          Serial.println(Firebase.error());   
//          return; 
//          }
//       delay(100);  
//       
//        Firebase.setInt("WIFIs/wifi2",rssi2);
//        if (Firebase.failed()) { 
//          Serial.print("setting /number failed:"); 
//          Serial.println(Firebase.error());   
//          return; 
//          }
//       delay(100);  
//    
//        Firebase.setInt("WIFIs/wifi3",rssi3);
//        if (Firebase.failed()) { 
//          Serial.print("setting /number failed:"); 
//          Serial.println(Firebase.error());   
//          return; 
//        }
       delay(1000); 
    j++;     
  }
  else
  {
   d1=digitalRead(resetpin);
   if (d1==HIGH)
   {
      j=0; 
      d1=0;
      rssi1,rssi2,rssi3,rssi4,rssi5,rssi6=-99;
    }
  }
}
