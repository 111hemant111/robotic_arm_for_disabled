
int pwmBase = 10;
int dirBase = 4;
int k;

void setup() 
{
  pinMode(pwmBase, OUTPUT);
  pinMode(dirBase, OUTPUT);
  Serial.begin(9600);
}


void loop() 
{ 

 clockBaseAcc();
 delay(800);
 clockBaseDec();
 delay(800);
 counterBaseAcc();
 delay(800);
 counterBaseDec();
 delay(800);
   
}


void clockBaseAcc()
{
   //Base Accelerates LOW
  digitalWrite(dirBase, LOW);
  for (int k = 0; k<255; k+=3)
  {
    analogWrite(pwmBase, k);
    delay(5);
    Serial.println(k);
  }
}

void clockBaseDec()
{
  //Base decelerates LOW
   digitalWrite(dirBase, LOW);
   for (int k = 255; k>0; k-=3)
  {
    analogWrite(pwmBase, k);
    delay(5);
    Serial.println(k);
  }
}

void counterBaseAcc()
{
    //Base Accelerates HIGH
  digitalWrite(dirBase, HIGH);
  for (int k = 0; k<255; k+=3)
  {
    analogWrite(pwmBase, k);
    delay(5);
    Serial.println(k);
  }
}

void counterBaseDec()
{
     //Base decelerates HIGH
   digitalWrite(dirBase, HIGH);
   for (int k = 255; k>0; k-=3)
  {
    analogWrite(pwmBase, k);
    delay(5);
    Serial.println(k);
  }
}

