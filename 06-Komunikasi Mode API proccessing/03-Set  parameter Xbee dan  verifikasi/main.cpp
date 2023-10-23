import processing.serial.*;

Serial myPort; // Create object from Serial class
int dataser, i; // Data received from the serial port
int startChar=0x7E;
int[] buffer = new int[40]; 
boolean storeString=false;
int index=0;
int setMY[]= {0x7E, 0x00, 0x05, 0x08, 0x4D, 0x4D, 0x59, 0x03, 0x01};
int readMY[]= {0x7E, 0x00, 0x04, 0x08, 0x52, 0x4D, 0x59, 0xFF};

void setup() 
{
	size(200, 200);
	String portName = Serial.list()[0];
	println(Serial.list());
	myPort = new Serial(this, portName, 9600);
	for (i=0;i<9;i++)
	{
		myPort.write(setMY[i]); 
		print(hex(setMY[i], 2));
	}
	println("");

	for (i=0;i<8;i++)
	{
		myPort.write(readMY[i]); 
		print(hex(readMY[i], 2));
	}
	println("");
	// 7E 00 05 08 52 4D 59 03 FC -> 7E-00-05-88-52-4D-59-00-7F
	// 7e 00 04 08 52 4D 59 FF    -> 7E-00-07-88-52-4D-59-00-00-03-7C

}

void draw()
{
	while ( myPort.available () > 0) { // If data is available,
		dataser = myPort.read(); // read it and store it in val
		//print(hex(dataser, 2));
		if (dataser == startChar) {
			storeString=true;
			index=0;
			break;
		} 

		if (storeString==true)
		{
			buffer[index++] =dataser;
			if (index>=  10) 
			{
				print(hex(0x7E, 2));
				for (i=0;i<index;i++)
				{
					print('-');
					print(hex(buffer[i], 2));
				}
				storeString=false; 
				index=0;
			}
		}
	}
}
