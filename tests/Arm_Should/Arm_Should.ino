
int pwmShould = 5;
int dirShould = 9;
int j;


void setup() 
{
  pinMode(pwmShould, OUTPUT);
  pinMode(dirShould, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{ 

 lowerShouldAcc();
 delay(800);
 
 delay(3000);
 
 lowerShouldDec();
 delay(800);
 raiseShouldAcc();
 delay(800);
 
 delay(3000);
 
 raiseShouldDec();
 delay(800);
   
}

///////Shoulder Accelerates LOW////////
///////////////////////////////////////
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

///////Shoulder Decelerates LOW////////
///////////////////////////////////////
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

///////Shoulder Accelerates HIGH///////
///////////////////////////////////////
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

///////Shoulder Decelerates HIGH///////
///////////////////////////////////////
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

