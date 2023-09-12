///////// my sepcial delay function ///////////////
void delayMs(int ms) {
  for (int i = 0; i < ms; i += 1) {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////




////////// motor bridge control ////////////
#include "motor_bridge_control.h"
// motor A H-Bridge Connection
int IN1 = 7, IN2 = 8, enA = 5;
MotorControl motorA(IN1, IN2, enA);

// motor B H-Bridge Connection
int IN3 = 11, IN4 = 12, enB = 6;
MotorControl motorB(IN3, IN4, enB);
/////////////////////////////////////////////




void initLed(){
  pinMode(LED_BUILTIN, OUTPUT);
}

void onLed(){
  digitalWrite(LED_BUILTIN, HIGH);
}

void offLed(){
  digitalWrite(LED_BUILTIN, LOW);
}




int readSonarDist(){
  // enter your sonar reading function here
  return 253;
}






//////////////////////////////////////
#include "serial_comm.h"
//////////////////////////////////////








unsigned long prevSerialCommTime, sampleSerialCommTime = 10; //ms -> (1000/sampleTime) hz

void setup() {
  Serial.begin(115200);// NOTE THIS BAUD RATE
  Serial.setTimeout(2);// DO NOT TOUCH

  /*SAMPLE OF SENDING PWM TO THE MOTORS VIA L298N HBRIDGE*/
  //  motorA.sendPWM(-100); // REVERSE
  //  motorB.sendPWM(100);  // FORWARD

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
