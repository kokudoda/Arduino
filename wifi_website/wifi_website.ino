#include "WiFiS3.h"

char ssid[]="";
char passwd[]="";

int status = WL_IDLE_STATUS;

char server[]="www.sotechsha.co.jp";
char pagepath[]="/sp/1330/arduino_test.html";

WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if(WiFi.status()==WL_NO_MODULE){
    Serial.println("Failed to WiFi communication.");
    while(true);
  }

  while(status != WL_CONNECTED){
    Serial.print("Try Connect to ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,passwd);

    delay(10000);
  }

  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  IPAddress ip=WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  // put your main code here, to run repeatedly:
  char buf;

  if(client.connect(server,80)){
    client.print("GET ");
    client.print(pagepath);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  }
  else{
    Serial.println("connection failed");
  }

  while(client.connected()){
    if(client.available()){
      buf=client.read();
      Serial.print(buf);
    }
  }

  client.stop();

  delay(600000);
}
