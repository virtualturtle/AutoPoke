#include <Servo.h>

int darktime = 11600;
int encounters = 0;
int lightPin = 2;  //define a pin for Photo resistor
int sPinLeftUp = 2;
int sPinDownRight = 3;
int sPinYB = 4;
int sPinAX = 5;

Servo sLeftUp;
Servo sDownRight;
Servo sYB;
Servo sAX;

int centerLeftUp = 50;
int posLeft = 83;
int posUp = 35;

int centerDownRight = 130;
int posDown = 97;
int posRight = 155;

int centerYB = 62;
int posY = 53;
int posB = 93;

int centerAX = 62;
int posA = 45;
int posX = 73;

int shortPressTime = 350;

void pressButton(Servo s, int time, int rest, int press) {
	s.write(press);
	delay(time);
	s.write(rest);
	delay(250);
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

int isScreenOn() {
	return analogRead(lightPin) > 200;
}

void setup()
{
	Serial.begin(9600);
	sLeftUp.attach(sPinLeftUp);
	sDownRight.attach(sPinDownRight);
	sYB.attach(sPinYB);
	sAX.attach(sPinAX);


	pressLeft(shortPressTime);
	pressUp(shortPressTime);
	pressDown(shortPressTime);
	pressRight(shortPressTime);
	pressY(shortPressTime);
	pressB(shortPressTime);
	pressA(shortPressTime);
	pressX(shortPressTime);
	delay(5000);
}

void hunt() {
	
	pressLeft(shortPressTime);
	checklight();
        pressLeft(shortPressTime);
	checklight();
	pressRight(shortPressTime);
	checklight();
        pressRight(shortPressTime);
	checklight();
}
void checklight() {
  
        if (isScreenOn()) {
                return;
        } else {
                check();
        }
}

void check() {
	//Wait to see if screen has turned back on
	delay(darktime);
        encounters += 1;
        char buff[12];
        Serial.print("Encounters: ");
        Serial.println(itoa(encounters, (char*)(&buff), 10));
        
	
	//If screen is on, then return to hunting
	if (isScreenOn()) {
		
		pressLeft(100);
		pressRight(100);
		pressA(shortPressTime);
		delay(7000);
                return;
	} else { //If screen is still off, then we have a shiny
		
		shiny();
	}
}

void shiny() {
	delay(500);
	pressLeft(shortPressTime);
	delay(500);
	pressA(shortPressTime);
	delay(500);
	pressRight(shortPressTime);
	delay(500);
	pressA(shortPressTime);
	delay(500);
	pressA(shortPressTime);
	delay(500);
	pressA(shortPressTime);
	delay(25000);
	pressB(shortPressTime);
	delay(500);
	pressA(shortPressTime);
	delay(4500);
        hunt();
}

void loop()
{
	hunt();
}
