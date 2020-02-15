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
/* 
 fist();
 delay(2000);
 Rock();
 delay(2000);
 Peace();
 delay(2000);
 graspTip();
 delay(2000);
 graspTripod();
 delay(2000);
 */
 ResetPosition();
 delay(1000);
 Test();
 delay(4000);
}

void fist() {
  Pinky.close();
  Ring.close();
  Middle.close();
  Index.close();
  Thumb.close();
}

void Rock() {
  Pinky.open();
  Ring.close();
  Middle.close();
  Index.open();
  Thumb.open();
}

void Peace() {
  Pinky.close();
  Ring.close();
  Middle.open();
  Index.open();
  Thumb.close();
}

void graspTip() {
  Pinky.open();
  Ring.open();
  Middle.open();
  Index.writePos(800);
  Thumb.writePos(800);
}

void graspTripod() {
  Pinky.open();
  Ring.open();
  Middle.writePos(800);
  Index.writePos(800);
  Thumb.writePos(800);
}

void ResetPosition() {   
  Pinky.open();
  Ring.open();
  Middle.open();
  Index.open();
  Thumb.open();  
}

void Test() {
  Pinky.close();
  Ring.close();
  Middle.close();
  Index.writePos(200);
  Thumb.close();
}
