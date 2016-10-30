int DIRECTIONA = 4;
int MOTORA = 5;
int DIRECTIONB = 7;
int MOTORB = 6;
int sensor = A2;

long sensorVoltage;
long inches;
long cm;
int sum = 0;                            // Sum variable, used for averaging sensor's readings.
int avgRange = 10;                // Number of values to average.

void setup ()
{
     pinMode(MOTORA, OUTPUT);
     pinMode(DIRECTIONA, OUTPUT);
     pinMode(MOTORB, OUTPUT);
     pinMode(DIRECTIONB, OUTPUT);
     pinMode(sensor, INPUT);
}

void loop ()
{
     // Averaging sensor's readings.
     for(int readingNo = 0; readingNo < avgRange ; readingNo++)
     {
          // Used to read the analog voltage output that is being sent by the MaxSonar device.
          // Scale factor is (VCC/512) per inch. A 5V supply yields ~9.8mV/in.
          // Arduino analog pin goes from 0 to 1024, so value has to be divided by 2 to get actual inches.
          sensorVoltage = analogRead(sensor) / 2;
          sum += sensorVoltage; delay(2);
     }
     inches = sum/avgRange;
     cm = inches * 2.54;

     if (cm < 30)
          moveRight();
     else
          moveForward();

     sum = 0;
}

unsigned long startTime;
int timeToGo;

void moveRight()
{
     analogWrite(MOTORA, 140);
​     analogWrite(MOTORB, 140);
​     digitalWrite(DIRECTIONA, 0);
​     digitalWrite(DIRECTIONB, 1);
​     timeToGo = 400;

​     startTime = millis();
​     // Doing something what was defined previously, until timeout.
​     // Check current drain (consumption).
​     while (millis() - startTime < timeToGo)
​     {
​     ​     // If current is too high.
​     ​     if (analogRead(A0) > 325) // > 1.46 amps
​     ​     ​     break;
​     }
​     analogWrite(MOTORA, 0);
​     analogWrite(MOTORB, 0);
}

void moveForward()
{
     analogWrite(MOTORA, 120);
     analogWrite(MOTORB, 120);
     digitalWrite(DIRECTIONA, 1);
     digitalWrite(DIRECTIONB, 1);
     timeToGo = 300;

     startTime = millis();
     // Doing something what was defined previously, until timeout.
     // Check current drain (consumption).
     while (millis() - startTime < timeToGo)
     {
          // If current is too high.
          if (analogRead(A0) > 325) // > 1.46 amps break;
     }
     
     analogWrite(MOTORA, 0);
     analogWrite(MOTORB, 0);
}