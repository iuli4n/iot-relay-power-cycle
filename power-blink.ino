// This code is intended to drive a relay that turns on power to a circuit at specific intervals,
// such as turning on/off a fan through an IOT Relay
// 
// To use it, connect an Arduino to the relay using two pins: 10 and GROUND. Then update the code to specificy the on/off periods and loops.


#define CPIN 10   // pin 
#define LPIN LED_BUILTIN   // onboard led will be used to display our status

unsigned long nextStop, nextDuration;

void turnOn(unsigned long  durationSecs) {
  digitalWrite(CPIN, HIGH);
  digitalWrite(LPIN, HIGH);
  delay(durationSecs * 1000);
}

void turnOff(unsigned long  durationSecs) {
  digitalWrite(CPIN, LOW);
  digitalWrite(LPIN, LOW);
  delay(durationSecs * 1000);
}


void setup() {
  Serial.begin(9600);
  pinMode(CPIN, OUTPUT);
  pinMode(LPIN, OUTPUT);
}

void loop() {

  // phase 1 -- copy/paste as necessary

  // how long it should do this phase (in secs)
  nextDuration = 15*60;     nextStop = nextDuration * 1000 + millis();
  do {
    
    turnOn (60);  // turn on for specified secs
    turnOff(45);  // turn off for specified secs
    
  } while (nextStop > millis());



  // phase 2 -- copy/paste as necessary

  // how long it should do this phase (in secs)
  nextDuration = 15*60;     nextStop = nextDuration * 1000 + millis();
  do {
    
    turnOn (13*60);  // turn on for specified secs
    turnOff( 2*60);  // turn off for specified secs
  
  } while (nextStop > millis());


  
}
