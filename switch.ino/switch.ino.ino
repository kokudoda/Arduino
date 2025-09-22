int SWITCH_SOCKET = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(SWITCH_SOCKET,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(SWITCH_SOCKET));
  delay(1000);
}
