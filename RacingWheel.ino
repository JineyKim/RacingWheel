#include "Joystick.h" // Gaming gear library

Joystick_ Joystick;

int16_t Handle[20]; // Input 20 times value
int16_t HandleSum; // Sum of 20 values
int outValue; // Final output value
int i; // For for loop

void setup()
{
  delay(1000); // Start delay
  //analogReference(INTERNAL); // Set input range
  Joystick.setXAxisRange(-512,511); // Set output range
  Joystick.begin();
  pinMode(A0,INPUT_PULLUP);// Set input mode to pull-up
  //Serial.begin(9600); // For test (deleted to improve performance)
}

void loop()
{
  HandelSum=0; // HandleSum value reset
  Handle[19]=analogRead(A0); // Set the 19th value to input of A0
  for(i=0;i<19;i++) // Repeat 20 times
  {
    Handle[i]=Handle[i+1]; // Pull one step forward
    HandleSum+=Handel[i]; // If you pull it, add it
  }
  outValue=(HandleSum/20)-512; // Calculate the output value
  //Serial.println(outValue); // For test (deleted to improve performance)
  delay(1); // A little delay
}
