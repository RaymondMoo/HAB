#include "SoftwareSerial.h"

#include <Servo.h>
Servo cutDown;

#define inputPin 1
#define outputPin 2
SoftwareSerial XBee(inputPin, outputPin)

int failsafe = 0;


bool checkXBeeDrop() {
  byte input = XBee.read();
  /*Input depends on how we are structuring the input byte 
    Are we sending the altitude data and doing the logic here?
    Are we sending just a signal from our main board to cut down?
   
  */
  
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
    if (failsafe > 3){
      //Action to Drop 
    }
  }
}
