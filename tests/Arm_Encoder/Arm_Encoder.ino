int pwmBase = 9;
int dirBase = 8;
int k;

void setup() 
{
  pinMode(2, INPUT);
  pinMode(7, INPUT);
  pinMode(pwmBase, OUTPUT);
  pinMode(dirBase, OUTPUT);
  Serial.begin(9600);

}


void loop() 
{
  clockBaseAcc();
  digitalWrite(dirBase, LOW);
  digitalWrite(pwmBase, HIGH);

  while(1)
  {
    Serial.println(digitalRead(2));
    Serial.println(digitalRead(7));
  }
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
