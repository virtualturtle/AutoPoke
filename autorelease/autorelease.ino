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
int posDown = 97;
int posRight = 147;

int centerYB = 62;
int posY = 53;
int posB = 93;

int centerAX = 62;
int posA = 45;
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
	return analogRead(lightPin) > 250;
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

void go() {
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressDown(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressDown(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressDown(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressLeft(150);
        rlse();
        pressDown(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        pressRight(150);
        rlse();
        while(true);
}

void rlse() {
        pressA(150);
        Serial.println("Selected.");
        pressUp(150);
        pressUp(150);
        pressA(350);
        pressUp(150);
        pressA(150);
        delay(300);
        pressA(250);
        pressA(250);
        Serial.println("Released.");
        delay(200);
        return;	
}




void loop()
{
	go();
}
