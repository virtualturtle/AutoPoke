#include <Servo.h>

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
int posLeft = 75;
int posUp = 35;

int centerDownRight = 130;
int posDown = 100;
int posRight = 145;

int centerYB = 60;
int posY = 53;
int posB = 93;

int centerAX = 62;
int posA = 47;
int posX = 73;

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
	Serial.println("Start Hunt");
	Serial.println("open menu");
	pressX(100);
	Serial.println("view party");
	pressA(150);
        delay(1600);
	Serial.println("open sweet scenter");
	pressA(100);
	pressDown(100);
	pressA(100);
	Serial.println("sweet scent");
	pressA(100);
        check();
}

void check() {
	//Wait to see if screen has turned back on
	delay(20100);
        encounters += 1;
        char buff[12];
        Serial.print("Encounters: ");
        Serial.println(itoa(encounters, (char*)(&buff), 10));
        
	
	//If screen is on, then return to hunting
	if (isScreenOn()) {
		Serial.println("Nope, Closing Menu");
		pressLeft(100);
		pressRight(100);
		pressA(shortPressTime);
		delay(7100);
                return;
	} else { //If screen is still off, then we have a shiny
		Serial.println("Got One! Waiting for Human...");
		delay(12000000);
	}
}




void loop()
{
	hunt();
}
