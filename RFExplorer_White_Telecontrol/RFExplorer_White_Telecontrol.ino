/*
  Example for use library RC-Switch with sniffer of RF Explorer.
  Project of RC Switch - https://github.com/sui77/rc-switch
  RF Explorer - www.rf-explorer.com
  Project Sniffer - http://j3.rf-explorer.com/menu-the-news/173-rf-explorer-sniffer-public-beta-available
  Simulate a Telecontrol as garage controller. Example in ebay : https://www.ebay.com/itm/2pcs-Wireless-RF-Remote-Control-4-buttons-Telecontrol-433-MHz-Alarm-System-Z83O-/131677445248?_ul=BO
*/

#include <RCSwitch.h>

RCSwitch g_objSwitch = RCSwitch();
int g_nPinLed = 13;  //Select a flash that indicate TX
int g_nPinData = 11; //Transmitter is connected to Arduino Pin #11


void setup() {

  Serial.begin(9600);
  pinMode(g_nPinLed, OUTPUT);   
      
  g_objSwitch.enableTransmit(g_nPinData);
  g_objSwitch.setRepeatTransmit(4);//Set number of transmission repetitions - Optional
  
}

void loop() 
{
  //Send all button A,B,C,D of white telecontrol that is simulated
  digitalWrite(g_nPinLed, HIGH); 
  g_objSwitch.sendTriState("FFFFFFFF1000");
  delay(1000);  
  g_objSwitch.sendTriState("FFFFFFFF0100");
  delay(1000);
  g_objSwitch.sendTriState("FFFFFFFF0010");
  delay(1000);  
  g_objSwitch.sendTriState("FFFFFFFF0001");
  delay(1000);
  digitalWrite(g_nPinLed, LOW);

  //Wait 10 seconds to begin
  delay(10000);
}
