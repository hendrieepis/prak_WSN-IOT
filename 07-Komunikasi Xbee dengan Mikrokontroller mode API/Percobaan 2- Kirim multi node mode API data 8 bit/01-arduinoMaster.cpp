unsigned char sendnode1[]= {
		0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x00, 0x31, 0xCC};

unsigned char sendnode2[]= {
		0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x02, 0x00, 0x32, 0xCA};

unsigned char sendnode3[]= {
		0x7E, 0x00, 0x06, 0x01, 0x00, 0x00, 0x03, 0x00, 0x33, 0xC8};

void sendtoNode1(unsigned char cnt){
	for(int i=0;i<8;i++) {
		Serial1.write(sendnode1[i]);
	};
	sendnode1[8]=cnt;
	Serial1.write(sendnode1[8]);
	Serial1.write(0xFF-((sendnode1[3]+sendnode1[4]+sendnode1[5]+sendnode1[6]+sendnode1[7]+sendnode1[8])&0xFF));  
}

void sendtoNode2(unsigned char cnt){
	for(int i=0;i<8;i++) {
		Serial1.write(sendnode2[i]);
	};
	sendnode2[8]=cnt;
	Serial1.write(sendnode2[8]);
	Serial1.write(0xFF-((sendnode2[3]+sendnode2[4]+sendnode2[5]+sendnode2[6]+sendnode2[7]+sendnode2[8])&0xFF));  
}

void sendtoNode3(unsigned char cnt){
	for(int i=0;i<8;i++) {
		Serial1.write(sendnode3[i]);
	};
	sendnode3[8]=cnt;
	Serial1.write(sendnode3[8]);
	Serial1.write(0xFF-((sendnode3[3]+sendnode3[4]+sendnode3[5]+sendnode3[6]+sendnode3[7]+sendnode3[8])&0xFF));  
}


void setup() {
	//  delay(500);
	Serial.begin(9600);
	Serial1.begin(9600);
}

int delaypar=300;

void loop() {
	for(int cnt=0;cnt<=255;cnt++)
	{
		sendtoNode1(cnt);
	}

	for(int cnt=0;cnt<=255;cnt++)
	{
		sendtoNode2(cnt);
	}

	for(int cnt=0;cnt<=255;cnt++)
	{
		sendtoNode3(cnt);
	}
	delay(delaypar);
}
