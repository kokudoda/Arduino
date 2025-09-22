#include "WiFiS3.h"

char ssid[]="";
char pass[]="";

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("Failed to WiFi communication.");
    while(true);
  }

  while(status != WL_CONNECTED){
    Serial.print("Try Conecting to ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,pass);

    delay(10000);
  }

  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  // put your main code here, to run repeatedly:

}
