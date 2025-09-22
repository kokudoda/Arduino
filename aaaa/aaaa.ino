#include <Wire.h>
#include <LiquidCrystal.h>
#define SHT31_ADDR 0x45

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  Wire.begin();
  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x30);
  Wire.write(0xa2);
  Wire.endTransmission();
  delay(500);

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x30);
  Wire.write(0x41);
  Wire.endTransmission();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int dac[6];
  unsigned int i,t,h;
  float temp,humi;

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x24);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(300);

  Wire.requestFrom(SHT31_ADDR,6);
  for(i=0;i<6;i++){
    dac[i]=Wire.read();
  }
  Wire.endTransmission();

  t=(dac[0] << 8) | dac[1];
  temp=(float)(t) * 175/65535.0 - 45.0;
  h=(dac[3] << 8) | dac[4];
  humi=(float)(h) / 65535.0 * 100.0;
  
  lcd.setCursor(0, 0);

  lcd.print("Temperature : ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity    : ");
  lcd.print(humi);
  lcd.println(" %");

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.print("Humidity    : ");
  Serial.print(humi);
  Serial.println(" %");

  delay(1000);
}
