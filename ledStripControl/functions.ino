

void receive()
 {
  
  if (SERIAL.available()>0)
    {
      com=SERIAL.read();

      #ifdef UNODEBUG
      Serial.println();
      Serial.println("received command: ");
      Serial.println(com);
      #endif

      
      switch (com)
      {

          case 114: //r
          {
            data.r=convert(red);
            break;
          }
          
          case 103: //g
          {
            data.g=convert(green);
            break;
          }
          
          case 98: //b
          {
            data.b=convert(blue);
            break;
          }
          
          case 99: //c
          {
            mode=1;
            break;
          }

          case 102: //f
          {
            mode=2;
            break;
          }

          case 109: //m
          {
            mode=3;
            break;
          }

          case 100: //d
          {
            data.del=convert(del);
            break;
          }

          default:
            break;
            
        }
        svuotabuf();
     }
 }
 
 void svuotabuf()
 {
  byte temp;
  while(SERIAL.available()>0)
  {
    temp=SERIAL.read();
  }
  
  #ifdef UNODEBUG
  Serial.println();
  Serial.println("buffer empty");
  #endif

 }

byte convert (byte vet[]) //the vector contains digits of the value in decimal ascii
 {
   byte i;
   byte v1=0,v2=0,v3=0;
   byte res;
   
   for(i=0;i<3;i++) // fill vet[] with 255 to use later as a check for unused cells of the vector
                    // (for 1 and 2 digits number you don't fill up the vector)
      vet[i]=255;
     
  #ifdef UNODEBUG
  Serial.println();
  Serial.println("raw data vector = ");
  Serial.println(vet[0]);
  Serial.println(vet[1]);
  Serial.println(vet[2]);
  #endif 
            
   SERIAL.readBytesUntil(120,vet,3); //fill up vector with digits coming from bt module
   
   #ifdef UNO
   Serial.println();
   Serial.println("raw data vector = ");
   Serial.println(vet[0]);
   Serial.println(vet[1]);
   Serial.println(vet[2]);
   #endif
    
   for(i=0;i<3;i++) //conversion from decimal ascii to values, ignoring unused cells filled with 255
   {
      if (vet[i]!=255)
        vet[i]-=48;
   }
   
   #ifdef UNODEBUG
   Serial.println();
   Serial.println("converted data vector = ");
   Serial.println(vet[0]);
   Serial.println(vet[1]);
   Serial.println(vet[2]);
   #endif
              
   if (vet[2]==255)
   {
      if(vet[1]==255) //1 digit
      {
        v1=vet[0];
      }
      else //2 digits
      {
        v1=vet[0]*10;
         v2=vet[1];
      }
   }
   else //3 digits
   {
      v1=vet[0]*100;
      v2=vet[1]*10;
      v3=vet[2];
   }

            
    res=v1+v2+v3; //actual pwm value

   #ifdef UNODEBUG
   Serial.println();
   Serial.println("result:");
   Serial.println(res);
   #endif
   
    return res;
}

void fade (int del)
 {
  int con,conr,cong,conb,max=255;

  conr=0;
  cong=0;
  conb=0;
  
     for(con=0;con<max;con++)
  {
     if(conr<data.r)
      conr++;
      
     analogWrite(R,conr);

     if(cong<data.g)
      cong++;

     analogWrite(G,cong);

     if(conb<data.b)
      conb++;

     analogWrite(B,conb);
     
     delayMicroseconds(del);
    
   }

    conr=data.r;
    cong=data.g;
    conb=data.b;
    
    for(con=0;con<max;con++)
    {
      if(conr>0)
      conr--;
      
     analogWrite(R,conr);

     if(cong>0)
      cong--;

     analogWrite(G,cong);

     if(conb>0)
      conb--;

     analogWrite(B,conb);
     delayMicroseconds(del);
    }
  }




  void color (byte r,byte g,byte b)
  {
    analogWrite(R,r);
    analogWrite(G,g);
    analogWrite(B,b);
  }

  void off ()
  {
    analogWrite(R,0);
    analogWrite(G,0);
    analogWrite(B,0);
    delay(10); 
  }

  void blinker (byte r,byte g,byte b,unsigned int t,unsigned int d1,unsigned int d2)
  {
    byte i;
    for(i=0;i<t;i++)
    {
      analogWrite(R,r);
      analogWrite(G,g);
      analogWrite(B,b); 
      delay(d1);
      analogWrite(R,0);
      analogWrite(G,0);
      analogWrite(B,0);
      delay(d2);     
    }
    
  }


