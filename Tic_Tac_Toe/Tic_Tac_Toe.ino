
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(14,15,16,17,18,19);

int tictac[10];
boolean s2_flag,s3_flag ,s4_flag ,s5_flag ,s6_flag ,s7_flag ,s8_flag ,s9_flag ,s10_flag,winner_flag ;
int s2,s3,s4,s5,s6,s7,s8,s9,s10;
int count = 0 ;
int winner = 0 ;
int P1_points = 0 , P2_points = 0 ;
char sx,control ;

void setup() 
{
  
s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ; 

for(int i = 0 ; i < 9 ; i++) //clearing the array on reset
tictac[i] = 0 ;

Serial.begin(9600);

lcd.begin(20,4);
lcd.setCursor(2,1);
lcd.print("TIC TAC TOE :-)");
delay(1000);
lcd.setCursor(2,1);
lcd.print("TIC TAC TOE ;-)");
delay(1500);
displayboard();

pinMode(2,INPUT);  
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);

}

void loop()
{

s2 = digitalRead(2) ; //Reading statuses of the pins
s3 = digitalRead(3) ;
s4 = digitalRead(4) ;
s5 = digitalRead(5) ;
s6 = digitalRead(6) ;
s7 = digitalRead(7) ;
s8 = digitalRead(8) ;
s9 = digitalRead(9) ;
s10= digitalRead(10) ;

//if(Serial.available() > 0) // tester code 
//{
//  
//sx = Serial.read() ;
//Serial.println(" you selected cell no - ");
//Serial.print(sx);
//Serial.println(" ");
//
//if (sx == '0')
//s2 = HIGH ;
//else if (sx == '1')
//s3 = HIGH ;
//else if (sx == '2')
//s4 = HIGH ;
//else if (sx == '3')
//s5 = HIGH ;
//else if (sx == '4')
//s6 = HIGH ;
//else if (sx == '5')
//s7 = HIGH ;
//else if (sx == '6')
//s8 = HIGH ;
//else if (sx == '7')
//s9 = HIGH ;
//else if (sx == '8')
//s10 = HIGH ;
//
//}

if(s2 == HIGH && s2_flag == false ) 
{
  s2_flag = true ;
  count ++;
  if(count % 2 == 0 )
  {
  tictac[0] = 5 ; // O
  lcd.setCursor(15,1);
  lcd.print("O");
  }
  else
  {
  tictac[0] = 1 ;
  lcd.setCursor(15,1);
  lcd.print("X");// X
  }
}

else if(s3 == HIGH && s3_flag == false ) 
{
  s3_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[1] = 5 ; // O
  lcd.setCursor(17,1);
  lcd.print("O");
  }
  else
  {
  tictac[1] = 1 ; // X
  lcd.setCursor(17,1);
  lcd.print("X");
  }
}

else if(s4 == HIGH && s4_flag == false ) 
{
  s4_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[2] = 5 ; // O
  lcd.setCursor(19,1);
  lcd.print("O");
  }
  else
  {
  tictac[2] = 1 ; // X
  lcd.setCursor(19,1);
  lcd.print("X");
  }
}

else if(s5 == HIGH && s5_flag == false ) 
{
  s5_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[3] = 5 ; // O
  lcd.setCursor(15,2);
  lcd.print("O");
  }
  else
  {
  tictac[3] = 1 ; // X
  lcd.setCursor(15,2);
  lcd.print("X");
  }
}

else if(s6 == HIGH && s6_flag == false ) 
{
  s6_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[4] = 5 ; // O
  lcd.setCursor(17,2);
  lcd.print("O");
  }
  else
  {
  tictac[4] = 1 ; // X
  lcd.setCursor(17,2);
  lcd.print("X");
  }
}

else if(s7 == HIGH && s7_flag == false ) 
{
  s7_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[5] = 5 ; // O
  lcd.setCursor(19,2);
  lcd.print("O");
  }
  else
  {
  tictac[5] = 1 ; // X
  lcd.setCursor(19,2);
  lcd.print("X");
  }
}

else if(s8 == HIGH && s8_flag == false ) 
{
  s8_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[6] = 5 ; // O
  lcd.setCursor(15,3);
  lcd.print("O");
  }
  else
  {
  tictac[6] = 1 ; // X
  lcd.setCursor(15,3);
  lcd.print("X");
  }
}

else if(s9 == HIGH && s9_flag == false ) 
{
  s9_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[7] = 5 ; // O
  lcd.setCursor(17,3);
  lcd.print("O");
  }
  else
  {
  tictac[7] = 1 ; // X
  lcd.setCursor(17,3);
  lcd.print("X");
  }
}

