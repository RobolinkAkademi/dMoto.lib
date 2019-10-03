#include <dmoto.h>
dmoto Light;
float ldrRemove =0;
void setup() {
  Serial.begin(9600);
  Light.pinSet();
  Light.Stop();
}

void loop() {
  ldrRemove = abs(Light.LdrRightValue() - Light.LdrLeftValue());
  Serial.print(Light.LdrRightValue());
  Serial.print("  ");
  Serial.print(Light.LdrLeftValue());
  Serial.print("  ");
  Serial.println(ldrRemove);
  delay(30);
  if (Light.LdrRightValue() > Light.LdrLeftValue() && ldrRemove > 80)
  {
    Light.Left(150,70); // aa

  }
  if (Light.LdrRightValue() < Light.LdrLeftValue() && ldrRemove > 80)
  {
    Light.Right(70,150);

  }
  if (ldrRemove < 80)
  {
    Light.Forward(150);

  }


}
