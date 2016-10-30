int DIRECTIONA = 4;
int MOTORA = 5;
int DIRECTIONB = 7;
int MOTORB = 6;

void setup ()
{
     pinMode(MOTORA, OUTPUT);
     pinMode(DIRECTIONA, OUTPUT);
     pinMode(MOTORB, OUTPUT);
     pinMode(DIRECTIONB, OUTPUT);
}
​
     int phase = 0;
     int timeToGo;
     unsigned long startTime;

void loop ()
{
     ​// Defining speed 120.
     analogWrite(MOTORA, 120);
     analogWrite(MOTORB, 120);

     // Moving to some direction with some speed, which were defined previously, until timeout.
     startTime = millis(); while (millis() - startTime < timeToGo)
     {
          // Check current drain (consumption).
          // If current is too high - break.
          if (analogRead(A0) > 325) // > 1.46 amps
               break;
     }

     // Move forwards.
     if (phase == 0)
     {
          digitalWrite(DIRECTIONA, 1);
          digitalWrite(DIRECTIONB, 1);
          timeToGo = 1500; phase = 1; }

     // Move backwards.
     else if (phase == 1)
     {
          digitalWrite(DIRECTIONA, 0);
          digitalWrite(DIRECTIONB, 0);
          timeToGo = 1500; phase = 2;
     }

     // Move left.
     else if (phase == 2)
     {
          digitalWrite(DIRECTIONA, 1);
          digitalWrite(DIRECTIONB, 0);
          timeToGo = 2200; phase = 3;
     }

     // Move right.
     else
     {
          digitalWrite(DIRECTIONA, 0);
          digitalWrite(DIRECTIONB, 1);
          timeToGo = 2200;
          phase = 0;
     }

     // Defining speed 0.
     analogWrite(MOTORA, 0);
     analogWrite(MOTORB, 0);
}