
volatile int pwm_value = 0;
volatile int prev_time = 0;
volatile int y = 0;
volatile int p=0;
volatile int prev_y=0;
volatile int new_y=0;
volatile int token =0;

int pwmShould = 5;
int dirShould = 9;
int j;

int pwmElbow = 3;
int dirElbow = 6;
int i;

void setup() 
{
  pinMode(pwmShould, OUTPUT);
  pinMode(dirShould, OUTPUT);

  pinMode(pwmElbow, OUTPUT);
  pinMode(dirElbow, OUTPUT);
  
  Serial.begin(115200);
  //pinMode(5,OUTPUT);
  // when pin D2 goes high, call the rising function
  attachInterrupt(0, rising, RISING);

  digitalWrite(dirElbow, LOW);
}


void loop() 
{ 

 lowerShouldAcc();
 delay(800);
 
 delay(1000);
 
 lowerShouldDec();
 delay(800);
 raiseShouldAcc();
 delay(800);
 
 delay(1000);
 
 raiseShouldDec();
 delay(800);
   
}


void lowerShouldAcc()
{
   //Should Accelerates LOW
  digitalWrite(dirShould, LOW);
  for (int j = 0; j<255; j+=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    //Serial.println(j);
  }
}

void lowerShouldDec()
{
  //Should decelerates LOW
   digitalWrite(dirShould, LOW);
   for (int j = 255; j>0; j-=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    //Serial.println(j);
  }
}

void raiseShouldAcc()
{
    //Should Accelerates HIGH
  digitalWrite(dirShould, HIGH);
  for (int j = 0; j<255; j+=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    //Serial.println(j);
  }
}

void raiseShouldDec()
{
     //Should decelerates HIGH
   digitalWrite(dirShould, HIGH);
   for (int j = 255; j>0; j-=3)
  {
    analogWrite(pwmShould, j);
    delay(5);
    //Serial.println(j);
  }
}


////////////INTERRUPT FALL AND RISE/////////////
////////////////////////////////////////////////
void rising() {
  attachInterrupt(0, falling, FALLING);
  prev_time = micros();
}
 
void falling() {
  attachInterrupt(0, rising, RISING);
  pwm_value = micros()-prev_time;
  new_y = map(pwm_value,40,1800,0,255);
  
//  while (token = 0)
//  {
//    prev_y = new_y;
//  }
//  token = 1;
//  
  for (p =0;p<1;p++)
  {
    if (new_y<(prev_y-10)||new_y>(prev_y+10))
    { 
      delayMicroseconds(10);
      //analogWrite(pwmElbow,prev_y);
      //Serial.println(prev_y);  
  }
  
  analogWrite(pwmElbow, prev_y);
  prev_y=new_y;
  Serial.println(prev_y);




    
//    if (new_y<(prev_y-10)||new_y>(prev_y+10))
//    {
//      analogWrite(pwmElbow,prev_y);
//      Serial.println(prev_y);
//      prev_y=new_y;
//  }
//    else
//    {
//      analogWrite(pwmElbow,new_y);
//      //Serial.println(new_y);
//      prev_y=new_y;
//    }
//  
//    if(new_y>prev_y)
//    {
//      analogWrite(pwmElbow, prev_y);
//      Serial.println(prev_y);
//    }
//    else if (prev_y>new_y)
//    {
//      analogWrite(pwmElbow, new_y);
//      Serial.println(new_y);
//    }
  }

//  analogWrite(pwmElbow, y);
//  Serial.println(y);
}


