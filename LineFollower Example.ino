#include <dmoto.h>

dmoto cizgi;

void setup() {
  Serial.begin(9600);
  cizgi.pinSet();

}

void loop() {

 Serial.print(digitalRead(Sensor1));
 Serial.print(cizgi.sensor2());
 Serial.println(cizgi.sensor3());
 digitalWrite(A5,HIGH);
delay(10);

  if (cizgi.sensor1() == 0 && cizgi.sensor2() == 1 && cizgi.sensor3() == 0)
  {

    cizgi.Forward(80);
  }
  if (cizgi.sensor1() == 1 && cizgi.sensor2() == 1 && cizgi.sensor3() == 1)
  {

 cizgi.Forward(80);
  }
  if (cizgi.sensor1() == 0 && cizgi.sensor2() == 0 && cizgi.sensor3() == 0)
  {

 cizgi.Forward(80);
  }
  if (cizgi.sensor1() == 1 && cizgi.sensor2() == 0 && cizgi.sensor3() == 0)
  {

    cizgi.Right(0,80);
  }
  if (cizgi.sensor1() == 1 && cizgi.sensor2() == 1 && cizgi.sensor3() == 0)
  {

   cizgi.Right(0,80);
  }
       if (cizgi.sensor1() == 0 && cizgi.sensor2() == 0 && cizgi.sensor3() == 1)
  {
    
 cizgi.Left(80,0);
    }
          if (cizgi.sensor1() == 0 && cizgi.sensor2() == 1 && cizgi.sensor3() == 1)
  {
    
 cizgi.Left(80,0);
    }
  
}
