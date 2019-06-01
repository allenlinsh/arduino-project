
#define MICRO // MICRO , UNO select what kind of microcontroller you are using
// #define UNODEBUG //enables the serial monitor in order to see the code in action

#define startup q//enables startup section(default mode 1=color and set a default color)

#ifdef UNO
#define SERIAL bt

#include <SoftwareSerial.h>
SoftwareSerial bt(RX, TX);

#ifdef UNODEBUG
Serial.begin(9600);
#endif

#endif

#ifdef MICRO
#define SERIAL Serial1
#endif

#include "variables.h"

void setup() 
{  
  pinMode(B,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(SI,INPUT);

  SERIAL.begin(9600);

 #ifdef startup
  mode=1;
  data.r=100;
  data.b=255;
 #endif
  
}


void loop() 
{
  
  switch(mode)
  {
    case 1:                     //color mode
    {
     do
      {
      
        color(data.r,data.g,data.b);
        receive();
   
      }
     while(mode==1);

     off();
     break;
     
    }

    case 2:                     //fade mode
    {
      do
      {
        
        fade(data.del*100);
        receive();
      }
      while(mode==2);

      off();
      break;
    }

    
    case 3:                     //music mode
    {

        attachInterrupt(digitalPinToInterrupt(SI),off , FALLING);
        do
        {
          
          color(data.r,data.g,data.b);

          receive();
        }
        while(mode==3);
        
        detachInterrupt(digitalPinToInterrupt(SI));
        off();
        break;
        
    }
  }
}





 


