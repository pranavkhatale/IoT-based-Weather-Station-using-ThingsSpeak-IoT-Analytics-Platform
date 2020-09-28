//Weather Station using NodeMCU ESP8266 & Thingspeak IoT Analytics.
// by Pranav Khatale
#include <dht.h> // Include DHT Header file for DHT sensor.
#define dht_apin D2 // Analog Pin sensor is connected to pin D2.
 
dht DHT;// Including library for DHT sensor.

#include <ESP8266WiFi.h>

String apiKey = "FYAOILR3XDN6HJ5P";     //  Enter your Write API key from ThingSpeak IoT Analytics Cloud platform.

const char *ssid =  "Snehal";     // Replace with your Wi-Fi ssid.
const char *pass =  "917057968804"; // // Replace with your Wi-Fi wpa2 key.
const char *server = "api.thingspeak.com"; //Initializing Server.
WiFiClient client;
 
void setup() 
{
       // Program written in setup will run only once for connecting to Wi-Fi network.
       Serial.begin(115200); // Selecting the baud rate for Serial Communication.
       delay(500);
       // initialize digital pin LED_BUILTIN as an output.
       pinMode(LED_BUILTIN, OUTPUT);
      
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
       WiFi.begin(ssid, pass); // Wi-Fi network searching starts.
 
       while (WiFi.status() != WL_CONNECTED) 
           {
            delay(500);
            Serial.print(".");
           }
       Serial.println("");
       Serial.println("WiFi connected."); //Prints on serial monitor if Wi-Fi gets connected sucessfully.
}
 
void loop() 
{
  DHT.read11(dht_apin); // Reading DHT sensor pin D2's data.
  
      float h = DHT.humidity; // Storing the humidity float value in variable h
      float t = DHT.temperature; // Storing the temperature float value in variable h
      
      if (isnan(h) || isnan(t)) 
         {
          Serial.println("Failed to read from DHT sensor!");
          return;
         }
                 
       if (client.connect(server,80))   // "184.106.153.149" or api.thingspeak.com
          {                  
           String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(t);
           postStr +="&field2=";
           postStr += String(h);
           postStr += "\r\n\r\n";
 
           client.print("POST /update HTTP/1.1\n");
           client.print("Host: api.thingspeak.com\n");
           client.print("Connection: close\n");
           client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
           client.print("Content-Type: application/x-www-form-urlencoded\n");
           client.print("Content-Length: ");
           client.print(postStr.length());
           client.print("\n\n");
           client.print(postStr);

           // Printing DHT Sensor's Humidity & Temperature on Serial Monitor.
           Serial.print("Temperature: "); 
           Serial.print(t);
           Serial.print(" °C, Humidity: ");
           Serial.print(h);
           Serial.println("% ||| Data sent to Thingspeak IoT Analytics Cloud platform.");
          }
          client.stop();
          Serial.println("Waiting..."); // Waiting for new data to be sensed by DHT Sensor.
  
  // thingspeak needs minimum 15 sec delay between on Cloud console updates for free subscription.
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}
