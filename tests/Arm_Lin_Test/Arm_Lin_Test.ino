//LINEAR ACTUATOR
  int LinPin = 5; //Pin
  int val = 525; //Value for no movement

void setup() {
  // put your setup code here, to run once:
    analogWrite(LinPin, val/4); //Start with linear actuator stopped

    //LINEAR ACTUATOR
    pinMode(LinPin,OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   // Raise linear actuator halfway
            linearUp();

}

void linearUp()
  {
    val = 880;
    analogWrite(LinPin, val/4);
    Serial.println(val);
    delay(1500);
    val = 525;
    analogWrite(LinPin, val/4);
    Serial.println(val);
  }
  
void linearDown()
  {
    val = 200;
    analogWrite(LinPin, val/4);
    Serial.println(val);
    delay(1500);
    val = 525;
    analogWrite(LinPin, val/4);
    Serial.println(val); 
  }
