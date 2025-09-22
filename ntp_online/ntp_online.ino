#include "WiFiS3.h"
#include "RTC.h"
#include <NTPClient.h>
#include <LiquidCrystal.h>

const int timezone = 9; //タイムゾーンの指定
const int timeout = 5;  //無線LANアクセスポイントかへ接続を試行する回数

const char ssid[]="";
const char pass[]="";

int status = WL_IDLE_STATUS;

boolean onwifi = true;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"pool.ntp.org",timezone * 3600,60000);

RTCTime crTime;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void wificonnect(){
  int trywifi = 0;

  if(WiFi.status()==WL_NO_MODULE){
    Serial.println("Failed to WiFi communication.");
    while(true);
  }

  while(status != WL_CONNECTED){
    if(trywifi > timeout){
      Serial.println("Could not connect to wifi.");
      onwifi = false;
      break;
    }
    else{
      Serial.print("Try Connect to ");
      Serial.println(ssid);
      status = WiFi.begin(ssid,pass);
    }
    trywifi++;
    delay(10000);
  }

  if(onwifi == true){  //正常に接続できた場合
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
  }
}

void getntptime(){  
  unsigned long epochtime;
  timeClient.update();  //NTPサーバーから日時情報を取得
  epochtime = timeClient.getEpochTime();  //日時をエポック秒で取得
  RTCTime ntptime(epochtime);
  RTC.setTime(ntptime);
  Serial.print("NTP Time is ");
  Serial.println(ntptime);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  wificonnect();
  RTC.begin();
  lcd.begin(16, 2);

  if(onwifi == true){
    timeClient.begin();
    getntptime();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  RTC.getTime(crTime);

  lcd.setCursor(0,0); //(列,行)
  lcd.print(crTime.getYear());
  lcd.print("/");
  lcd.print(Month2int(crTime.getMonth()));
  lcd.print("/");
  lcd.print(crTime.getDayOfMonth());
  lcd.print(" ");

  lcd.setCursor(0,1); //(列,行)
  lcd.print(crTime.getHour());
  lcd.print(":");
  lcd.print(crTime.getMinutes());
  lcd.print(":");
  lcd.print(crTime.getSeconds());

  delay(1000);
}
