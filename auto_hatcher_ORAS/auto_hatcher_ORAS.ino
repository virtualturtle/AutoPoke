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
int posUp = 33;

int centerDownRight = 130;
int posDown = 95;
int posRight = 176;

int centerYB = 62;
int posY = 49;
int posB = 93;

int centerAX = 62;
int posA = 43;
int posX = 84;

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

int isScreenDim() {
  return analogRead(lightPin) < 200;
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

/*
  If we have less than 5 eggs,
  Ask for one.
  If we get one, increase our egg counter
*/
void askforegg() {
  delay(200);
  Serial.println("Ask For Egg");
  if (eggs != 5) {
    pressA(150);
    delay(350);
    pressA(150);
    delay(350);
    pressA(150);
    delay(250);
    pressA(150);
    delay(350);
    if (isScreenDim()) {
      Serial.println("Egg Available...");
      pressA(100);
      delay(250);
      pressA(100);
      delay(250);
      pressA(100);
      delay(3200);
      pressA(100);
      delay(250);
      pressA(100);
      eggs ++;
    } else {
      Serial.println("No egg.");
    }
  }
}
/*
  Check if an egg has hatched.  If so, increase hatched counter
*/
void checkMaybeHatchEgg() {
  if (isScreenDim()) {
    Serial.println("egg is hatching...");
    pressA(200);
    delay(18500);
    pressB(300);//Configurable if you want a nickname
    delay(3000);
    hatched ++;
  }
}

void gatherAndHatch5() {
  hatched = 0;
  eggs = 0;
  while(true) {
    Serial.println("Start Left");
    sLeftUp.write(posLeft);
    for (int count2 = 0; count2 < 3400; count2+=10){
      delay(10);
      checkMaybeHatchEgg();
      if (hatched == 5) {
        sLeftUp.write(centerLeftUp);
        return;
      }
    }
    sLeftUp.write(centerLeftUp);
    Serial.println("End Left");
    
    Serial.println("Start Right");
    sDownRight.write(posRight);
    for (int count2 = 0; count2 < 3600; count2+=10){
      delay(10);
      checkMaybeHatchEgg();
      if (hatched == 5) {
        sDownRight.write(centerDownRight);
        return;
      }
    }
    sDownRight.write(centerDownRight);
    Serial.println("End Right");
    askforegg();
  }
}

void deposit_hatched() {
  hatched = 0;
  Serial.println("Going to deposit Hatchlings...");
  pressRight(3700);
  pressY(200);
  pressUp(200);
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
  pressUp(1000);
  delay(2000);
  pressUp(1500);
  pressRight(250);
  pressRight(250);
  pressUp(150);
  pressA(150);
  delay(1900);
  pressA(200);
  pressA(250);
  pressA(150);
  delay(2000);
  deposit();
  deposit();
  deposit();
  deposit();
  deposit();
  boxlimit +=5;
  Serial.println("ADDED 5");
  pressB(150);
  delay(400);
  pressB(150);
  delay(700);
  pressB(150);
  delay(500);
  pressB(150);
  delay(3300);
  pressLeft(220);
  pressLeft(220);
  pressLeft(220);
  pressDown(200);
  pressDown(200);
  pressDown(200);
  pressDown(200);
  pressDown(200);
  pressDown(200);
  pressDown(200);
  delay(2700);
  pressDown(150);
}
void deposit() {
  if (boxlimit == 30) {
    pressRight(250);
    pressA(250);
    pressA(250);
    delay(500);
    pressRight(150);
    delay(500);
    pressA(150);
    delay(300);
    boxlimit = 0;
    Serial.println("SET TO 0");
  } else {
    pressRight(250);
    pressA(250);
    pressA(250);
    delay(400);
    pressA(250);
    delay(400);
  }
}

void loop()
{	
  Serial.println("Start");
  Serial.println("Bike");
  pressY(shortPressTime);
  pressUp(shortPressTime);
  delay(1000);
  gatherAndHatch5();
  deposit_hatched();
}
