
/////////////Joystick controlled Robotic arm//////////////
/////////Developed by Hemant Kuruva - 15 May 2018/////////

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
int l;

/////SHOULDER MOTOR PINS/////
int pwmShould = 5;
int dirShould = 9;
int j;

/////BASE MOTOR PINS/////
int pwmBase = 10;
int dirBase = 4;
int k;


void setup() 
  { 
    pinMode(pwmElbow, OUTPUT);
    pinMode(dirElbow, OUTPUT);

    pinMode(pwmLin, OUTPUT);
    pinMode(dirLin, OUTPUT);

    pinMode(pwmShould, OUTPUT);
    pinMode(dirShould, OUTPUT);

    pinMode(pwmBase, OUTPUT);
    pinMode(dirBase, OUTPUT);


    pinMode(pin1btn, INPUT);
    pinMode(pin2btn, INPUT);

    //pinMode(servoPin, OUTPUT);

    //myservo.attach(12);
    
    Serial.begin(9600);
    Serial.println("Joystick control started");
  }

void loop() 
  {
    joy2x = analogRead(pin2x); //495
    joy2y = analogRead(pin2y); //507
    joy1x = analogRead(pin1x);
    joy1y = analogRead(pin1y);
    joy1btn = digitalRead(pin1btn);
    joy2btn = digitalRead(pin2btn);

////////// JOYSTICK 1 - Y AXIS ///////////
    if (joy1y > 527)
      {
        digitalWrite(dirShould, LOW);
        joy1y = map(joy1y, 527, 1023, 0, 100);
        analogWrite(pwmShould, joy1y);
      }

    else if (joy1y < 510)
      {
        digitalWrite(dirShould, HIGH);
        joy1y = map(joy1y, 0, 510, 120, 0);
        analogWrite(pwmShould, joy1y);
      }

    else
      {
        analogWrite(pwmShould, 0);
      }

////////// JOYSTICK 1 - X AXIS ///////////
      if (joy1x > 530)
      {
        digitalWrite(dirBase, HIGH);
        joy1x = map(joy1x, 530, 1023, 0, 180);
        analogWrite(pwmBase, joy1x);
      }

    else if (joy1x < 510)
      {
        digitalWrite(dirBase, LOW);
        joy1x = map(joy1x, 0, 510, 180, 0);
        analogWrite(pwmBase, joy1x);
      }

    else
      {
        analogWrite(pwmBase, 0);
      }

////////// JOYSTICK 2 - Y AXIS ///////////
    if (joy2y > 505)
      {
        digitalWrite(dirElbow, LOW);
        joy2y = map(joy2y, 505, 1023, 0, 200);
        analogWrite(pwmElbow, joy2y);
      }

    else if (joy2y < 485)
      {
        digitalWrite(dirElbow, HIGH);
        joy2y = map(joy2y, 0, 485, 200, 0);
        analogWrite(pwmElbow, joy2y);
      }

    else
      {
        analogWrite(pwmElbow, 0);
      }

////////// JOYSTICK 2 - X AXIS ///////////
      if (joy2x > 510)
      {
        digitalWrite(dirLin, LOW);
        joy2x = map(joy2x, 510, 1023, 0, 255);
        analogWrite(pwmLin, joy2x);
      }

    else if (joy2x < 490)
      {
        digitalWrite(dirLin, HIGH);
        joy2x = map(joy2x, 0, 490, 255, 0);
        analogWrite(pwmLin, joy2x);
      }

    else
      {
        analogWrite(pwmLin, 0);
      }
      char k="hjlh hgb";
  }


