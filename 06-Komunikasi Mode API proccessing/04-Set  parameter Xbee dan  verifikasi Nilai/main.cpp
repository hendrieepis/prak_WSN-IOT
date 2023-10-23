import processing.serial.*;
Serial myPort;  // Create object from Serial class
int length[] = new int[2];
int dataframeid[]= new int[15];
int lengthTotal,AddressMY,localChecksum;
int state, dataser, i, cntLength=0,  cntframe;
// Data received from the serial port
final int start=0, sLength=1, sAPI=2, sFrame=3, sValue=4, sCheck=5;
int readMY[]= {
		0x7E, 0x00, 0x04, 0x08, 0x52, 0x4D, 0x59, 0xFF
};
void setup() 
{
	size(200, 200);
	state=start;
	String portName = Serial.list()[0];
	println(Serial.list());
	myPort = new Serial(this, portName, 9600);
	for (i=0;i<8;i++)
	{
		myPort.write(readMY[i]);  
		print(hex(readMY[i], 2));
	}
	println("");
	//  7e 00 04 08 52 4D 59 FF -> 7E-00-07-88-52-4D-59-00-12-34-39
}

void draw()
{
	if ( myPort.available() > 0) {  // If data is available,
		dataser = myPort.read();         // read it and store it in val
		switch(state)
		{
		case start:
			if (dataser == 0x7E) {
				state=sLength;
				print(hex(dataser, 2));
			}
			cntLength=0;
			cntframe=0;
			break;
		case sLength:
			if ((cntLength)<2)
			{
				length[cntLength]=dataser;
				print('-');
				print(hex(length[cntLength++], 2));
			} 
			else
			{
				lengthTotal= (length[0]<<8)+length[1];
				print('[');
				print("panjang Data="+hex(lengthTotal, 4));
				print(']');
				print('-');
				dataframeid[cntframe]=dataser;
				print(hex(dataframeid[cntframe], 2));
				cntframe++;
				state=sAPI;
			}
			break;
		case sAPI:
			dataframeid[cntframe]=dataser;
			print(hex(dataframeid[cntframe], 2));
			cntframe++;
			state=sFrame;
			break;
		case sFrame:
			dataframeid[cntframe]=dataser;
			print(hex(dataframeid[cntframe], 2));
			if((cntframe++)==4)
			{
				state=sValue;
				print('-');
			}

			break;
		case sValue:
			dataframeid[cntframe]=dataser;
			print(hex(dataframeid[cntframe], 2));
			if((cntframe++)==6)
			{
				state=sCheck;
				print('[');
				AddressMY= (dataframeid[5]<<8)+dataframeid[6];
				print("nilaiMY="+hex(AddressMY, 4));
				print(']');
				print('-');
			}
			break;
		case sCheck:
			dataframeid[cntframe]=dataser;
			print(hex(dataframeid[cntframe], 2));
			print('[');
			for(i=0;i<cntframe;i++)
				localChecksum+=dataframeid[i];
			print("localchecksum="+hex(localChecksum,4));
			if((0xFF-(dataframeid[cntframe]+localChecksum)&0xFF)==0)
				print("-OK-");
			else
				print("-FCS Error-");
			print(']');
			break;
		}
	}
}
