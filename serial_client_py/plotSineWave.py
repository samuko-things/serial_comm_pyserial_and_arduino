#------------------------------------------------------------------------------------#
# from serial_client_api import MySerialClient
# import time


# serClient = MySerialClient('/dev/ttyACM0')
# time.sleep(2.5)



# if __name__=='__main__':
#   while True:

#     #---------------------- TURN ON AND OFF LED -----------------------------#
#     sineSignal = serClient.send("sine") # return custom sign signal value
#     print(sineSignal)
#     time.sleep(0.1)
#     #-------------------------------------------------------------------------#
#------------------------------------------------------------------------------------#







#----------------------------------------------------------------------------------------#
import matplotlib.pyplot as plt
import matplotlib.animation as animation

from serial_client_api import MySerialClient
import time


def animate(i):
    global serClient, axes, sineSignalList, pitchDataList, yawDataList, dataPoints

    sineSignal = serClient.get("sine") # return the current sine wave value
    
    sineSignalList.append(sineSignal)

    # Fix the list size so that the animation plot 'window' is x number of points
    sineSignalList = sineSignalList[-dataPoints:]
    
    axes.clear()
    axes.plot(sineSignalList)
    
    axes.grid(which = "major", linewidth = 0.5)
    axes.grid(which = "minor", linewidth = 0.2)
    axes.minorticks_on()

    axes.set_ylim([-10,10]) # Set Y axis limit of plot
    axes.set_title("SINE SIGNAL") # Set title of figure
    axes.set_ylabel("sign signal data") # Set title of y axis 
    axes.set_xlabel("number of data points") # Set title of z axis 


serClient = MySerialClient('/dev/ttyACM0')
time.sleep(2.5)

sineSignalList = []
dataPoints = 150
                                                        
fig = plt.figure()  # Create Matplotlib plots fig is the 'higher level' plot window
axes = fig.add_subplot(111) # Add subplot to main fig window


if __name__ == '__main__':
  ani = animation.FuncAnimation(fig, animate, frames=300, interval=25) 
  plt.show()
#--------------------------------------------------------------------------------------#