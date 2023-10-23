unsigned char TxFrame[]= {
  0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x00, 0x31, 0xCC};

void sendData8bit(unsigned int node, unsigned char data){
  TxFrame[5]=(node>>8);
  TxFrame[6]=(unsigned char) node;
  TxFrame[7]=0x00;
  TxFrame[8]=data;
  for(int i=0;i<=8;i++) {
    Serial1.write(TxFrame[i]);
  };
  Serial1.write(0xFF-((TxFrame[3]+TxFrame[4]+TxFrame[5]+TxFrame[6]+TxFrame[7]+TxFrame[8])&0xFF));  
}

void setup() {
  Serial1.begin(9600);
}

void loop() {
  for(int cnt=0;cnt<=255;cnt++)
  {
    sendData8bit(1,cnt);
    sendData8bit(2,cnt);
    sendData8bit(3,cnt);
  }
}
