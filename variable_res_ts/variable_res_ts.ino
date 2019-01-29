 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>  
 #define DHTPIN D0
 #define DHTTYPE DHT11  
 DHT dht(DHTPIN, DHTTYPE);  
 const char* ssid = "hi";  
 const char* password = "1234567?";  
 WiFiClient client;  
 unsigned long myChannelNumber = 403225;  
 const char * myWriteAPIKey = "ISQSS4RP7HWAAU8D";  
 uint8_t temperature, humidity,voltage, k=0, l=0;  
 void setup()  
 {  
  //pinMode(16,OUTPUT);
  //digitalWrite(16,LOW);  
  Serial.begin(115200);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address
  //digitalWrite(16,HIGH);  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 } 
 static boolean data_state = false;  
 void loop()   
 {  
   int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);// ThingSpeak will only accept updates every 15 seconds. 
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
  Serial.println("%"); 
  Serial.print("Voltage value is :");
  Serial.print(voltage);
  Serial.println("V"); 
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1.  
  if(temperature < 255)
  {
      k=temperature;  
  }
   if(humidity < 255)
  {
      l=humidity;  
  }
  
  
   //ThingSpeak.writeField(myChannelNumber, 1, k, myWriteAPIKey);  
   //data_state = false;  
  // delay(15000);
   //ThingSpeak.writeField(myChannelNumber, 2, l, myWriteAPIKey);  
   //data_state = true;  
   //delay(15000);
    ThingSpeak.writeField(myChannelNumber, 3, voltage, myWriteAPIKey);  
   delay(10000);
 }  
