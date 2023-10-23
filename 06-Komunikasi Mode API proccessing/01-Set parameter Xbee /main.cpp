import processing.serial.*;

Serial myPort;  // Create object from Serial class
int inbyte;      // Data received from the serial port

// 7E 00 06 08 4D 4D 59 23 45 9C
void setup() 
{
	size(200, 200);
	println(Serial.list());
	String portName = Serial.list()[0];
	//  println(Serial.list());
	myPort = new Serial(this, portName, 9600);
	myPort.write(0x7E);
	myPort.write(0x00);
	myPort.write(0x06);
	myPort.write(0x08);
	myPort.write(0x4D);
	myPort.write(0x4D);
	myPort.write(0x59);
	myPort.write(0x23);
	myPort.write(0x45);
	myPort.write(0x9C);
}

void draw()
{

}
