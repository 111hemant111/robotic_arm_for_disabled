void setup() 
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  
}
