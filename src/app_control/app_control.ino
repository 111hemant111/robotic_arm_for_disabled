/////PWM READS/////
byte pinAppShould = 2;
byte pinAppElbow = 12;
byte pinAppBase = 8;
byte pinAppLin = 13;

/////SHOULDER VARIABLES/////
int pwmAppShould = 0;
int mapShould = 0;
int oldShould = 0;

/////ELBOW VARIABLES/////
int pwmAppElbow = 0;
int mapElbow = 0;
int oldElbow = 0;

/////BASE VARIABLES/////
int pwmAppBase = 0;
int mapBase = 0;
int oldBase = 0;

/////LINEAR ACTUATOR VARIABLES/////
int pwmAppLin = 0;
int mapLin = 0;
int oldLin = 0;

/////ELBOW MOTOR PINS/////
int pwmElbow = 3;
int dirElbow = 6;
int i;

/////LINEAR ACTUATOR PINS/////
int pwmLin = 11;
int dirLin = 7;
int l;

/////SHOULDER MOTOR PINS/////
int pwmShould = 5;
int dirShould = 9;
int j;

/////BASE MOTOR PINS/////
int pwmBase = 10;
int dirBase = 4;
int k;

void setup() 
{ 
  pinMode(pwmElbow, OUTPUT);
  pinMode(dirElbow, OUTPUT);

  pinMode(pwmLin, OUTPUT);
  pinMode(dirLin, OUTPUT);

  pinMode(pwmShould, OUTPUT);
  pinMode(dirShould, OUTPUT);

  pinMode(pwmBase, OUTPUT);
  pinMode(dirBase, OUTPUT);


  pinMode(pin1btn, INPUT);
  pinMode(pin2btn, INPUT);

  pinMode(pinAppShould, INPUT);
  pinMode(pinAppElbow, INPUT);
  pinMode(pinAppLin, INPUT);
  pinMode(pinAppBase, INPUT);
  
  Serial.begin(115200);
  Serial.println("Program started");
}


void loop() 
{ 
 pwmAppShould = pulseIn(pinAppShould, HIGH);
 pwmAppElbow = pulseIn(pinAppElbow, HIGH);
 pwmAppBase = pulseIn(pinAppBase, HIGH);
 pwmAppLin = pulseIn(pinAppLin, HIGH);

    /////////////////////////////////////////////////////////
    ////////// APP JOYSTICK 1 - Y AXIS - SHOULDER ///////////
    /////////////////////////////////////////////////////////

  if ((pwmAppShould < (oldShould + 200) && pwmAppShould > (oldShould - 200)) || oldShould == 0)
    {
      if (pwmAppShould > 1100)
      {
        digitalWrite(dirShould, LOW);
        Serial.print(pwmAppShould); Serial.print(" Greater "); Serial.print(oldShould); Serial.println(" Part 1");
        mapShould = map(pwmAppShould, 1100, 1800, 0, 35);
        analogWrite(pwmShould, mapShould);
      }

    else if (pwmAppShould < 700)
      {
        digitalWrite(dirShould, HIGH);
        Serial.print(pwmAppShould); Serial.print(" Lower "); Serial.print(oldShould); Serial.println(" Part 2");
        mapShould = map(pwmAppShould, 0, 700, 50, 0);
        analogWrite(pwmShould, mapShould);
      }

    else
      {
        analogWrite(pwmShould, 0);
        Serial.print(pwmAppShould); Serial.print(" Middle "); Serial.print(oldShould); Serial.println(" Part 3");
      }
      oldShould = pwmAppShould;
    }

      else
      {
      Serial.print(pwmAppShould); Serial.println(" Random");
      oldShould = pwmAppShould;
      }
      
    /////////////////////////////////////////////////////
    ////////// APP JOYSTICK 1 - X AXIS - BASE ///////////
    /////////////////////////////////////////////////////

  if ((pwmAppBase < (oldBase + 200) && pwmAppBase > (oldBase - 200)) || oldBase == 0)
    {
      if (pwmAppBase > 1100)
      {
        digitalWrite(dirBase, HIGH);
        mapBase = map(pwmAppBase, 1100, 1800, 0, 70);
        analogWrite(pwmBase, mapBase);
      }

    else if (pwmAppBase < 700)
      {
        digitalWrite(dirBase, LOW);
        mapBase = map(pwmAppBase, 0, 700, 70, 0);
        analogWrite(pwmBase, mapBase);
      }

    else
      {
        analogWrite(pwmBase, 0);
      }

      oldBase = pwmAppBase;
    }

    else 
      {
        oldBase = pwmAppBase;
      }

    //////////////////////////////////////////////////////
    ////////// APP JOYSTICK 2 - Y AXIS - ELBOW ///////////
    //////////////////////////////////////////////////////

  if ((pwmAppElbow < (oldElbow + 200) && pwmAppElbow > (oldElbow - 200)) || oldElbow == 0)
    {
      if (pwmAppElbow > 1350)
      {
        digitalWrite(dirElbow, LOW);
        mapElbow = map(pwmAppElbow, 1350, 1960, 0, 75);
        analogWrite(pwmElbow, mapElbow);
      }

    else if (pwmAppElbow < 650)
      {
        digitalWrite(dirElbow, HIGH);
        mapElbow = map(pwmAppElbow, 0, 650, 90, 0);
        analogWrite(pwmElbow, mapElbow);
      }

    else
      {
        analogWrite(pwmElbow, 0);
      }

    oldElbow = pwmAppElbow;
    }

    else
    {
      oldElbow = pwmAppElbow;
    }
    
    ///////////////////////////////////////////////////////
    ////////// APP JOYSTICK 2 - X AXIS - LINEAR ///////////
    ///////////////////////////////////////////////////////

  if ((pwmAppLin < (oldLin + 300) && pwmAppLin > (oldLin - 300)) || oldLin == 0)
    {
      if (pwmAppLin > 1150)
      {
        digitalWrite(dirLin, LOW);
        //Serial.print(pwmAppLin); Serial.print(" Greater "); Serial.println(oldLin);
        mapLin = map(pwmAppLin, 1150, 1960, 5, 250);
        analogWrite(pwmLin, mapLin);
      }

    else if (pwmAppLin < 850)
      {
        digitalWrite(dirLin, HIGH);
        //Serial.print(pwmAppLin); Serial.print(" Lesser "); Serial.println(oldLin);
        mapLin = map(pwmAppLin, 0, 850, 250, 5);
        analogWrite(pwmLin, mapLin);
      }

    else
      {
        analogWrite(pwmLin, 0);
        //Serial.print(pwmAppLin); Serial.print(" Middle "); Serial.println(oldLin);
      }

      oldLin = pwmAppLin;
    }

    else
      {
        oldLin = pwmAppLin;
      }

}
