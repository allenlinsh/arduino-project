int LED = 13;
int dot = 150;
int dash = dot * 3;
int elemPause = dot;
int charPause = dot * 3;
int wordPause = dot * 7;
char fName[] = "allen";
char lName[] = "lin";

void setup() {
  pinMode(LED, OUTPUT);
}
void MorseDot() {
  digitalWrite(LED, HIGH);
  delay(dot);
}
void MorseDash() {
  digitalWrite(LED, HIGH);
  delay(dash);
}
void MorseElemPause() {
  digitalWrite(LED, LOW);
  delay(elemPause);
}
void MorseCharPause() {
  digitalWrite(LED, LOW);
  delay(charPause);
}
void MorseWordPause() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(wordPause);                       // wait for a second
}
void Turnoff () {
  digitalWrite(LED, LOW);
  delay(wordPause);
}
void loop () {
  int i = 0;
  Turnoff();
  switch (fName[0]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (fName[1]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (fName[2]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (fName[3]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (fName[4]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  MorseWordPause();
  switch (lName[0]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (lName[1]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  switch (lName[2]) {
    case 'a':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      break;
    case 'e':
      MorseDot();
      MorseElemPause();
      break;
    case 'i':
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'l':
      MorseDot();
      MorseElemPause();
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
    case 'n':
      MorseDash();
      MorseElemPause();
      MorseDot();
      MorseElemPause();
      break;
  }
  MorseCharPause();
  MorseWordPause();
  Turnoff();
}
