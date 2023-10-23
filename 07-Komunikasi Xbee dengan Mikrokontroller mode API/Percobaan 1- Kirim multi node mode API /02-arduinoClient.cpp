void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    if(inByte=='0')
    {
      Serial.println("nol ");
      digitalWrite(13,LOW);
    } 
    else if(inByte=='1')
    {
      Serial.println("satu ");
      digitalWrite(13,HIGH);
    } 
    else
      Serial.write(inByte); 
  }

  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte); 
  }
}
