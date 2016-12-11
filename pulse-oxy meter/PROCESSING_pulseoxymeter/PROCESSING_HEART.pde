import processing.serial.*;
float[] signal = new float[100];
Serial myPort; 
int val, screen_increment, old_x=0, old_y=0,count=0,temp=0;     
String inString; 
int lf = 10;     

void setup() 
{
  size(1400, 600);
 
  String portName = Serial.list()[32];
  println(Serial.list());
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil(lf);
  background(208,24,24);
}

void draw()
{
  strokeWeight(10);
  stroke(255, 255, 255);
  if(temp<99){
  line(screen_increment,700-signal[temp],screen_increment+2,700-signal[temp+1]);
  screen_increment= screen_increment+2;
  temp++;
  }
 if(screen_increment>(1400)){
    background(208,24,24);
    screen_increment=-10;
    old_x = -10;
    old_y = 0;
    temp=0;
  }
}

void serialEvent(Serial myPort) 
{ 

  inString = myPort.readString();
  inString = trim(inString);
  val = int(inString);
  println(val);

  if(count<1000)
  {
    for(int i=0;i<100;i++){
      if(i <99){
        signal[i]=signal[i+1];
      }
      else if(i==99){
        signal[i] = val;
        temp=0;
      }
    }
    println(signal);
  }
  else{
    count =0;
  }

}