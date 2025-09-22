void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value,answer;

  value=7;

  answer = value % 2;

  if(answer == 0){
    Serial.println("Even number");
  }
  else{
    Serial.println("Odd number");
  }
  delay(10000);
}
