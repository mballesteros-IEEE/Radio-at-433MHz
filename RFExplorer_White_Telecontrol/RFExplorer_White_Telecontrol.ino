/*
  Example for use library RC-Switch with sniffer of RF Explorer

  Project of RC Switch - https://github.com/sui77/rc-switch
  RF Explorer - www.rf-explorer.com
  Project Sniffer - http://j3.rf-explorer.com/menu-the-news/173-rf-explorer-sniffer-public-beta-available
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(PF_2);
 
  // Optional set number of transmission repetitions.
   mySwitch.setRepeatTransmit(4);
  
}

void loop() {

  /* Send  button A,B,C,D of white telecontrol that is simulated */ 
  mySwitch.sendTriState("FFFFFFFF1000");
  delay(1000);  
  mySwitch.sendTriState("FFFFFFFF0100");
  delay(1000);
  mySwitch.sendTriState("FFFFFFFF0010");
  delay(1000);  
  mySwitch.sendTriState("FFFFFFFF0001");
  delay(1000);

  delay(20000);
}
