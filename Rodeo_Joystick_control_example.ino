#include <dmoto.h>
RF24 Nrf(9, 10);
dmoto Rodeo;
const byte addresses[][6] = {"00001", "00002"};
int received[11] = {};
float ldrRemove = 0;
int Speed = 0;

void setup() {
  Rodeo.pinSet();
  Nrf.begin();
  Nrf.openWritingPipe(addresses[0]); // 00001
  Nrf.openReadingPipe(1, addresses[1]); // 00002
  Nrf.setPALevel(RF24_PA_MIN);
  Nrf.startListening();
  digitalWrite(ledPin, LOW);
  Rodeo.Stop();
}

void loop() 
{
  Nrf.startListening();
  digitalWrite(ledPin, LOW);
  if (Nrf.available())
  {
    digitalWrite(ledPin, HIGH);
    Nrf.read(&received, sizeof(received));
  }

  if (received[0] == 1)
  {
    LineFollower();
  }

  if (received[1] == 1)
  {
    LightTracer();
  }
  if (received[2] == 1)
  {
    Obstructing();
  }
  if (received[3] == 1 && received[5] == 1)
  {

    Rodeo.Left(70, 150);
  }
  else if (received[3] == 1 && received[6] == 1)
  {
    Rodeo.Right(150, 70);
  }
  else if (received[4] == 1 && received[6] == 1 )
  {
    Rodeo.BackRight(150, 70);

  }
  else if (received[4] == 1 && received[5] == 1 )
  {
    Rodeo.BackLeft(70, 150);
  }
  else if (received[3] == 1)
  {
    Rodeo.Forward(Speed);
  }
  else if (received[4] == 1)
  {
    Rodeo.Backward(Speed);
  }
  else if (received[5] == 1)
  {
    Rodeo.Left(70, 150);
  }
  else if (received[6] == 1)
  {
    Rodeo.Right(150, 70);
  }
  if (received[7] == 1)
  {
    Speed = 250;
  }
  else
    Speed = received[9];

  if (received[8] == 1)
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }

  if (received[0] == 0 && received[1] == 0 && received[2] == 0 && received[3] == 0 && received[4] == 0 && received[5] == 0 && received[6] == 0 )
  {
    Rodeo.Stop();
  }
  delay(10);
}
void LineFollower()
{
  if (Rodeo.sensor1() == 0 && Rodeo.sensor2() == 1 && Rodeo.sensor3() == 0)
  {

    Rodeo.Forward(80);
  }
  if (Rodeo.sensor1() == 1 && Rodeo.sensor2() == 1 && Rodeo.sensor3() == 1)
  {

    Rodeo.Forward(80);
  }
  if (Rodeo.sensor1() == 0 && Rodeo.sensor2() == 0 && Rodeo.sensor3() == 0)
  {

    Rodeo.Forward(80);
  }
  if (Rodeo.sensor1() == 1 && Rodeo.sensor2() == 0 && Rodeo.sensor3() == 0)
  {

    Rodeo.Right(0, 80);
  }
  if (Rodeo.sensor1() == 1 && Rodeo.sensor2() == 1 && Rodeo.sensor3() == 0)
  {

    Rodeo.Right(0, 80);
  }
  if (Rodeo.sensor1() == 0 && Rodeo.sensor2() == 0 && Rodeo.sensor3() == 1)
  {

    Rodeo.Left(80, 0);
  }
  if (Rodeo.sensor1() == 0 && Rodeo.sensor2() == 1 && Rodeo.sensor3() == 1)
  {

    Rodeo.Left(80, 0);
  }

}
void LightTracer()
{
  ldrRemove = abs(Rodeo.LdrRightValue() - Rodeo.LdrLeftValue());

  if (Rodeo.LdrRightValue() > Rodeo.LdrLeftValue() && ldrRemove > 80)
  {
    Rodeo.Left(150, 70);

  }
  if (Rodeo.LdrRightValue() < Rodeo.LdrLeftValue() && ldrRemove > 80)
  {
    Rodeo.Right(70, 150);

  }
  if (ldrRemove < 80)
  {
    Rodeo.Forward(150);

  }
}
void Obstructing()
{
  if (Rodeo.distance() < 15)
  {
    Rodeo.Backward(Speed);
    delay(150);
    Rodeo.Right(0, 150);
    delay(250);
  }
  else
  { Rodeo.Forward(Speed);
  }

}



