int heart_high, heart_low;
int data[200], i, mapped;


void setup(){
      pinMode(A0,OUTPUT);
      pinMode(A1,OUTPUT);
      pinMode(A2,OUTPUT);
      pinMode(A3,OUTPUT);
      pinMode(A4,OUTPUT);
      pinMode(A5,OUTPUT);
      pinMode(A6,INPUT);
      pinMode(A7,INPUT);

      Serial.begin(115200);
  
}

void loop(){

      heart_high=0;
      heart_low = 1023;
      
      for(i=200; i>0; i--){
        data[i] = data[i-1];
        
      if(data[i]>heart_high)
      heart_high=data[i];
      if(data[i]<heart_low)
      heart_low=data[i];
    }//for loop
    
    data[0] = analogRead(A6);
    
    mapped = map(data[0], 0, 1023, 0, 600);
    Serial.println(mapped);
  delay(5);
  
 
  if((heart_high-heart_low)>10){
   		if(data[0] > (heart_high-.95*(heart_high-heart_low)))
                  analogWrite(A0, 700);
                else
                  analogWrite(A0,0); 
                
                if(data[0] > (heart_high-.9*(heart_high-heart_low)))
                  analogWrite(A1, 700);
                else
                  analogWrite(A1,0); 
               
                if(data[0] > (heart_high-.8*(heart_high-heart_low)))
                  analogWrite(A2, 700);
                else
                  analogWrite(A2,0); 
                if(data[0] > (heart_high-.7*(heart_high-heart_low)))
                  analogWrite(A3, 700);
                else
                  analogWrite(A3,0); 
                if(data[0] > (heart_high-.6*(heart_high-heart_low)))
                  analogWrite(A4, 700);
                else
                  analogWrite(A4,0); 
                
                if(data[0] > (heart_high-.5*(heart_high-heart_low)))
                  analogWrite(A5, 700);
                else
                  analogWrite(A5,0); 
  }
  
  
  else
  {
	 	analogWrite(A0,0);
		analogWrite(A1,0);
		analogWrite(A2,0);
		analogWrite(A3,0);
		analogWrite(A4,0);
		analogWrite(A5,0);
  }


    

}


