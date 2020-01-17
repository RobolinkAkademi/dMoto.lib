#include <dmoto.h>
dmoto obstacle;
float obs = 0;
void setup()
{
  Serial.begin(9600);

  obstacle.pinSet();
  obstacle.Stop();
}

void loop() {
  Serial.print("Distance= ");
  Serial.println(obs);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  obs = (duration / 2) / 29.1;
  if (obs < 15)
  {
    obstacle.Backward(150);
    delay(150);
    obstacle.Right(0, 150);
    delay(250);
  }
  else
  { obstacle.Forward(150);
  }
}
