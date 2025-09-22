void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //int count=0;

  /*while(count < 100){
    count+=1;

    Serial.print("Count : ");
    Serial.println(count);

    delay(1000);
  }*/

  for(int count=1;count<=100;count++){
    Serial.print("Count : ");
    Serial.println(count);
    delay(1000);
  }
}
