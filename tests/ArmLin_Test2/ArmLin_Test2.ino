int pwmLin = 11;
int dirLin = 7;
int linLimit = 15000; // Linear actuator's full time to reach limit is 15.5 seconds

void setup() 
{
  pinMode(pwmLin, OUTPUT);
  pinMode(dirLin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  digitalWrite(dirLin, HIGH);
  analogWrite(pwmLin, 255);
  delay(linLimit+2000);
  while(1)
  {
    digitalWrite(pwmLin, LOW);
    Serial.println(analogRead(1));
  }

}
