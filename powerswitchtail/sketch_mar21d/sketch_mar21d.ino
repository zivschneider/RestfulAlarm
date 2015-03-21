#include <Bridge.h>

// control powerSocket
const int powerPin = A0;
const int ledPin = 13;
boolean powerOn = false;


char dataBuffer[4];      // buffer for receiving the data. You need an extra byte at the end, so 4 bytes to get 3
int red, green, blue;    // ints to set the LED brightnesses
String dataString;       // a string for the buffer-to-int conversion

// control LEDs

int incomingByte;  //a variable to read incoming serial data 





void setup() {
  //initiate serial communication:
  Bridge.begin();
  Serial.begin(9600);
  Serial.println(F("starting up"));
  
  
  
  pinMode(ledPin, OUTPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  

  // use pin 8 as a cathode ground pin:
  digitalWrite(ledPin, LOW);
  digitalWrite(powerPin, HIGH);
}  



void loop() {

Bridge.get("state", dataBuffer, 3);// get the green value
dataString = String(dataBuffer);   // convert to a String
  
  // read serial messages
  if (Serial.available() > 0) {
    powerOn = !powerOn;
    
    if (powerOn) {
      digitalWrite(powerPin, LOW);
      Serial.println(F("ON"));
    } else {
//      digitalWrite(ledPin, LOW);
      digitalWrite(powerPin, HIGH);
      Serial.println(F("OFF"));
    }      
    
    //read all the bytes in the serial buffer (we don't care about the contents of the data)
    while (Serial.available()) incomingByte = Serial.read();
  }                       
}
