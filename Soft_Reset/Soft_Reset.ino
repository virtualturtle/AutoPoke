#include <Servo.h>
int starter = 1; // treecko is 1, torchic is 2, and mudkip is 3
int encounters = 0;
int lightPin = 2;  //define a pin for Photo resistor
int sPinLeftUp = 2;
int sPinDownRight = 3;
int sPinYB = 4;
int sPinAX = 5;
int sPinS = 8;

Servo sLeftUp;
Servo sDownRight;
Servo sYB;
Servo sAX;
Servo sS;

int centerLeftUp = 50;
int posLeft = 75;
int posUp = 35;

int centerDownRight = 130;
int posDown = 99;
int posRight = 147;

int centerYB = 62;
int posY = 53;
int posB = 93;

int centerAX = 62;
int posA = 43;
int posX = 73;

int centerS = 90;
int posS = 80;


int shortPressTime = 220;


void pressButton(Servo s, int time, int rest, int press) {
	s.write(press);
	delay(time);
	s.write(rest);
        delay(shortPressTime);
}

void pressLeft(int time) {
	pressButton(sLeftUp, time, centerLeftUp, posLeft);
}
void pressUp(int time) {
	pressButton(sLeftUp, time, centerLeftUp, posUp);
}
void pressDown(int time) {
	pressButton(sDownRight, time, centerDownRight, posDown);
}
void pressRight(int time) {
	pressButton(sDownRight, time, centerDownRight, posRight);
}
void pressY(int time) {
	pressButton(sYB, time, centerYB, posY);
}
void pressB(int time) {
	pressButton(sYB, time, centerYB, posB);
}
void pressA(int time) {
	pressButton(sAX, time, centerAX, posA);
}
void pressX(int time) {
	pressButton(sAX, time, centerAX, posX);
}
void pressS(int time) {
	pressButton(sS, time, centerS, posS);
}

int isScreenOn() {
	return analogRead(lightPin) > 250;
}

void setup()
{
    Serial.begin(9600);
    sLeftUp.attach(sPinLeftUp);
	sDownRight.attach(sPinDownRight);
	sYB.attach(sPinYB);
	sAX.attach(sPinAX);

        //READ INTEGER FROM PROGRAM
	pressLeft(shortPressTime);
	pressUp(shortPressTime);
	pressDown(shortPressTime);
	pressRight(shortPressTime);
	pressY(shortPressTime);
	pressB(shortPressTime);
	pressA(shortPressTime);
	pressX(shortPressTime);
        pressS(shortPressTime);
	delay(5000);
}

void hunt() {
	
	
	
	pressA(150);
        delay(3400);
        pressA(150);
        if (starter = 1) {
                pressLeft(200);
                pressA(150);
                pressA(150);
                check();
        } else {
        if (starter = 2) {
                pressA(150);
                pressA(150);
                check();
        } else {
                pressRight(200);
                pressA(150);
                pressA(150);
                check();
        }
        }
}

void check() {
	//Wait to see if screen has turned back on
	delay(15500);
        encounters += 1;
        char buff[12];
        Serial.print("Encounters: ");
        Serial.println(itoa(encounters, (char*)(&buff), 10));
	//If screen is on, then return to hunting
	if (isScreenOn()) {
		
		pressS(200);
		delay(10500);
                pressA(150);
                delay(250);
                pressA(100);
	        delay(4200);
                return;
	} else { //If screen is still off, then we have a shiny
		
		while(true);
	}
}




void loop()
{
	hunt();
}
