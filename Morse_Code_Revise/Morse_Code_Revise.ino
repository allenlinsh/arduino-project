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
  digitalWrite(LED, LOW);  delay(wordPause);
}
void longPause () {
  digitalWrite(LED, LOW);
}
void pickLetter(char x){
  switch (x) {
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
}

void loop () {
  pickLetter(fName[0]);
  pickLetter(fName[1]);
  pickLetter(fName[2]);
  pickLetter(fName[3]);
  pickLetter(fName[4]);
  MorseWordPause();
  pickLetter(lName[0]);
  pickLetter(lName[1]);
  pickLetter(lName[2]);
  MorseWordPause();
  longPause();
}
