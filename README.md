# IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics
## Monitor the Temperature and Humidity on any device and also upload that data to Thingspeak Cloud.
![Project Image2](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Project%20Image2.jpg?raw=true)
![Project Image2](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Project%20Image1.jpg?raw=true)
### Block Diagram:
![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics/blob/master/Block%20Diagram.jpg?raw=true)

### Component & Supplies:
1) NodeMCU ESP8266-12E [1 Unit]
2) DHT11 Sensor [1 Unit]
3) Jumper Wires (Male-to-Male) [10 Units]
4) Breadboard [1 Unit]

### Prerequisites:
Arduino IDE with ESP8266 add-on installed.

### Circuit description and working:
Circuit diagram for monitoring humidity and temperature is shown in figure below. It is built around NodeMCU ESP8266, DHT11 Sensor and few jumper wires on Solderless breadboard.

### Schematic:

The DHT11 sensor senses humidity and temperature, and sends the information to digital pin D2 of NodeMCU ESP8266 board, as shown in the above figure. From NodeMCU, humidity and temperature values are uploaded to the Cloud at regular intervals of time through NodeMCU ESP8266 Wi-Fi module. From the Cloud, humidity and temperature values can be seen graphically on ThingSpeak platform from anywhere in the world.

### Construction and testing:
ThingSpeak is an open source data platform but you need to register to use it. After registering, login to your account and create a new channel with humidity as one field and temperature as another, as shown in figure below. Once a new channel is created, it will generate two API keys, namely, write API key and read API key. Replace the line given below in the program with your write API key:

_String apiKey = “NTIM1RXET6YVUVWF“;_

Next, substitute Host_Name and Password with your Wi-Fi name and Wi-Fi password in the two lines given below in the program (code.ino):

_String Host_Name = “DLinkWiFi”;
String Password = “Pass@123”;_

The program should be verified with your Wi-Fi setup. It uses DHT library. If DHT library is not present in your Arduino folder, download it from https://github.com/adafruit/DHT-sensor-library. To import DHT library in Arduino IDE, select Sketch >>> Import library >>> Add library >>> Select the library that you have downloaded.
Compile the sketch/program and upload it to Arduino MCU through Arduino IDE. Ensure that Wi-Fi modem and the Internet connection in your PC/smartphone are working properly. Once sketch uploading is done, it will upload humidity and temperature values on ThingSpeak platform and you will be able to see it graphically in Private view window, as shown in figure below. If you want to change channel or field name, you can change it from Channel Settings (shown in the figure below).

### Other applications : 

Along with temperature and humidity sensor, other sensors like gas, voltage, current and energy can be used based on the requirement. Moreover, it is also possible to take further actions by controlling the actuators from the Internet once the sensor values are going above/below predetermined values.
