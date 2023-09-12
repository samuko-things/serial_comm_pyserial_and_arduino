

///////// DIFFERENT TASK FOR SERIAL AND I2C COMMUNICATION //////////
/////// NOTE THAT ALL FUNCTIONS SHOULD RETURN A STRING /////////////

String turnOnLed(){
  onLed();
  return "1";
}

String turnOffLed(){
  offLed();
  return "1";
}


String setMotorAPwm(int valA){
//  motorA.sendPWM(valA);/
  return "1";
}


String setMotorsPwm(int valA, int valB){
//  motorA.sendPWM(valA);/
//  motorB.sendPWM(valB);/
  return "1";
}

String sendSonarDist(){
  /*put in here the function that handles the dist reading
  e.g int dist = readSonarDist();*/
  int dist = readSonarDist();
  return String(dist);
}
//////////////////////////////////////////////////////////////////////










///////////////// SERIAL COMMUNICATION ///////////////////////////////////
String ser_msg = "";

String serMsg = "", serMsgBuffer, serDataBuffer[3];

void serialReceiveAndSendData() {
  int indexPos = 0, i = 0;

  if (Serial.available() > 0) {
    while (Serial.available())
    {
      serMsg = Serial.readString();
    }
    serMsg.trim();
    if (serMsg != "") {
      do {
        indexPos = serMsg.indexOf(',');
        if (indexPos != -1) {
          serMsgBuffer = serMsg.substring(0, indexPos);
          serMsg = serMsg.substring(indexPos + 1, serMsg.length());
          serDataBuffer[i] = serMsgBuffer;
          serMsgBuffer = "";
        }
        else {
          if (serMsg.length() > 0)
            serDataBuffer[i] = serMsg;
        }
        i += 1;
      } while (indexPos >= 0);
    }


    if (serDataBuffer[0] != ""){

      //// you can add functions in the if else part so it can be handled by the serial communication ////
      
      if (serDataBuffer[0] == "pwm") {
        ser_msg = setMotorsPwm(constrain(serDataBuffer[1].toInt(), -255, 255), constrain(serDataBuffer[2].toInt(), -255, 255));
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "pwmA") {
        ser_msg = setMotorAPwm(constrain(serDataBuffer[1].toInt(), -255, 255));
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "dist") {
        ser_msg = sendSonarDist();
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "on") {
        ser_msg = turnOnLed();
        Serial.println(ser_msg);
        ser_msg = "";
      }

      else if (serDataBuffer[0] == "off") {
        ser_msg = turnOffLed();
        Serial.println(ser_msg);
        ser_msg = "";
      }

      ////////////////////////////////////////////////////////////////////////////////////////////////////
      
    } else {
      ser_msg = "0";
      Serial.println(ser_msg);
      ser_msg = "";
    }
  }
  
  serMsg = "";
  serMsgBuffer = "";
  serDataBuffer[0] = "";
  serDataBuffer[1] = "";
  serDataBuffer[3] = "";
}
//////////////////////////////////////////////////////////////////////////
