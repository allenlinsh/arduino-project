#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

#define BREAK 5
#define FADESPEED 10     // make this higher to slow down

void setup() {
  // Start off with the LED off.
  setColourRgb(0,0,0);
  pinMode(7,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
}

void loop() {
  unsigned int rgbColour[3];
  boolean soundstate;

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      soundstate = digitalRead(7);
      if (soundstate == 0) {
        setColourRgb(LOW, LOW, LOW);
        delay(BREAK);    
      }
      else {
        setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
        delay(FADESPEED);
      }
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(REDPIN, red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
 }

