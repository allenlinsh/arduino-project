// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

#define BREAK 5
#define FADESPEED 5     // make this higher to slow down
 
void setup() {
  pinMode(7,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  int r = 0, g = 0, b = 255;
  boolean soundstate;
  
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);    
    }
    else {
      analogWrite(REDPIN, r);
      analogWrite(BLUEPIN, b);
      analogWrite(GREENPIN, HIGH);
      delay(FADESPEED);
    }
  } 
  
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);
    }
    else {
      analogWrite(REDPIN, r);
      analogWrite(BLUEPIN, b);
      analogWrite(GREENPIN, HIGH);
      delay(FADESPEED);
    }
  } 
  
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);
    }
    else {
      analogWrite(REDPIN, r);
      analogWrite(BLUEPIN, HIGH);
      analogWrite(GREENPIN, g);
      delay(FADESPEED);
    }
  } 
  
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);
    }
    else {
      analogWrite(REDPIN, r);
      analogWrite(BLUEPIN, HIGH);
      analogWrite(GREENPIN, g);
      delay(FADESPEED);
    }
  } 

  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);
    }
    else {
      analogWrite(REDPIN, HIGH);
      analogWrite(BLUEPIN, b);
      analogWrite(GREENPIN, g);
      delay(FADESPEED);
    }
  }

  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    soundstate = digitalRead(7);
    if (soundstate == 0) {
      analogWrite(REDPIN, LOW);
      analogWrite(BLUEPIN, LOW);
      analogWrite(GREENPIN, LOW);
      delay(BREAK);
    }
    else {
      analogWrite(REDPIN, HIGH);
      analogWrite(BLUEPIN, b);
      analogWrite(GREENPIN, g);
      delay(FADESPEED);
    }
  } 

}
