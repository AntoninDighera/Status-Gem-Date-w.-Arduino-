//ArduinoBluetoothWithSmirfLED3Servos 

#include <SoftwareSerial.h> 
#include <Servo.h>         

SoftwareSerial BT(10, 11);        //TX, RX respectively

Servo servo1;//Introducing a servo and naming it 
Servo servo2;
Servo servo3;

String state;                


void setup() {
 
 BT.begin(115200);
 Serial.begin(9600);              // serial communication to check the data on serial monitor
 
 pinMode(13, OUTPUT);             // LED connected to 13th pin

 servo1.attach(3);    
 servo2.attach(6);    
 //servo3.attach(3);    

 servo1.write(90);     
 servo2.write(90);
 //servo3.write(90);


}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){         //Check if there is an available byte to read
  delay(10);                      //Delay added to make reads stable (a little like a spam block)
  char c = BT.read();             //Created a variable called 'c' 
                                  //Whenever 'c' is referenced it's the equivalent writing "BT.read()" #lazy
  
  state += c;                   
                                  
  }  

  
  if (state.length() > 0) {       
                                  
    Serial.println(state);       


  if(state == "On")               
                                  
  {
  digitalWrite(13, HIGH);           //Turn LED (13~) on 
    
      } 
  
  if(state == "Off")              
  {   
    digitalWrite(13, LOW);          //Turn LED (13~) off
     }  
  
  if(state == "S1")                 
  {
    servo1.write(120);              //Make Servo 1 move 
    delay(2000);
    servo1.write(50);
    delay(1000);
    servo1.write(90); 
  }
 
  if(state == "S2")                 //Make Servo 2 move 
  {
    servo2.write(120);
    delay(2000);
    servo2.write(50);
    delay(1000);
    servo2.write(90); 
  }
  
  if(state == "S3")                 //Make Servo 3 move 
  {
    servo3.write(120);
    delay(2000);
    servo3.write(50);
    delay(1000);
    servo3.write(90); 
  }
  
  
state ="";                      //after loop finished change the value of the 'state' variable to blank and LOOP

}

} //Reset the variable







