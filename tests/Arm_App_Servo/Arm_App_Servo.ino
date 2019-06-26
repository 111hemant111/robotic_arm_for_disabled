int servoPin = 12;
int angle = 0;
int pulseWidth = 0;
int token = 28;

/////JOYSTICKS' PINS/////
int pinOpen = 10;
int pinClose = 11;

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
    varClose = digitalRead(pinClose);
    varOpen = digitalRead(pinOpen);

    if (varClose == LOW)
      {
       for (angle=token; angle<=165 && (digitalRead(pinClose)) == LOW && (digitalRead(pinOpen)) == HIGH; angle++)
          {
            servoPulse(servoPin, angle);
            Serial.println("HOLD");
            token = angle;
          }
      }

    if (varOpen == LOW)
      {
       for (angle=token; angle>=28 && (digitalRead(pinOpen)) == LOW && (digitalRead(pinClose)) == HIGH; angle--)
          {
            servoPulse(servoPin, angle);
            Serial.println("RELEASE");
            token = angle;
          }
      }
    
  }


  void servoPulse(int servoPin, int angle)
{
  pulseWidth = (angle*10) + 575;
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
}
