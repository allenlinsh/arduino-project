// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 10     // make this higher to slow down
 
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  int r, g, b;
  int temp_r, temp_g, temp_b;
  boolean soundstate;
  
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    soundstate = digitalRead(7);
    analogWrite(REDPIN, r);
    temp_r = r;
    delay(FADESPEED);    
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    }
    else {
      analogWrite(REDPIN, temp_r);
      analogWrite(BLUEPIN, temp_b);
      analogWrite(GREENPIN, temp_g);
    }
  } 
  
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    soundstate = digitalRead(7);
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    }
  } 
  
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    soundstate = digitalRead(7);
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    }
  } 
  
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    soundstate = digitalRead(7);
    analogWrite(REDPIN, r);
    delay(FADESPEED);
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    }
  } 
  
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    soundstate = digitalRead(7);
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    } 
  }
  
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    soundstate = digitalRead(7);
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
    if (soundstate == 0) {
      analogWrite(REDPIN, 0);
      analogWrite(BLUEPIN, 0);
      analogWrite(GREENPIN, 0);
    }
  } 
}
