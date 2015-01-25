#include <Servo.h>

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
int posLeft = 65;
int posUp = 40;

int centerDownRight = 130;
int posDown = 120;
int posRight = 150;

int centerYB = 60;
int posY = 50;
int posB = 75;

int centerAX = 60;
int posA = 50;
int posX = 70;

int shortPressTime = 500;

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
	Serial.println("Start Hunt");
	Serial.println("Go Left");
	pressLeft(shortPressTime);
	check();
	Serial.println("Go Right");
	pressRight(shortPressTime);
	check();
}

void check() {
	Serial.println("Checking...");
	if (isScreenOn()) {
		Serial.println("Nope!");
		return; //Go back to hunting
	}
	
	//Wait to see if screen has turned back on
	delay(12000);
	
	//If screen is on, then return to hunting
	if (isScreenOn()) {
		Serial.println("Nope, Closing Menu");
		pressDown(shortPressTime);
		delay(500);
		pressRight(shortPressTime);
		delay(500);
		pressA(shortPressTime);
		delay(7000);
	} else { //If screen is still off, then we have a shiny
		Serial.println("Got One!");
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
	delay(450);
}

void loop()
{
	hunt();
}