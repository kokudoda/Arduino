#include "RTC.h"
#include <LiquidCrystal.h>

const int year = 2025;
const Month month = Month::SEPTEMBER;
const int day = 21;
const int hour = 13;
const int minutes = 45;
const int second = 50;
const DayOfWeek week = DayOfWeek::SUNDAY;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  RTC.begin();

  RTCTime sTime(day,month,year,hour,minutes,second,week,SaveLight::SAVING_TIME_ACTIVE);

  RTC.setTime(sTime);

  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  RTCTime cTime;

  RTC.getTime(cTime);

  lcd.setCursor(0, 0);

  lcd.print(cTime.getYear());
  lcd.print("/");
  lcd.print(Month2int(cTime.getMonth()));
  lcd.print("/");
  lcd.print(cTime.getDayOfMonth());
  lcd.print(" ");

  lcd.setCursor(0, 1);
  lcd.print(cTime.getHour());
  lcd.print(":");
  lcd.print(cTime.getMinutes());
  lcd.print(":");
  lcd.print(cTime.getSeconds());

  Serial.print(cTime.getYear());
  Serial.print("/");
  Serial.print(Month2int(cTime.getMonth()));
  Serial.print("/");
  Serial.print(cTime.getDayOfMonth());
  Serial.print(" ");

  Serial.print(cTime.getHour());
  Serial.print(":");
  Serial.print(cTime.getMinutes());
  Serial.print(":");
  Serial.println(cTime.getSeconds());

  

  delay(1000);
}
