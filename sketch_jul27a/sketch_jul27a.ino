#include <CoDrone.h>







//        16. Go left (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        17. Land

void setup(){
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x7D,0xA3, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}
void loop(){
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if(left == 1){
     CoDrone.FlightEvent(Stop);
  }
  else if(right == 1){
    CoDrone.FlightEvent(TakeOff);
    THROTTLE = 100;
    CoDrone.Control();
    delay(3000);
//    PITCH = 50;
//    THROTTLE = 20;
//    CoDrone.Control();
//    delay(1000);
//    ROLL = 80;
//    THROTTLE = 20;
//    CoDrone.Control();
//    delay(1000);
//    PITCH = -80;
//    THROTTLE = 20;
//    CoDrone.Control();
//    delay(1000);
//    ROLL = -80;
//    THROTTLE = 20;
//    CoDrone.Control();
//    delay(1000);
CoDrone.FlightEvent(Landing);
  }
  else if(middle == 1){
    CoDrone.FlightEvent(Landing);
  }
  
}

