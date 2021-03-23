# **_Welcome to the IoT-based-Weather-Station-using-ThingSpeak-IoT-Analytics-Platform wiki!_**
### _Monitor the Temperature and Humidity on any internet-connected device have a Web Browser and also upload that data to ThingSpeak IoT Analytics Platform._

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Project%20Image1.jpg?raw=true)

![Project Image1](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Project%20Image%203.jpg?raw=true)

#### **Block Diagram:**
![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics/blob/master/Block%20Diagram.jpg?raw=true)

### _Required components & tools:_
| **_Hardware_** | **_Quantity_** |
|---| :---: |
| [NodeMCU ESP8266-12E Board](https://en.wikipedia.org/wiki/NodeMCU) | 1 |
| DHT11 Sensor Module | 1 |
| Jumper Wires (Male-to-Female) | 3 |
| Breadboard | 1 |
| USB Cable | 1 |

| **_Software & Online tools_** |
|---|
| [Arduino IDE](https://www.arduino.cc/en/Main/Software) |
| [Web Browser](https://en.wikipedia.org/wiki/Web_browser) |
| [Thingspeak Account](https://thingspeak.com/) |

### _Prerequisites:_
* Arduino IDE with ESP8266 add-on installed.

### _Circuit description and working:_
The circuit diagram for monitoring humidity and temperature is shown in the figure below. It is built around NodeMCU ESP8266-12E board, DHT11 Sensor, and few jumper wires on the solderless breadboard.

### _Schematic:_
![Fritzing Schematic Diagram](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Fritzing%20Schematic.jpg?raw=true)
The DHT11 sensor senses humidity and temperature, and sends the information to digital pin D2 of NodeMCU ESP8266-12E board, as shown in the above figure. From NodeMCU, humidity and temperature values are uploaded to the Cloud at regular intervals of time through the NodeMCU ESP8266 Wi-Fi module. From the Cloud, humidity and temperature values can be seen graphically on the ThingSpeak platform from anywhere in the world.

### _Construction and testing:_

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/1.png?raw=true)

Go to [ThingSpeak](https://thingspeak.com/) website on a Web Browser.
Thingspeak is an IoT analytics platform but you need to register to use it. After registering, login to your account and **Create a new channel** with **Name**, add **Description**, Temperature as **Field1**, and Humidity as **Field2** (tick the square boxes shown in front of it), you can add **Elevation**, **Latitude** & **Longitude** of the place where you are installing this weather station (tick **Show Channel Location**) as shown in the figure below. Finally don't forget to tick the **Show Status** square box & click **Save Channel**.

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/2.png?raw=true)

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/3.png?raw=true)

Once a new channel is created, go to **API Keys** tab, ThingSpeak will generate two API keys, namely, write an API key and read the API key. Replace the line given below in the program with your write API key:

`String apiKey = “NTIM1RXET6YVUVWF“;`

Next, substitute _const char *ssid_ and _const char *pass_ with your Wi-Fi name and Wi-Fi password in the two lines given below in the program (code_Weather_Station.ino):

`const char *ssid =  "DLinkWiFi";`

`const char *pass =  "Pass@123";`

The program should be verified with your Wi-Fi setup. It uses the dht library. If the dht library is not present in your Arduino IDE. Go to your PC's **File Explorer > Documents > Arduino > libraries**. Create a new folder named **dht** in lower case only, [Download the dht.h & dht.cpp files](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-ThingsSpeak-IoT-Analytics-Platform/tree/master/dht) & paste both the files in that dht folder. Close the Arduino IDE. 

Open Arduino IDE. Connect the board with a USB cable to the computer. Compile the sketch/program and upload it to NodeMCU Board through Arduino IDE (don't forget to select **Board** & **Port** before uploading the sketch). Ensure that the Wi-Fi modem and the Internet connection in your PC/smartphone are working properly. Once sketch uploading is done, it will upload humidity and temperature values on the ThingSpeak platform and you will be able to see it graphically in the Private view window, as shown in the figure below. If you want to change the channel or field name, you can change it from Channel Settings (shown in the figure below).

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/4.png?raw=true)

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/5.png?raw=true)

Finally, your project looks like this image shown below in the Web Browser,

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/6.png?raw=true)

[Click here to view my ThingSpeak Channel.](https://thingspeak.com/channels/952128)

[Click here to view my Project Website](https://sites.google.com/view/thingspeakiotweatherstation/home) where I have integrated the whole project to access it with a single click.

![](https://github.com/pranavkhatale/IoT-based-Weather-Station-using-Thingspeak-IoT-Analytics-Platform/blob/master/Project%20Image2.jpg?raw=true)

### _**Built with  ❤  by Pranav Khatale**_
