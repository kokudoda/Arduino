#include <Wire.h>
#define SHT31_ADDR 0x45

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  unsigned int dec[6];
  unsigned int i,t,h;
  float temp,humi;

  Wire.beginTransmission(SHT31_ADDR);
  Wire.write(0x24);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(300);

  Wire.requestFrom(SHT31_ADDR,6);
  for(i=0;i<6;i++){
    dec[i]=Wire.read();
  }
  Wire.endTransmission();

  t=(dec[0] << 8) | dec[1];
  temp=(float)(t) * 175/65535.0-45.0;
  h=(dec[3] << 8) | dec[4];
  humi=(float)(h) / 65535.0 * 100.0;

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.print("Humidity  : ");
  Serial.print(humi);
  Serial.println(" %");
  
  delay(1000);

}