else if(s10 == HIGH && s10_flag == false ) 
{
  s10_flag = true ;
  count ++ ;
  if(count % 2 == 0 )
  {
  tictac[8] = 5 ; // O
  lcd.setCursor(19,3);
  lcd.print("O");
  }
  else
  {
  tictac[8] = 1 ; // X
  lcd.setCursor(19,3);
  lcd.print("X");
  }
}

//Serial.println("count =");
//Serial.println(count);

winner = check();
if(winner == 1)
{ 
  delay(1000);
  Serial.println("Player 1 wins ! "); 
  P1_points ++ ;
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print("Player 1 wins !");
  delay(2000);
  winner_flag = true  ;
}
else if(winner == 2)
{
  delay(1000);
  Serial.println("Player 2 wins ! ");
  P2_points ++ ;
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print("Player 2 wins !");
  delay(2000);
  winner_flag = true ;
}
else if(winner == 0 && count == 9 )
{
  delay(1000);
  Serial.println(" Draw match !! ") ;
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print("Draw match !!");
  delay(2000);
  winner_flag = true ;
}

if(winner_flag == true )
{
  while( s2== HIGH || s3 == HIGH  || s4 == HIGH || s5 == HIGH || s6 == HIGH || s7 == HIGH || s8 == HIGH || s9 == HIGH || s10 == HIGH )
  {
    s2 = digitalRead(2) ; //Reading statuses of the pins
    s3 = digitalRead(3) ;
    s4 = digitalRead(4) ;
    s5 = digitalRead(5) ;
    s6 = digitalRead(6) ;
    s7 = digitalRead(7) ;
    s8 = digitalRead(8) ;
    s9 = digitalRead(9) ;
    s10= digitalRead(10) ;
  }
  //Serial.println("waiting for reset...");
  //control = Serial.read();
  control = 'r' ;
  if(control == 'r' ) 
  {
  Serial.println("resetting..");
  //s2=s3=s4=s5=s6=s7=s8=s9=s10= LOW ;
  resett();
  displayboard();
  }
}

}//loop

int check ()
{
  if( ((tictac[0]+tictac[1]+tictac[2]) == 3 ) ||
      ((tictac[3]+tictac[4]+tictac[5]) == 3 ) ||
      ((tictac[6]+tictac[7]+tictac[8]) == 3 ) ||
      ((tictac[0]+tictac[3]+tictac[6]) == 3 ) ||
      ((tictac[1]+tictac[4]+tictac[7]) == 3 ) ||
      ((tictac[2]+tictac[5]+tictac[8]) == 3 ) ||
      ((tictac[0]+tictac[4]+tictac[8]) == 3 ) ||
      ((tictac[2]+tictac[4]+tictac[6]) == 3 ) )
      return 1 ;
  else if( ((tictac[0]+tictac[1]+tictac[2]) == 15 ) ||
      ((tictac[3]+tictac[4]+tictac[5]) == 15 ) ||
      ((tictac[6]+tictac[7]+tictac[8]) == 15 ) ||
      ((tictac[0]+tictac[3]+tictac[6]) == 15 ) ||
      ((tictac[1]+tictac[4]+tictac[7]) == 15 ) ||
      ((tictac[2]+tictac[5]+tictac[8]) == 15 ) ||
      ((tictac[0]+tictac[4]+tictac[8]) == 15 ) ||
      ((tictac[2]+tictac[4]+tictac[6]) == 15 ) )
      return 2 ;
  else
      return 0 ;     
      
}

void resett()
{
s2_flag = s3_flag = s4_flag = s5_flag = s6_flag = s7_flag = s8_flag = s9_flag = s10_flag = winner_flag = false ; 
for(int i = 0 ; i < 9 ; i++) //clearing the array on reset
tictac[i] = 0 ; 
count = 0 ;
winner = 0 ;
}

void displayboard()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PLAYER");
lcd.setCursor(7,0);
lcd.print("Pts");
lcd.setCursor(15,0);
lcd.print("BOARD");
lcd.setCursor(0,2);
lcd.print("P1(X)");
lcd.setCursor(0,3);
lcd.print("P2(O)");
lcd.setCursor(16,1);
lcd.print("|");
lcd.setCursor(18,1);
lcd.print("|");
lcd.setCursor(16,2);
lcd.print("|");
lcd.setCursor(18,2);
lcd.print("|");
lcd.setCursor(16,3);
lcd.print("|");
lcd.setCursor(18,3);
lcd.print("|");
lcd.setCursor(8,2);
lcd.print(P1_points);
lcd.setCursor(8,3);
lcd.print(P2_points);
}

