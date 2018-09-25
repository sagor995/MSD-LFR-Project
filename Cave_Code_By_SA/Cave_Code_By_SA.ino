int ledArray=6;
int ldr=A5;
int value = 0;
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);  //Create Liquid Crystal Object called LCD
long duration;

int myCounter=0;  //declare your variable myCounter and set to 0

float Duration;  //time for ping to travel from sensor to target and return
float Distance; //Distance to Target in inches

void setup() {
Serial.begin(9600);
pinMode(ldr, INPUT);
pinMode(ledArray, OUTPUT);
LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("Smart LFR Car");  //Print Message on First Row
}
void loop() {
  
  value= analogRead(ldr);
 Serial.println("Intensity of the LDR is =");
 Serial.println(value);

 
  if(value <= 500){
      digitalWrite(ledArray, HIGH);   // turn the LED on (HIGH is the voltage level)
    LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  LCD.print("LFR In!!!!!"); //Print measured distance
  LCD.blink();
  delay(5000); //pause to let things settle

      }
      else{
     digitalWrite(ledArray, LOW);   // turn the LED on (HIGH is the voltage level)
     
    LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  LCD.print("LFR OUT!!!!!"); //Print measured distance
  LCD.blink();
  //delay(0); //pause to let things settle
    
    }



    

   
  }  
