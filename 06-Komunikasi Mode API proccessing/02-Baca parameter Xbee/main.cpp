import processing.serial.*;

Serial myPort;  // Create object from Serial class
int inbyte, i;  // Data received from the serial port
int readMY[]= {
		0x7E, 0x00, 0x04, 0x08, 0x52, 0x4D, 0x59, 0xFF
};
void setup() 
{
	size(200, 200);
	String portName = Serial.list()[0];
	println(Serial.list());
	myPort = new Serial(this, portName, 9600);
	for (i=0;i<8;i++)
	{
		myPort.write(readMY[i]);  
		print(hex(readMY[i], 2));
	}
	println("");
	//  7e 00 04 08 52 4D 59 FF
}

void draw()
{
	if ( myPort.available() > 10) {  // If data is available,
		inbyte = myPort.read();         // read it and store it in val
		if (inbyte == 0x7E) {
			print(hex(inbyte, 2));
			for (i=0;i<10;i++)
			{
				print('-');
				print(hex(myPort.read(), 2));
			}
		}
	}
}
