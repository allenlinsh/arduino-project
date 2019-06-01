#ifdef MICRO
const int R = 5;    //output to RED mosfet (pwm pin)        
const int G = 6;    //output to GREEN mosfet (pwm pin)
const int B = 3;    //output to BLUE mosfet (pwm pin)
const int SI = 7;   //input for MICROPHONE (interrupt pin)
#endif

#ifdef UNO
const int TX = 1; //Serial pins for SoftwareSerial
const int RX = 0;
#endif

struct rec
{
  int del;
  byte r,g,b;
};

rec data = {10 , 0, 0, 0};
       
byte mode = 1;

byte red[3]={0,0,0};
byte green[3]={0,0,0};
byte blue[3]={0,0,0};

byte del[3]={0,0,0};

byte com;
