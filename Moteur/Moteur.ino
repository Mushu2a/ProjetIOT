#include <Stepper.h>
 
int in1Pin = 2;
int in2Pin = 3;
int in3Pin = 4;
int in4Pin = 5;

int pas = 500;
 
// change this to the number of steps on your motor
#define STEPS 512
 
Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin); 
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
 
  // this line is for Leonardo's, it delays the serial interface
  // until the terminal window is opened
  while (!Serial);
   
  Serial.begin(9600);
  motor.setSpeed(40);
}
 
void loop()
{
  if (Serial.available()) {
    int steps = Serial.parseInt();
    motor.step(pas);
    motor.step(-pas);
  }
}
