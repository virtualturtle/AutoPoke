#include <Servo.h>

int encounters = 0;
int soundPin = 3;
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
int posY = 38;
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
	return analogRead(lightPin) > 200;

}
int isSoundLoud() {
	return analogRead(soundPin) > 900;
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

long sample(int times) {
	long result;
	for(; times > 0; times--) {
		result += analogRead(soundPin);
	}
	return result;
}

void hunt() {
	pressY(100);
	delay(200);
	pressRight(150);
	delay(2600);

	long s;
	s = sample(300);
	Serial.println(s);
	for(; s < 100000000; s = sample(300)) {
		Serial.println(s);
	}
	pressA(150);
	check();
}
void check() {
	//Wait to see if screen has turned back on
	delay(12900);
	encounters += 1;
	char buff[12];
	Serial.print("Encounters: ");
	Serial.println(itoa(encounters, (char*)(&buff), 10));

	//If screen is on, then return to hunting
	if (isScreenOn()) {
		pressLeft(100);
		pressRight(100);
		pressA(shortPressTime);
		delay(7300);
	} else { //If screen is still off, then we have a shiny
		pressLeft(100);
		pressA(100);
		delay(800);
		pressRight(100);
		pressA(100);
		delay(300);
		pressA(100);
		delay(100);
		pressA(100);
		delay(24000);
		pressB(100);
		delay(1000);
		pressA(100);
		delay(5000);
	}
}

void loop()
{
	hunt();
}
