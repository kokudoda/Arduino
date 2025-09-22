int SWITCH_SOCKET = 2;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SWITCH_SOCKET,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SWITCH_SOCKET) == 1){
    count += 1;
    Serial.print("Count : ");

    Serial.println(count);
    while(digitalRead(SWITCH_SOCKET) == 1){
      delay(100);
    }
  }
}
