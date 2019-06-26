
int pwmElbow = 3;
int dirElbow = 6;
int i;

void setup() 
{
  pinMode(pwmElbow, OUTPUT);
  pinMode(dirElbow, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{ 

 lowerElbowAcc();
 delay(1300);
 lowerElbowDec();
 delay(1300);
 raiseElbowAcc();
 delay(1300);
 raiseElbowDec();
 delay(1300);
   
}



void lowerElbowAcc()
{
   //Elbow Accelerates LOW
  digitalWrite(dirElbow, LOW);
  for (int i = 0; i<255; i+=3)
  {
    analogWrite(pwmElbow, i);
    delay(5);
    Serial.println(i);
  }
}

void lowerElbowDec()
{
  //Elbow decelerates LOW
   digitalWrite(dirElbow, LOW);
   for (int i = 255; i>0; i-=3)
  {
    analogWrite(pwmElbow, i);
    delay(5);
    Serial.println(i);
  }
}

void raiseElbowAcc()
{
    //Elbow Accelerates HIGH
  digitalWrite(dirElbow, HIGH);
  for (int i = 0; i<255; i+=3)
  {
    analogWrite(pwmElbow, i);
    delay(5);
    Serial.println(i);
  }
}

void raiseElbowDec()
{
     //Elbow decelerates HIGH
   digitalWrite(dirElbow, HIGH);
   for (int i = 255; i>0; i-=3)
  {
    analogWrite(pwmElbow, i);
    delay(5);
    Serial.println(i);
  }
}

