int VOLUME_SOCKET = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_val;
  float input_volt;

  analog_val = analogRead(VOLUME_SOCKET);

  input_volt = float(analog_val) * (5.0 / 1024.0);

  Serial.print(analog_val);
  Serial.print(" : ");
  Serial.print(input_volt);
  Serial.println("V");

  delay(500);
}
