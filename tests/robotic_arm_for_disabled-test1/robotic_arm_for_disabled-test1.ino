  
  //SHOULDER PINS (TB6600 Motor Driver)
  int PUL=11; //define Pulse pin
  int DIR=12; //define Direction pin
  int ENA=13; //define Enable Pin

  int stepVal = 5000;

void setup() {
  pinMode(PUL,OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(ENA,OUTPUT);
  Serial.begin(9600);
  Serial.println("Motor starts");
}

void loop() 
  { 
    delay(2000);
    
    Serial.println("Rotate Forward");
    forwardStep_SHOUL();
    delay(2000);
    
    Serial.println("Rotate Backward");
    backwardStep_SHOUL();
    delay(2000);
  }

// SHOULDER MOTOR SUBROUTINES
void forwardStep_SHOUL()
  {
    for (int i=0; i<800; i++) //Forward 800 steps
      {
        digitalWrite(DIR,LOW);
        digitalWrite(ENA,HIGH);
        digitalWrite(PUL,HIGH);
        delayMicroseconds(stepVal);
        digitalWrite(PUL,LOW);
        delayMicroseconds(stepVal);
      }
    delay(500);
  }

void backwardStep_SHOUL()
  {
    for (int i=0; i<800; i++) //Backward 800 steps
      {
        digitalWrite(DIR,HIGH);
        digitalWrite(ENA,HIGH);
        digitalWrite(PUL,HIGH);
        delayMicroseconds(stepVal);
        digitalWrite(PUL,LOW);
        delayMicroseconds(stepVal);
      }
    delay(500);
  }
