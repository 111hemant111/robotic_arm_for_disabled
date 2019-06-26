int pwm = 10;
int dir = 11;
int linLimit = 15000; // Linear actuator's full time to reach limit is 15.5 seconds

void setup() 
{
  pinMode(pwm, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  digitalWrite(dir, LOW);
  analogWrite(pwm, 255);
  delay(linLimit+2000);
  while(10)
  {
    digitalWrite(pwm, LOW);
    Serial.println(analogRead(1));
  }

}
