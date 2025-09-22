int CDS_SOCKET = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog_val;
  float input_volt;
  String message = "";

  analog_val = analogRead(CDS_SOCKET);
  input_volt = float(analog_val) * (5.0 / 1024.0);

  if(input_volt > 1.0){
    message = "Lighted";
  }
  else{
    message = "Dark";
  }
  Serial.print(message);
  Serial.print(input_volt);
  Serial.println("V");

  delay(500);
}
