#include <CoDrone.h>

void setup() {
  // put your setup code here, to run once:
CoDrone.begin(115200);
byte droneAddress[6] = {0x7D, 0xA3, 0x61, 0x78, 0xD5, 0xA4};
CoDrone.AutoConnect(AddressInputDrone, droneAddress);
CoDrone.LedColor(ArmDimming, 232, 248, 30, 7);
}

void loop() {
  // put your main code here, to run repeatedly:
byte sensor1 = digitalRead(11);
byte sensor2 = digitalRead(14);
byte sensor3 = digitalRead(18);
if(sensor1 == 1){
  CoDrone.FlightEvent(Stop);
}
else if(sensor3 == 1){
  CoDrone.FlightEvent(TakeOff);
}
else if(sensor2 == 1){
  CoDrone.FlightEvent(Landing);
}
}
