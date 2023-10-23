unsigned char sendnode1off[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x00, 0x30, 0xCD}; 
unsigned char sendnode1on[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x00, 0x31, 0xCC};

unsigned char sendnode2off[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x02, 0x00, 0x30, 0xCC};
unsigned char sendnode2on[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x02, 0x00, 0x31, 0xCB};

unsigned char sendnode3off[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x03, 0x00, 0x30, 0xCB};
unsigned char sendnode3on[] {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x03, 0x00, 0x31, 0xCA};

void setup() {
  //  delay(500);
  Serial.begin(9600);
  Serial1.begin(9600);
}

int delaypar=300;
void loop() {
  for(int i=0;i<10;i++)
    Serial1.write(sendnode1on[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode2off[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode3off[i]);
  delay(delaypar);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode1off[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode2on[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode3off[i]);
  delay(delaypar);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode1off[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode2off[i]);
  for(int i=0;i<10;i++)
    Serial1.write(sendnode3on[i]);
  delay(delaypar);
}
