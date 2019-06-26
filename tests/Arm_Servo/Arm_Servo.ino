#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(8);
  myservo.write(180);  // set servo to mid-point
} 

void loop()
{
  
}

