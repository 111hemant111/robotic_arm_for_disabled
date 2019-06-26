int pin1x = 0;
int pin2x = 1;
int pin1y = 2;
int pin2y = 3;
int pin1btn = 18;
int pin2btn = 19;

int joy1x = 0;
int joy2x = 0;
int joy1y = 0;
int joy2y = 0;
int joy1btn = 0;
int joy2btn = 0;


void setup() 
  { 
    pinMode(pin1btn, INPUT);
    pinMode(pin2btn, INPUT);
    
    Serial.begin(9600);
    Serial.println("Joystick control started");
  }

void loop() 
  {
    joy1x = analogRead(pin1x);
    joy1y = analogRead(pin1y);
    joy2x = analogRead(pin2x);
    joy2y = analogRead(pin2y);
    joy1btn = digitalRead(pin1btn);
    joy2btn = digitalRead(pin2btn);
    Serial.print(joy1x); Serial.print("  "); Serial.println(joy1y);
    //Serial.print(joy2x); Serial.print("  "); Serial.println(joy2y);
    //Serial.println(joy2btn); 
    delay(100);
  }
