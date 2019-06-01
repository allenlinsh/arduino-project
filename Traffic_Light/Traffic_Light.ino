int trig = 6;
int echo = 7;
int buzzer = 8;
int r_led = 11;
int y_led = 12;
int g_led = 13;
long duration;
long distance;
int sound;
int g_delay = 400;
int y_delay = 200;
int r_delay = 100;
int G1 = 49;
int G4 = 392;
int C5 = 523;

void setup()
{
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r_led, OUTPUT);
  pinMode(y_led, OUTPUT);
  pinMode(g_led, OUTPUT);
}

void g_light()
{
  digitalWrite(g_led, HIGH);
  tone(buzzer, G1);
  delay(g_delay);
  digitalWrite(g_led, LOW);
  noTone(buzzer);
  delay(g_delay);
}

void y_light()
{
  digitalWrite(g_led, LOW);
  digitalWrite(y_led, HIGH);
  tone(buzzer, G4);
  delay(y_delay);
  digitalWrite(y_led, LOW);
  noTone(buzzer);
  delay(y_delay);
}

void r_light()
{
  digitalWrite(g_led, LOW);
  digitalWrite(y_led, LOW);
  digitalWrite(r_led, HIGH);
  tone(buzzer, C5);
  delay(r_delay);
  digitalWrite(r_led, LOW);
  noTone(buzzer);
  delay(r_delay);

  digitalWrite(y_led, HIGH);
  tone(buzzer, G4);
  delay(r_delay);
  digitalWrite(y_led, LOW);
  noTone(buzzer);
  delay(r_delay);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;

  if (distance > 20)
  {
    g_light();
  }
  else
  {
    digitalWrite(g_led, LOW);

  }
  if (distance <= 20 && distance > 10)
  {
    y_light();
  }
  else {
    digitalWrite(y_led, LOW);
    digitalWrite(g_led, LOW);
  }

  if (distance <= 10 && distance > 0)
  {
    r_light();
  }
  else
  {
    digitalWrite(r_led, LOW);
    digitalWrite(y_led, LOW);
    digitalWrite(g_led, LOW);
  }

  if (distance > 20 || distance <= 0)
  {
    noTone(buzzer);
  }
}

