int pin;
const int RightReverse = 8;
const int RightForward = 9;
const int LeftForward = 10;
const int LeftReverse = 11;

int trig = A6;
int echo = A7;


int pos = 0;
int duration = 0;
int distance = 0;

int sensors[6]={A5,A4,A3,A2,A1,A0};
int sensorsD[6]={14,15,16,17,18,19};
int values[6];
int valuesD[6];

int black_value=750;
void setup() {
  for(pin=22; pin<=32; pin++ )
{
  pinMode(pin,OUTPUT);
}
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftReverse, OUTPUT);
  pinMode(RightForward, OUTPUT);
  pinMode(RightReverse, OUTPUT);
  pinMode(sensors[0],INPUT); 
  pinMode(sensors[1],INPUT);
  pinMode(sensors[2],INPUT);
  pinMode(sensors[3],INPUT);
  pinMode(sensors[4],INPUT);
  pinMode(sensors[5],INPUT);

  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  Serial.begin(9600);
}

void loop() {
Serial.print("Values: ");
for (int i = 0; i < 6; i++)
  {
    Serial.print(" ");
    Serial.print(analogRead(sensors[i]));
    delay(10);
  }
  Serial.println("");

   digitalWrite(trig , HIGH);
  delayMicroseconds(100);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
 
  //Move forward Condition
  if(((analogRead(sensors[2])>black_value ) && (analogRead(sensors[3])>black_value)&&(analogRead(sensors[4])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[5])<black_value))
    ||((analogRead(sensors[1])>black_value ) && (analogRead(sensors[2])>black_value)&&(analogRead(sensors[3])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))
    ||((analogRead(sensors[2])>black_value ) && (analogRead(sensors[3])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value)) 
  ||((analogRead(sensors[2])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))
  ||((analogRead(sensors[3])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))){
     if(distance < 11  && distance>7){

      a_o();
     }
     
     digitalWrite(LeftForward,HIGH);
     digitalWrite(RightForward,HIGH);
     digitalWrite(LeftReverse,LOW);
      digitalWrite(RightReverse,LOW);
     
      for(pin=22; pin<=32; pin++ )
      {
        digitalWrite (pin, HIGH);
       tone(12,100000); // Send 1KHz sound signal...
    delay(10);
        digitalWrite (pin,LOW);
      }
    }else

  //Back2Line From  LEFT
  if(((analogRead(sensors[1])>black_value ) && (analogRead(sensors[2])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))
  || ((analogRead(sensors[1])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))){
     digitalWrite(LeftForward,LOW);
     digitalWrite(RightForward,HIGH);
     digitalWrite(LeftReverse,HIGH);
      digitalWrite(RightReverse,LOW);
      for(pin=22; pin<=32; pin++ )
      {
        digitalWrite (pin, HIGH);
        tone(12,100000); // Send 1KHz sound signal...
    delay(10);
        digitalWrite (pin,LOW);
      }
       
      
    }else

     //Back2Line From RIGHT
if(((analogRead(sensors[3])>black_value ) && (analogRead(sensors[4])>black_value)&&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[5])<black_value))
|| ((analogRead(sensors[4])>black_value) &&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[5])<black_value))){
    digitalWrite(LeftForward,HIGH);
   digitalWrite(RightForward,LOW);
   digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,HIGH);
    for(pin=22; pin<=32; pin++ )
      {
        digitalWrite (pin, HIGH);
          tone(12,100000); // Send 1KHz sound signal...
    delay(10);
        digitalWrite (pin,LOW);
      }
      
      }else
 //Turning LEFT
if(((analogRead(sensors[1])>black_value)&&(analogRead(sensors[2])>black_value ) && (analogRead(sensors[3])>black_value) &&(analogRead(sensors[4])>black_value) && (analogRead(sensors[5])>black_value) &&(analogRead(sensors[0])<black_value))
||((analogRead(sensors[2])>black_value ) && (analogRead(sensors[3])>black_value) &&(analogRead(sensors[4])>black_value) && (analogRead(sensors[5])>black_value) &&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value))
      ||((analogRead(sensors[3])>black_value) &&(analogRead(sensors[4])>black_value) && (analogRead(sensors[5])>black_value) &&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)) 
      || ((analogRead(sensors[4])>black_value) && (analogRead(sensors[5])>black_value) &&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value))
      ||((analogRead(sensors[5])>black_value) &&(analogRead(sensors[0])<black_value)&&(analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value))){
        digitalWrite(LeftForward,HIGH);
     digitalWrite(RightForward,LOW);
     digitalWrite(LeftReverse,LOW);
      digitalWrite(RightReverse,LOW);
      
       for(pin=32; pin>=22; pin-- ){
  digitalWrite (pin, HIGH);
   tone(12,11000); // Send 1KHz sound signal...
    delay(10);
  digitalWrite (pin,LOW);
}
        }else
 //Turning RIGHT
if(((analogRead(sensors[0])>black_value ) && (analogRead(sensors[1])>black_value) &&(analogRead(sensors[2])>black_value) && (analogRead(sensors[3])>black_value) &&(analogRead(sensors[4])>black_value)&&(analogRead(sensors[5])<black_value))||
  ((analogRead(sensors[0])>black_value ) && (analogRead(sensors[1])>black_value) &&(analogRead(sensors[2])>black_value) && (analogRead(sensors[3])>black_value) &&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))
      ||((analogRead(sensors[0])>black_value) &&(analogRead(sensors[1])>black_value) && (analogRead(sensors[2])>black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value)) 
      || ((analogRead(sensors[0])>black_value) && (analogRead(sensors[1])>black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))
      ||((analogRead(sensors[0])>black_value) && (analogRead(sensors[1])<black_value)&&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value))){
          digitalWrite(LeftForward,LOW);
     digitalWrite(RightForward,HIGH);
     digitalWrite(LeftReverse,LOW);
      digitalWrite(RightReverse,LOW);
        for(pin=32; pin>=22; pin-- ){
  digitalWrite (pin, HIGH);
   tone(12,11000); // Send 1KHz sound signal...
    delay(10);
  digitalWrite (pin,LOW);
}
        }else
//WAIT
if((analogRead(sensors[0])<black_value) &&(analogRead(sensors[1])<black_value) &&(analogRead(sensors[2])<black_value)&&(analogRead(sensors[3])<black_value)&&(analogRead(sensors[4])<black_value)&&(analogRead(sensors[5])<black_value)){
         digitalWrite(LeftForward,LOW);
     digitalWrite(RightForward,LOW);
     digitalWrite(LeftReverse,HIGH);
      digitalWrite(RightReverse,HIGH);
      tone(12,100000); // Send 1KHz sound signal...
    delay(10);
        }
        

}


void a_o(){
    digitalWrite(LeftForward,HIGH);
    digitalWrite(RightForward,LOW);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(1000);

    digitalWrite(LeftForward,HIGH);
    digitalWrite(RightForward,HIGH);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(500);

    digitalWrite(LeftForward,LOW);
    digitalWrite(RightForward,HIGH);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(800);

    digitalWrite(LeftForward,HIGH);
    digitalWrite(RightForward,HIGH);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(500);

    digitalWrite(LeftForward,LOW);
    digitalWrite(RightForward,HIGH);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(900);

    digitalWrite(LeftForward,HIGH);
    digitalWrite(RightForward,LOW);
    digitalWrite(LeftReverse,LOW);
    digitalWrite(RightReverse,LOW);
    delay(500);
  
  }

