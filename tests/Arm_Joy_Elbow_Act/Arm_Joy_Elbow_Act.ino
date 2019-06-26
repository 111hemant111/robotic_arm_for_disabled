/////JOYSTICKS' PINS/////
int pin1x = 0;
int pin2x = 1;
int pin1y = 2;
int pin2y = 3;
int pin1btn = 18;
int pin2btn = 19;

/////JOYSTICKS' VARIABLES/////
int joy1x = 0;
int joy2x = 0;
int joy1y = 0;
int joy2y = 0;
int joy1btn = 0;
int joy2btn = 0;

/////ELBOW MOTOR PINS/////
int pwmElbow = 3;
int dirElbow = 6;
int i;

/////LINEAR ACTUATOR PINS/////
int pwmLin = 11;
int dirLin = 7;
int k;

void setup() 
  { 
    pinMode(pwmElbow, OUTPUT);
    pinMode(dirElbow, OUTPUT);

    pinMode(pwmLin, OUTPUT);
    pinMode(dirLin, OUTPUT);

    pinMode(pin1btn, INPUT);
    pinMode(pin2btn, INPUT);
  
    Serial.begin(9600);
    Serial.println("Joystick control started");
  }

void loop() 
  {
    joy2x = analogRead(pin2x); //495
    joy2y = analogRead(pin2y); //507
    Serial.print(joy2x);
    Serial.print("  ");
    Serial.println(joy2y);
    //joy1btn = digitalRead(pin1btn);
    //joy2btn = digitalRead(pin2btn);

    if (joy2x > 505)
      {
        digitalWrite(dirElbow, LOW);
        joy2x = map(joy2x, 527, 1023, 0, 255);
        analogWrite(pwmElbow, joy2x);
      }

    else if (joy2x < 485)
      {
        digitalWrite(dirElbow, HIGH);
        joy2x = map(joy2x, 0, 510, 255, 0);
        analogWrite(pwmElbow, joy2x);
      }

    else
      {
        analogWrite(pwmElbow, 0);
      }

      if (joy2y > 517)
      {
        digitalWrite(dirLin, HIGH);
        joy2y = map(joy2y, 540, 1023, 0, 255);
        analogWrite(pwmLin, joy2y);
      }

    else if (joy2y < 497)
      {
        digitalWrite(dirLin, LOW);
        joy2y = map(joy2y, 0, 520, 255, 0);
        analogWrite(pwmLin, joy2y);
      }

    else
      {
        analogWrite(pwmLin, 0);
      }
      
    //Serial.print(joy2x); Serial.print("  "); Serial.println(joy2y);
    
    //Serial.print(joy1x); Serial.print("  "); Serial.println(joy1y);
    //Serial.print(joy2x); Serial.print("  "); Serial.println(joy2y);
    //Serial.println(joy2btn);
    delay(100);
  }


