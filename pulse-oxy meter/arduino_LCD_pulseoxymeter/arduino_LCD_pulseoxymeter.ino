
#include <LiquidCrystal.h>
#define A6 manual_circuit

int heart_high, heart_low, heart_beats = 0;
int data[200], i, mapped;
int baud_rate = 115200;
int threshold = 100;//need to set after checking

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
      heart_beats = 0;
      //lcd __init__
      lcd.begin(16, 2);
      lcd.print("Final Project!!!");
      //LED's __init__
      pinMode(A0,OUTPUT);
      pinMode(A1,OUTPUT);
      pinMode(A2,OUTPUT);
      pinMode(A3,OUTPUT);
      pinMode(A4,OUTPUT);
      pinMode(A5,OUTPUT);
      pinMode(A6,INPUT);
      pinMode(A7,INPUT);
      
      //serial Monitor __init__
      Serial.begin(baud_rate);
      delay(1000);  
}

void loop(){
      analogWrite(A0,0);
      analogWrite(A1,0);
      analogWrite(A2,0);
      analogWrite(A3,0);
      analogWrite(A4,0);
      analogWrite(A5,0);
      if( analogRead(manual_circuit)>threshold)
      {
        while(true){
          unsigned long timeold=millis();
           if(timeold<6000){   
               heart_high=1023;
               heart_low =0;
               lcd.clear();
               lcd.setCursor(0,0);
               lcd.print("Don't Remove");
               lcd.setCursor(0,1);   
               lcd.print("      Your Hand.");

               for(i=200; i>0; i--){
                  data[i] = data[i-1];
                  if(data[i]>heart_low)
                      heart_low=data[i];
                  if(data[i]<heart_low)
                      heart_low=data[i];
                }
                
              data[0] = analogRead(manual_circuit);
                
              mapped = map(data[0], 0, 1023, 0, 600);
              Serial.println(mapped);
              delay(5);
              
              if((heart_high-heart_low)>threshold){
                heart_beats +=1;
                if(data[0] > (heart_high-.7*(heart_high-heart_low))){
                  analogWrite(A0, 700);
                }
                else
                  analogWrite(A0,0); 
                
                if(data[0] > (heart_high-.6*(heart_high-heart_low)))
                  analogWrite(A1, 700);
                else
                  analogWrite(A1,0); 
               
                if(data[0] > (heart_high-.5*(heart_high-heart_low)))
                  analogWrite(A2, 700);
                else
                  analogWrite(A2,0); 
                if(data[0] > (heart_high-.4*(heart_high-heart_low)))
                  analogWrite(A3, 700);
                else
                  analogWrite(A3,0); 
                if(data[0] > (heart_high-.3*(heart_high-heart_low)))
                  analogWrite(A4, 700);
                else
                  analogWrite(A4,0); 
                
                if(data[0] > (heart_high-.2*(heart_high-heart_low)))
                  analogWrite(A5, 700);
                else
                  analogWrite(A5,0); 
              }
    
           }
           else
           {
           	    analogWrite(A0,0);
		    analogWrite(A1,0);
		    analogWrite(A2,0);
		    analogWrite(A3,0);
		    analogWrite(A4,0);
		    analogWrite(A5,0);
		    lcd.clear();
		    lcd.print(heart_beats*10);
		    delay(3000);
		    lcd.clear();
		    lcd.print("ThankYou!!");
		    exit(0);
           }
        }
      }
}

