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

void gatheregg() {
	Serial.println("Start");
	Serial.println("Bike");
	pressY(shortPressTime);
        pressRight(shortPressTime)
	Serial.println("Start Biking");
	pressRight(1400);
        Serial.println("Wall was hit, going back");
        pressLeft(holdpress);
        Serial.println("Wall was hit, going back");
        pressRight(holdpress);
        Serial.println("Wall was hit, going back");
        pressLeft(holdpress);
        Serial.println("Wall was hit, going back");
        pressRight(holdpress);
        Serial.println("Wall was hit, going back");
        pressLeft(holdpress);
        Serial.println("Wall was hit, going back");
        pressRight(holdpress);
        Serial.println("Wall was hit, going back");
        pressLeft(holdpress);
        Serial.println("Wall was hit, going back");
        pressRight(holdpress);
        Serial.println("Wall was hit, going back");
        pressLeft(holdpress);
        Serial.println("Wall was hit, going back");
        pressRight(holdpress);
        Serial.println("asking for egg...")
        pressY(shortPressTime);
        pressRight(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressUp(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(2000);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        delay(3600);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressUp(shortPressTime);
        pressA(shortPressTime);
        delay(1650);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(2300);
        pressRight(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);//this will only work for the first 30, then it will need to switch boxes
        pressB(shortPressTime);
        pressB(shortPressTime);
        pressB(shortPressTime);
        pressB(shortPressTime);
        delay(3200);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        delay(3600)
        pressDown(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressUp(shortPressTime);
        
        
       
        
}
void hatch() {
	Serial.println("Start Hatching");
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        delay(3600);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressUp(shortPressTime);
        pressRight(shortPressTime);
        pressRight(shortPressTime);
        pressUp(shortPressTime);
        pressA(shortPressTime);
        delay(1650);
        pressA(shortPressTime);
        pressA(shortPressTime);
        pressDown(shortPressTime);
        pressA(shortPressTime);
        delay(2300)
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(100)
        pressRight(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(100)
        pressRight(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(100)
        pressRight(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(100)
        pressRight(shortPressTime);
        pressA(shortPressTime);
        pressA(shortPressTime);
        delay(100)
        pressB(shortPressTime);
        pressB(shortPressTime);
        pressB(shortPressTime);
        pressB(shortPressTime);
        delay(3000);
        pressLeft(shortPressTime);
        pressLeft(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        pressDown(shortPressTime);
        delay(3600)
        pressDown(shortPressTime);
        Serial.println("getting on bike");
        pressY(shortPressTime);
        pressRight(shortPressTime);
        pressRight(900);
        pressA(shortPressTime);
        checkegg();
        

{
void bikehatch() {
        Serial.println("Biking...")
        pressLeft(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressLeft(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressLeft(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressLeft(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressLeft(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressRight(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressRight(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressRight(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressRight(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
        pressRight(1200);
        pressB(shortPressTime);
        delay(500);
        checkegg();
  
  
}
void checkegg() {
	Serial.println("Checking...");
	if (isScreenOn()) {
		Serial.println("No egg.");
		return; //Go back to hatching
	}
	 else { //If screen is still off, then there is an egg hatching
		Serial.println("egg is hatching...");
		delay(19000);
                pressB(shortPressTime);//Configurable if you want a nickname
                delay(3000);
                return;

	}
}

}

void loop()
{
        gatheregg();
        gatheregg();
        gatheregg();
        gatheregg();
        gatheregg();
	hatch();
}
