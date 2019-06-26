int servoPin = 12;
int angle = 0;
int pulseWidth = 0;
int token = 0;

/////JOYSTICKS' PINS/////
int pinClose = 10;
int pinOpen = 11;

/////JOYSTICKS' VARIABLES/////
int varClose = 0;
int varOpen = 0;

void setup() 
  { 
    pinMode(pinClose, INPUT);
    pinMode(pinOpen, INPUT);

    pinMode(servoPin, OUTPUT);
    
    Serial.begin(9600);
    Serial.println("Joystick control started");
   } 

void loop() 
  {

       for (angle=token; angle<=150; angle++)
          {
            servoPulse(servoPin, angle);
            Serial.println("HOLD");
            token = angle;
          }
   

       for (angle=token; angle>=0; angle--)
          {
            servoPulse(servoPin, angle);
            Serial.println("RELEASE");
            token = angle;
          }
    
  }


  void servoPulse(int servoPin, int angle)
{
  pulseWidth = (angle*10) + 550;
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
}
