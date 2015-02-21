#include <Servo.h>

int lightPin = 2;  //define a pin for Photo resistor
int sPinLeftRight = 2;
int sPinYA = 3;


Servo sLeftRight;
Servo sYA;


int centerLeftRight = 50;
int posLeft = 65;
int posRight = 40;

int centerYA = 60;
int posY = 50;
int posA = 70;

int shortPressTime = 200;

void pressButton(Servo s, int time, int rest, int press) {
	s.write(press);
	delay(time);
	s.write(rest);
	delay(250);
}

void pressLeft(int time) {
	pressButton(sLeftRight, time, centerLeftRight, posLeft);
}

void pressRight(int time) {
	pressButton(sLeftRight, time, centerLeftRight, posRight);
}
void pressY(int time) {
	pressButton(sYA, time, centerYA, posY);
}

void pressA(int time) {
	pressButton(sYA, time, centerYA, posA);
}



int isScreenOn() {
	return analogRead(lightPin) > 200;
}

void setup()
{
	Serial.begin(9600);
	sLeftRight.attach(sPinLeftRight);
	sYA.attach(sPinYA);


	pressLeft(shortPressTime);

	pressRight(shortPressTime);
	pressY(shortPressTime);
	pressA(shortPressTime);
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
		pressLeft(shortPressTime);
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

void shiny() { //This is what it does when it finds a shiny
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
