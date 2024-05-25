# serial_comm_pyserial_and_arduino
sample serial communication code between pyserial and arduino that can be adapted to your arduino project.

Just dowload the python and arduino comm code, run it, test it and adapt it to your project.


## Sample Routes and their functions
> please check the `serial_comm.h` file in the `serial_server_arduino` file to see the routes. Also check the python client `.py` files to see how the routes are being accessed.

- **`"/sine"`** : access the function to return (i.e get) test **sine vave values**.
- **`"/led-state"`** : access the function to get and send **led state [0 or 1]**  where 0 - OFF and 1 - ON.