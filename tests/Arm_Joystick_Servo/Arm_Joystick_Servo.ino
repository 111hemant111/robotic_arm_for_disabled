int servoPin = 12;
int angle = 0;
int pulseWidth = 0;
int token = 28;

/////JOYSTICKS' PINS/////
int pin1x = 0;
int pin2x = 1;
int pin1y = 2;
int pin2y = 3;
int pin1btn = 8;
int pin2btn = 9;

/////JOYSTICKS' VARIABLES/////
int joy1x = 0;
int joy2x = 0;
int joy1y = 0;
int joy2y = 0;
int joy1btn = 0;
int joy2btn = 0;

void setup() 
{ 
  pinMode(pin1btn, INPUT);
    pinMode(pin2btn, INPUT);

    pinMode(servoPin, OUTPUT);

    //myservo.attach(12);
    
    Serial.begin(9600);
    Serial.println("Joystick control started");
  
} 

void loop() {
    joy1btn = digitalRead(pin1btn);
    joy2btn = digitalRead(pin2btn);

    if (joy1btn == LOW)
      {
        for (angle=token; angle<=165 && (digitalRead(pin1btn)) == LOW && (digitalRead(pin2btn)) == HIGH; angle++)
        {
          servoPulse(servoPin, angle);
          Serial.print(angle); Serial.println("HOLD");
          token = angle;
          //delay(20);
        }
      }

      if (joy2btn == LOW)
      {
        for (angle=token; angle>=28 && (digitalRead(pin2btn)) == LOW && (digitalRead(pin1btn)) == HIGH; angle--)
        {
          servoPulse(servoPin, angle);
          Serial.print(angle); Serial.println("RELEASE");
          token = angle;
          //delay(20);
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
