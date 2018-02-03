//RGB status prism code

int potPin = 0;   
//create an integer variable, name it 'potPin', give it a value of 0 right now it is not assigned to any port, it's just a word with a value
int potValue = 0;
 
/*create an integer variable, name it ‘potValue' for ‘potentiometer value’,
*give it a value of 0. ‘0’ in this case represents the 0 voltage coming from A0 (analog port 0). 
*Remember, however, that this is just a word with a value.*/

int rled = 9;
int gled = 10;
int bled = 11;
/*In this step you are creating a variable for each of the pins of the RGB LED (rled for the red LED)
 *and assigning them to the pins they will be connected to (pin #9).*/

void setup() {
Serial.begin(9600); 
      
//This tells the arduino to begin transmitting serial data, take a look at the "TX" led while the program is running
    
pinMode(rled, OUTPUT);
pinMode(gled, OUTPUT);
pinMode(bled, OUTPUT);  
   
/*this sets the variables you defined earlier in the code as outputs,and since those variables are 
 *standins for the actual pins on the Arduino,this could be read as pinMode(9, output)*/
}

void loop() {
//loop everything between these brackets

potValue = analogRead(potPin); 
   
/*analogRead(), gives us the voltage of an analog pin on the board in very high detail. analogRead() will return a value between 0-1023, 
 *digitalRead() will return HIGH or LOW. analogRead(potPin); is the equivalent of writing analogRead(0) or do an analog read of pin A0 
 *Because we want to store the information from the analogRead() we can make potPin equal to it. This allows us to reference it later.*/ 
 
  if (potValue < 300)
    {
      digitalWrite(bled, HIGH);
    }

  else 
    {
      digitalWrite(bled, LOW);
    }
    
/*For this first if-else statement, we set the condition to be satisied when the potValue is between 0 and 299 (less than 300). 
 *You can view the potValue data by opening the serial monitor or serial plotter. The else statement is used to turn the LED off 
 *if potValue is higher than 299; it is important because the conditions set in the if statement would still be satisfied by a value 
 *higher than 299, and we want the blue LED to turn off after 299 so it moves to the next primary light color. 
 *The main goal is to have one and only one of the 3 colors in the LED on at all times*/
  
  if (potValue >= 300 && potValue <= 600)
    {
      digitalWrite(gled, HIGH);
    }

  else
    {
      digitalWrite(gled, LOW);
    }
    
/*This is similar to the first if-else statement, but take a look at the conditions laid out in the if statement. 
 *Instead of the greater than operator (>), we are using the greater than or equal to operator (>=) to include values from 300 up. 
 *After that, there is what is called a boolean operator (&&), in this case AND. This means that both conditions must be met to satisfy 
 *this if statment (think this AND that). What this entire conditional statement does is set an interval that satisfies the if statement. 
 *The reason for the additional AND operator is that if just left with the first condition, 
 *values higher than 300 would still make that condition true and that would mean more than one LED would be on at the same time.*/
 
  if (potValue > 600)
    {
      digitalWrite(rled, HIGH);
    }

  else 
    {
      digitalWrite(rled, LOW);
    }
    
/*This if-else statement is very similar to the first, in that its limited by the maximum output value of the potValue, which is 1023.
 *This maximum exists because potValue is pulled via the analogRead() function, and will only ever output values between 0 and 1023. 
 *This is also why we did not have to define the minimum of the first if-else statement, because we did not have another funtion that would  
 *be satisfied by the values in between 0 and 299 */    

Serial.println (potValue);
delay(20);

/*Serial.println (that's an L for line not an I for igloo) Using Serial.println at the end of a loop is a programming trick to help you 
 *see when a loop is done.This can also be helpful for troubleshooting or general feedback data. 
 *Open the "serial plotter" in the tools menu and take note of the changes that happen when you turn the potentiometer. 
 *Delay is also a programming trick that helps us avoid memory and speed problems with the arduino itself, 
 *once the arduino reaches this point in the code, it stops and waits the time specified in miliseconds.
 *Change the delay to a higher number, and watch what happens to the "TX" led.*/ 
    
}

