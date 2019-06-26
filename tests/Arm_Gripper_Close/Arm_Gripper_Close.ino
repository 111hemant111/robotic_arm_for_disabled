#include <Servo.h>
// SERVO MOTOR (GRIPPER DECLARATIONS)
  Servo claw; // create servo object to control a servo
  int pos = 0; // variable to store the servo position

  
void setup() 
{
    //SERVO SETUP
    claw.attach(9); // attaches the servo on pin 8 to the servo object

}

void loop() {
  claw.write(70);
//  gripperOpen();
//  delay(5000);
//  gripperClose();
//  delay(5000);

}
// GRIPPER FUNCTIONS
void gripperOpen()
  {
    for (pos = 140; pos >= 40; pos--) 
      { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      claw.write(pos); // tell servo to go to position in variable 'pos'
      //delay(15); // waits 15ms for the servo to reach the position
      }
  }
  
void gripperClose()
  {
    for (pos = 40; pos <= 140; pos++) 
      { // goes from 180 degrees to 0 degrees
      claw.write(pos); // tell servo to go to position in variable 'pos'
      //delay(15); // waits 15ms for the servo to reach the position
      }
  }
