#include<dmoto.h>
dmoto RodeoBt;
char alinan;
void setup() {
  Serial.begin(9600);
  RodeoBt.pinSet();
}
void loop() {
//  alinan = '0';
  if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    alinan = Serial.read(); // Reads the0 data from the serial port
  }
  delay(10);

  if (alinan == 'F' )
  {
    RodeoBt.Forward(150);
  }
  if (alinan == 'B' )
  {
    RodeoBt.Backward(150);
  }
  if (alinan == 'R' )
  {
    RodeoBt.Right(120, 60);
  }
  if (alinan == 'L' )
  {
    RodeoBt.Left(60, 120);
  }
  if (alinan == 'G' )
  {
    RodeoBt.Left(60, 190);
  }
  if (alinan == 'I' )
  {
    RodeoBt.Right(190, 60);
  }
  if (alinan == 'H' )
  {
    RodeoBt.BackLeft(60, 150);
  }
  if (alinan == 'J' )
  {
    RodeoBt.BackRight(150, 60);
  }
  if (alinan == 'S' )
  {
    RodeoBt.Stop();
  }
  if (alinan == 'V' )
  {
    digitalWrite(buzzerPin, HIGH);
  }
  if (alinan == 'v' )
  {
    digitalWrite(buzzerPin, LOW);
  }
  if (alinan == 'W' )
  {
    digitalWrite(ledPin, HIGH);
  }
  if (alinan == 'w' )
  {
    digitalWrite(ledPin, LOW);
  }
}
