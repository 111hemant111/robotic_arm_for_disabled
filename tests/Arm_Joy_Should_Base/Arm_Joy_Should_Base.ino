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
    pinMode(pwmShould, OUTPUT);
    pinMode(dirShould, OUTPUT);

    pinMode(pwmBase, OUTPUT);
    pinMode(dirBase, OUTPUT);

    pinMode(pin1btn, INPUT);
    pinMode(pin2btn, INPUT);
  
    Serial.begin(9600);
    Serial.println("Joystick control started");
  }

void loop() 
  {
    joy1x = analogRead(pin1x);
    joy1y = analogRead(pin1y);
    //joy2x = analogRead(pin2x);
    //joy2y = analogRead(pin2y);
    //joy1btn = digitalRead(pin1btn);
    //joy2btn = digitalRead(pin2btn);

    if (joy1x > 527)
      {
        digitalWrite(dirShould, LOW);
        joy1x = map(joy1x, 527, 1023, 0, 255);
        analogWrite(pwmShould, joy1x);
      }

    else if (joy1x < 510)
      {
        digitalWrite(dirShould, HIGH);
        joy1x = map(joy1x, 0, 510, 255, 0);
        analogWrite(pwmShould, joy1x);
      }

    else
      {
        analogWrite(pwmShould, 0);
      }

      if (joy1y > 540)
      {
        digitalWrite(dirBase, LOW);
        joy1y = map(joy1y, 540, 1023, 0, 255);
        analogWrite(pwmBase, joy1y);
      }

    else if (joy1y < 520)
      {
        digitalWrite(dirBase, HIGH);
        joy1y = map(joy1y, 0, 520, 255, 0);
        analogWrite(pwmBase, joy1y);
      }

    else
      {
        analogWrite(pwmBase, 0);
      }
      
    Serial.print(joy1x); Serial.print("  "); Serial.println(joy1y);
    
    //Serial.print(joy1x); Serial.print("  "); Serial.println(joy1y);
    //Serial.print(joy2x); Serial.print("  "); Serial.println(joy2y);
    //Serial.println(joy2btn);
    //delay(100);
  }


////////Shoulder Accelerates LOW////////
////////////////////////////////////////
void lowerShouldAcc()
{
  digitalWrite(dirShould, LOW);
  for (int j = 0; j<255; j+=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    Serial.println(j);
  }
}

////////Shoulder Decelerates LOW////////
////////////////////////////////////////
void lowerShouldDec()
{
   digitalWrite(dirShould, LOW);
   for (int j = 255; j>0; j-=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    Serial.println(j);
  }
}

////////Shoulder Accelerates HIGH///////
////////////////////////////////////////
void raiseShouldAcc()
{
  digitalWrite(dirShould, HIGH);
  for (int j = 0; j<255; j+=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    Serial.println(j);
  }
}

////////Shoulder Decelerates HIGH///////
////////////////////////////////////////
void raiseShouldDec()
{
   digitalWrite(dirShould, HIGH);
   for (int j = 255; j>0; j-=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    Serial.println(j);
  }
}

