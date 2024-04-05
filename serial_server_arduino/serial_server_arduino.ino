///////// my sepcial delay function ///////////////
void delayMs(int ms) {
  for (int i = 0; i < ms; i += 1) {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////


//////////////////////////////////////
#include "serial_comm.h"
//////////////////////////////////////








unsigned long prevSerialCommTime, sampleSerialCommTime = 10; //ms -> (1000/sampleTime) hz

void setup() {
  Serial.begin(115200);// NOTE THIS BAUD RATE
  Serial.setTimeout(2);// DO NOT TOUCH

  initLed(); // initialize built in led
  
  prevSerialCommTime = millis();
}


void loop() {

////////// THIS PART HANDLES THE SERIAL COMMUNICATION //////////////
/************PLEASE TRY NOT TO EDIT THIS PART*****************/
  if ((millis() - prevSerialCommTime) >= sampleSerialCommTime) {
    serialReceiveAndSendData();
    prevSerialCommTime = millis();
  }
/////////////////////////////////////////////////////////////////////


/////////////////// YOU CAN PUT YOUR CODES BELOW ////////////////////


/////////////////////////////////////////////////////////////////////
}
