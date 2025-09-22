void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int count=0;

  while(count < 10){
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(5000);
    count++;
  }

  count=0;
  while(count < 7){
    digitalWrite(13,HIGH);
    delay(3000);
    digitalWrite(13,LOW);
    delay(3000);
    count++;
  }
}
