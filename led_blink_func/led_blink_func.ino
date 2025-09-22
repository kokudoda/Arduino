void led_blink(int count,int interval);

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  led_blink(10,1000);

  led_blink(3,5000);

  led_blink(7,3000);
}

void led_blink(int count,int interval){
  int i=0;
  while(i < count){
    digitalWrite(13,HIGH);
    delay(interval);
    digitalWrite(13,LOW);
    delay(interval);
    i++;
  }
}
