#include <dmoto.h>
dmoto obstacle;

void setup() 
{
  Serial.begin(9600);

  obstacle.pinSet();
  obstacle.Stop();
}

void loop() {
  Serial.println(obstacle.distance());


  if (obstacle.distance() < 15)
  {
   obstacle.Backward(150);
    delay(150);
  obstacle.Right(150,150);
    delay(250);
  }
  else
  { obstacle.Forward(150);
  }

}
