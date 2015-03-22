int soundPin = 3;  //define a pin for Photo resistor

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    
}

void loop()
{
    Serial.println(analogRead(soundPin)); //Write the value of the photoresistor to the serial monitor.
    
                                           
   delay(10); //short delay for faster response to light.
}
