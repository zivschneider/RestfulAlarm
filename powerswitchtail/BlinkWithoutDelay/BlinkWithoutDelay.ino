
const int powerPin = A0;
boolean powerOn = false;
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 400;           // interval at which to blink (milliseconds)

void setup() {  
  
  Serial.begin(9600);
  Serial.println(F("starting up"));
  pinMode(powerPin, OUTPUT);
  
}

void loop()
{
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
 
    powerOn = !powerOn;
    
    if (powerOn) {
      digitalWrite(powerPin, LOW);
      Serial.println(F("ON")); } 
      else {
      digitalWrite(powerPin, HIGH);
      Serial.println(F("OFF"));
    }    

  }
}

