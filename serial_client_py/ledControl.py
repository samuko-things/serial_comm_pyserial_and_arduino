from serial_client_api import MySerialClient
import time


serClient = MySerialClient('/dev/ttyACM0')
time.sleep(2.5)



if __name__=='__main__':
  while True:

    #---------------------- TURN ON AND OFF LED -----------------------------#
    isSuccess = serClient.send("/led-state", 1) # turn on led and return true if operation is successful
    ledState = serClient.get("/led-state") # return the current led state
    print(isSuccess, ledState)
    time.sleep(3)
    isSuccess = serClient.send("/led-state", 0) # turn off led and return true if operation is successful
    ledState = serClient.get("/led-state") # return the current led state
    print(isSuccess, ledState)
    time.sleep(1)
    #-------------------------------------------------------------------------#
