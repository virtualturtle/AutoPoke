#include <Servo.h>

int boxlimit = 0;
int eggs = 0;
int hatched = 0;
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
int posRight = 146;

int centerYB = 62;
int posY = 40;
int posB = 93;

int centerAX = 62;
int posA = 45;
int posX = 73;

int shortPressTime = 180;
int holdpress = 5200;

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
	return analogRead(lightPin) > 190;
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
void askforegg() {
        pressA(500);
        pressA(500);
        pressA(300);
        pressA(350);
        pressA(300);
        pressA(300);
        pressA(300);
        delay(3500);
        pressA(300);
        pressA(300);
        eggs ++;
        return;
        
}       
void egg1() {
	Serial.println("Start Biking");
	pressRight(2000);
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        Serial.println("Hit wall, going back");
        pressRight(3400);
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        Serial.println("Hit wall, going back");
        pressRight(3400);
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        Serial.println("Hit wall, going back");
        pressRight(3400);
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        Serial.println("Hit wall, going back");
        pressRight(3400);
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        Serial.println("Hit wall, going back");
        pressRight(3400);
        askforegg();
        return;
}

void egg2to5() {
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        pressLeft(150);
        checkegg();
        Serial.println("Hit wall, going back");
        pressLeft(3400);
        pressRight(100);
        checkegg();
        Serial.println("Hit wall, going back");
        pressRight(3400);
        askforegg();
        return;
       
}

void gatheregg() {
	Serial.println("Start");
	Serial.println("Bike");
	pressY(shortPressTime);
        pressUp(shortPressTime);
        egg1();
        egg2to5();
        egg2to5();
        egg2to5();
        egg2to5();
        return;
       
}

void deposit_hatched() {
        hatched = 0;
        Serial.println("Going to deposit Hatchlings...");
        pressRight(3400);
        pressY(150);
        pressUp(150);
        delay(1000);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressLeft(150);
        delay(100);
        pressUp(600);
        delay(2000);
        pressUp(2000);
        pressRight(250);
        pressRight(250);
        pressUp(150);
        pressA(1900);
        pressA(200);
        pressA(250);
        pressA(150);
        delay(2000);
        deposit();
        deposit();
        deposit();
        deposit();
        deposit();
        boxlimit +5;
        pressB(150);
        delay(400);
        pressB(150);
        delay(700);
        pressB(150);
        delay(400);
        pressB(150);
        delay(3100);
        pressLeft(220);
        pressLeft(220);
        pressDown(3700);
        return;
}
void deposit() {
        pressRight(150);
        pressA(150);
        pressA(150);
        if (boxlimit == 30) {
        pressRight(150);
        pressA(150);
        pressA(150);
        boxlimit = 0;
        return;
        } else {
          pressA(150);
          pressA(150);
        return;
        }
}
void hatch() {
        Serial.println("Hatching the rest...");
        pressLeft(3400);
        pressRight(100);
        checkegg();
        Serial.println("Hit wall, going back");
        if (hatched == 5) {
        deposit_hatched();
        } else {
        pressRight(3400);
        pressLeft(100);
        checkegg();
        Serial.println("Hit wall, going back");
        if (hatched == 5) {
        deposit_hatched();
        } else {
        hatch();
        }
        }
}
void checkegg() {
        pressA(200);
	Serial.println("Did anything hatch?");
	if (isScreenOn()) {
		Serial.println("Nope.");
		return; //Go back to hatching
	}
	 else { //If screen is still off, then there is an egg hatching
		Serial.println("egg is hatching...");
		delay(19000);
                pressB(shortPressTime);//Configurable if you want a nickname
                delay(3000);
                hatched ++;
                return;

	}
}



void loop()
{
        eggs = 0;
        gatheregg();
	hatch();
        
}
