int LED_SOCKET = 10;
int INTERVAL = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_SOCKET,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_SOCKET,HIGH);

  delay(INTERVAL);
  digitalWrite(LED_SOCKET,LOW);

  delay(INTERVAL);
}
