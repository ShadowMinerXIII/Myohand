#include <FingerLib.h>

Finger Pinky;
Finger Ring;
Finger Middle;
Finger Index;
Finger Thumb;

void setup() {
  Index.attach(3,6,A1);
  Thumb.attach(13,4,A5);
  Middle.attach(7,8,A2);
  Ring.attach(10,9,A3);
  Pinky.attach(11,12,A4);
}

void loop() {
  Ring.open();
  Pinky.open();
  Middle.open();
  Index.open();
  Thumb.open();
  delay(2000);
  Ring.close();
  Pinky.close();
  Middle.close();
  Index.close();
  Thumb.close();
  delay(2000);
}
