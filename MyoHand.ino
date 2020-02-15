#include <MyoController.h>
#include <FingerLib.h>

Finger Pinky;
Finger Ring;
Finger Middle;
Finger Index;
Finger Thumb;

int Status;
int SavedStatus;
String LastPosition;
long PreviousTime;
bool ReintTimer=0; 
const int DeltaTime =5000; 

MyoController myo = MyoController();
void setup() 
{ 
  Serial.begin(9600);
  Index.attach(3,6,A1);//OK
  Thumb.attach(13,4,A5);//OK
  Middle.attach(7,8,A2);//OK
  Ring.attach(10,9,A3);//Ok
  Pinky.attach(11,12,A4);//OK
  
  Status=1;
  SavedStatus=1;
  LastPosition="";
  PreviousTime=0;
  
} 

void loop() 
{ 
  myo.updatePose();
  if (LastPosition==String(myo.getCurrentPose())&&Status!=10)
  {
    switch ( myo.getCurrentPose() ) {
        case fingersSpread:
          ReintTimer=0;
          break;
        case fist:
          ReintTimer=0;
          break;
        default:
          ReintTimer=1;
        break;
    }
    if (ReintTimer==0)
    {
      if(millis()-PreviousTime>DeltaTime){//keep position
           Status=10; 
      }
      else {
          //continue to count;
      }
    }
    else
    {
      PreviousTime=millis();
    }   
  }
  else if (Status==1)
  {
    SavedStatus=1;
    PreviousTime=millis();
    LastPosition=myo.getCurrentPose();
    switch ( myo.getCurrentPose() ) {
    case rest:
      ResetPosition();
      break;
    case fist:
      Fist();
      Serial.print("Correct");
      break;
    case waveIn:
      Status=2;
      delay(500);
      break;
    case waveOut:
      Status=4;
      delay(500);
      break;
    case fingersSpread:
      Rock();
      break;
    case doubleTap:
      Status=10;
      SavedStatus=1;
      ResetPosition();
      delay(500);
      break;
    default:
    //keep the position
    break; 
    }      
  }
  else if (Status==2)
  {
    SavedStatus=2;
    PreviousTime=millis();
    LastPosition=myo.getCurrentPose();
    switch ( myo.getCurrentPose() ) {
    case rest:
      ResetPosition();
      break;
    case fist:
      graspTripod();
      break;
    case waveIn:
      Status=3;
      delay(500);
      break;
    case waveOut:
      Status=1;
      delay(500);
      break;
    case fingersSpread:
      graspTip();
      break;
    case doubleTap:
      Status=10;
      SavedStatus=2;
      ResetPosition();
      delay(500);
      break;
    default:
    //keep the position
    break;
    }
  }
  else if (Status==3)
  {
    SavedStatus=3;    
    PreviousTime=millis();
    LastPosition=myo.getCurrentPose();
    switch ( myo.getCurrentPose() ) {
    case rest:
      ResetPosition();
      break;
    case fist:
      graspCylindrical();
      break;
    case waveIn:
      Status=4;
      delay(500);
      break;
    case waveOut:
      Status=2;
      delay(500);
      break;
    case fingersSpread:
      graspSpherical();
      break;
    case doubleTap:
      Status=10;
      SavedStatus=3;
      ResetPosition();
      delay(500);
      break;
    default:
    //keep the position
    break;
    }
  } 
  else if (Status==4)
  {
    SavedStatus=4;    
    PreviousTime=millis();
    LastPosition=myo.getCurrentPose();
    switch ( myo.getCurrentPose() ) {
    case rest:
      ResetPosition();
      break;
    case fist:
      Point();
      break;
    case waveIn:
      Status=1;
      delay(500);
      break;
    case waveOut:
      Status=3;
      delay(500);
      break;
    case fingersSpread:
      Peace();
      break;
    case doubleTap:
      Status=10;
      SavedStatus=4;
      ResetPosition();
      delay(500);
      break;
    default:
    //keep the position
    break;
    }
  } 
  else if (Status==10)
  {
    myo.updatePose();
    switch ( myo.getCurrentPose() ) {
      case doubleTap:
        Status=SavedStatus;
        delay(500);
      default:
        //
      break;
      }    
    delay(10);
  }
}   
//List of positions
void Rock() {
  Pinky.open();
  Ring.close();
  Middle.close();
  Index.open();
  Thumb.open();
}
void graspCylindrical(){
  Pinky.writePos(800);
  Ring.writePos(800);
  Middle.writePos(800);
  Index.writePos(800);
  Thumb.writePos(900);        
}
void Fist() {
  Pinky.close();
  Ring.close();
  Middle.close();
  Index.close();
  Thumb.close();
}
void graspSpherical() {
  Pinky.writePos(600);
  Ring.writePos(600);
  Middle.writePos(600);
  Index.writePos(600);
  Thumb.close(); 
}
void graspTripod() {
  Pinky.open();
  Ring.open();
  Middle.writePos(800);
  Index.writePos(800);
  Thumb.writePos(800);
}
void graspTip() {
  Pinky.open();
  Ring.open();
  Middle.open();
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
void Point() {
  Pinky.close();
  Ring.close();
  Middle.close();
  Index.open();
  Thumb.close();
}
void Peace() {
  Pinky.close();
  Ring.close();
  Middle.open();
  Index.open();
  Thumb.close();
}
