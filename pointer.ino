//************************************************
const char* ssid     = "BABAK";
const char* password = "1374138319952004bb";
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include<ESP8266HTTPClient.h>
#include "index.h"
ESP8266WebServer server(80);
IPAddress local_IP(192, 168, 1, 150);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
//************************************************

String R;
long pointer;
String pointer2="XX";

void setup() {
    Serial.begin(9600);
    delay(1000);
    pinMode(A0,INPUT);
    if (!WiFi.config(local_IP, gateway, subnet))
  {
    //Serial.println("Failed to Configure");
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  server.on("/",vdd1);
  server.on("/SET",vdd2);
  server.begin();
}

void vdd1()
{
    server.send(200,"text/html",index_page);
}
void vdd2()
{
  String Ric = server.arg("password");
  if(Ric == "1234")
  {
     pointer = analogRead(A0);
     pointer2 = String(pointer);
     server.send(200,"text/plain",pointer2);
  }
}
void loop()
{
  server.handleClient();
    
  delay(100);
  
  if(Serial.available())
  {
    pointer2 = Serial.readStringUntil('\n');
  }
  Serial.println(pointer2);
  //pointer2 = String(pointer);
 
}
