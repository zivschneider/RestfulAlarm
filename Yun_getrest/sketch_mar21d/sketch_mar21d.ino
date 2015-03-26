/*
  RGB LED controller using REST interface
  Context:  Arduino, for Yun
 This example shows how to use the Bridge Library's get() command
 to get data from the linux processor to the Arduino processor.
 That data can be put in the linux processor's data store using the
 REST API like so:
http://arduino.local/data/put/red/xxx
http://arduino.local/data/put/green/xxx
http://arduino.local/data/put/blue/xxx
Where xxx is a numeric string from 0 -255
 The circuit:
 * Common cathode RGB LED on pins 8 - 11.
 *    Pin 8: cathode
 *    Pin 9: green
 *    Pin 10: blue
 *    Pin 11: red
 created  4 Mar 2015
 by Tom Igoe
 */

#include <Bridge.h>

char dataBuffer[4];      // buffer for receiving the data. You need an extra byte at the end, so 4 bytes to get 3
int red, green, blue;    // ints to set the LED brightnesses
String dataString;       // a string for the buffer-to-int conversion

void setup() {
  // initiate Bridge connection to linux processor:
  Bridge.begin();#include <Bridge.h>

char dataBuffer[4];

const int powerPin1 = A0;
const int powerPin2 = A1;
int one, two;
boolean powerOn1 = false;
boolean powerOn2 = false;
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 4000;           // interval at which to blink (milliseconds)

void setup() {
  
  Bridge.begin();
  Serial.begin(9600);
  Serial.println(F("starting up"));
  pinMode(powerPin1, OUTPUT);
  pinMode(powerPin2, OUTPUT);
  
}

void loop()
{
  
  Bridge.get("light", dataBuffer, 3);
    Serial.println(dataBuffer);
    if (dataBuffer = "on") {
    powerOn1 = true;
    } else {
      powerOn1 = false;
    };
    
  Bridge.get("sound", dataBuffer, 3);
    Serial.println(dataBuffer);
    if (dataBuffer = "on") {
    powerOn2 = true;
    } else {
      powerOn2 = false;
    }
    if (powerOn1) {
      digitalWrite(powerPin1, LOW);
      Serial.println(F("1 ON")); } 
      else {
      digitalWrite(powerPin1, HIGH);
      Serial.println(F("1 OFF"));
    }    
    if (powerOn2) {
      digitalWrite(powerPin2, LOW);
      Serial.println(F("2 ON")); } 
      else {
      digitalWrite(powerPin2, HIGH);
      Serial.println(F("2 OFF"));
    }
} 
  Serial.begin(9600);
  // use pin 8 as a cathode ground pin:
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop() {
  Bridge.get("red", dataBuffer, 3);  // get the red value
  dataString = String(dataBuffer);   // convert to a String
  red = dataString.toInt();          // convert String to int

  Bridge.get("green", dataBuffer, 3);// get the green value
  dataString = String(dataBuffer);   // convert to a String
  green = dataString.toInt();        // convert String to int

  Bridge.get("blue", dataBuffer, 3);  // get the blue value
  dataString = String(dataBuffer);    // convert to a String
  blue = dataString.toInt();          // convert String to int

  // turn on the LED channels:
  analogWrite(11, red);
  analogWrite(9, green);
  analogWrite(10, blue);
  // slight delay before next read of the linux data store:
  delay(100);
}
