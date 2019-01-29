
#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial mySerial(7,8);

//button pin
int buttonPin = 3;

void setup()
{
  mySerial.begin(19200);    // the GPRS baud rate   
  Serial.begin(19200);    // the GPRS baud rate 
  delay(500);
}

void loop(){
//If button is pressed, send text message 
int buttonVal = digitalRead(buttonPin);
if(buttonVal == HIGH){
SendTextMessage();
delay(500);
}

//Send text message
void SendTextMessage()
{
  mySerial.print("AT+CMGF=1\r");    //Because we want to send the SMS in text mode
  delay(100);
  mySerial.println("AT+CMGS=\"+44##########\""); //send sms message, insert your own phone number including the country code
  delay(100);
  mySerial.print("Test message from Arduino");//the content of the message
  delay(100);
  mySerial.print((char)26);//the ASCII code of the ctrl+z is 26
  delay(100);
  mySerial.println();
}}
