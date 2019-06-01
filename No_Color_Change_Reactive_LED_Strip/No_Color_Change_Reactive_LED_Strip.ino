#define REDLED 5
#define GREENLED 6
#define BLUELED 3

void setup()
{
  pinMode(7,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  pinMode(REDLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
}

//this function will make the LED dim once the Parallax Sound Impact Sensor sends a 1 signal, and then return to it’s original brightness.
void loop()
{
  boolean soundstate = digitalRead(7);
  if (soundstate == 1) {
     analogWrite(REDLED, 0);
     analogWrite(BLUELED, 0);
     analogWrite(GREENLED, 255);
     delay(10);
  }
  else{
    analogWrite(REDLED, 0);
    analogWrite(BLUELED, 0);
    analogWrite(GREENLED, 0);
  }
}
