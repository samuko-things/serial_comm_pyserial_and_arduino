
import serial
import time
import math

class MySerialClient:
  
  def __init__(self, port):
    self.ser = serial.Serial(port, 115200, timeout=0.1)
    self.val = 0

  # def send_msg(self, msg_to_send):
  #   data = ""
  #   while data=="":
  #     self.ser.write(msg_to_send.encode())   # send a single or multiple byte
  #     data = self.ser.readline().decode().strip()
  #   return data

  def send_msg(self, msg_to_send):
    data = ""
    prev_time = time.time()
    while data=="":
      try:
        self.ser.write(msg_to_send.encode())   # send a single or multiple byte    
        data = self.ser.readline().decode().strip()
        if time.time()-prev_time > 2.0:
          raise Exception("Error getting response from arduino, wasted much time \n")
      except:
        print("Error getting response from arduino, wasted much time \n")
    return data

  
  def send(self, cmd_route, valA=0, valB=0):
    cmd_str = cmd_route+","+str(valA)+","+str(valB)
    data = self.send_msg(cmd_str)
    if data == "1":
      return True
    else:
      return False
  
  
  def get(self, cmd_route):
    data = self.send_msg(cmd_route).split(',')
    if len(data)==1:
      return int(data[0])
    elif len(data)==2:
      return int(data[0]), int(data[1])
  
  


serClient = MySerialClient('/dev/ttyUSB0')
time.sleep(5) # wait 5 sec



###### TURN ON AND OFF LED #######
if __name__=='__main__':
  while True:
    isSuccess = serClient.send("on") # returns true or false to check if operation was successfull or not
    print(isSuccess)
    time.sleep(1)
    isSuccess = serClient.send("off") # returns true or false to check if operation was successfull or not
    print(isSuccess)
    time.sleep(1)



# ###### read test sonar dist #######
# if __name__=='__main__':
#   while True:
#     sonarDist = serClient.get("dist")
#     print(sonarDist)
#     time.sleep(0.01) #10 ms delay


# ###### WRITE MOTOR PWM #######
# if __name__=='__main__':
#   while True:
#     # isSuccess = serClient.send("pwm", 120, -120) # sends to left and write motor
#     # time.sleep(5)
#     isSuccess = serClient.send("pwmA", -75) # sends pwm commans to motor labelled A
#     time.sleep(2)