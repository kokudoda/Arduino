int M_SOCKET = 5;
int m_speed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(M_SOCKET,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(M_SOCKET,m_speed);
  delay(2000);

  m_speed += 15;
  if(m_speed > 255){
    m_speed = 0;
  }
}
