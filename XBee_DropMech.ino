#include "SoftwareSerial.h"

#include <Servo.h>
Servo cutDown;

#define inputPin 1
#define outputPin 2
SoftwareSerial XBee(inputPin, outputPin)

int failsafe = 0;
int maxAltitude = 2000; //In Meters

bool checkXBeeDrop() {
  byte input = XBee.read();
  /*Input depends on how we are structuring the input byte 
    Are we sending the altitude data and doing the logic here?
    Are we sending just a signal from our main board to cut down?
   
  */

  return False;
}



void setup() {
  Serial.begin(9600);
  XBee.begin(9600);
  
}


void loop() {
  if (Xbee.available() > 0){
    if(checkXBeeDrop()) {
      failsafe++;
    }
  }
  else {
    int altitude = (int)altimeterData.heightMeters1; //Unsure of how XBee altitude data is retrieved
    if (altitude > maxAltitude){
      failsafe++;
    }
  }
  if (failsafe > 3){
      //Action to Drop 
    }
}
