#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp;   
int threshold=55;
void setup()
{
  
 lcd.begin(16, 2); 
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   sensorInput = analogRead(A0);    
  temp = (double)sensorInput / 1024;      
  temp = temp * 5;                
  temp = temp - 0.5;               
  temp = temp * 100;               
 
  Serial.print("Current Temperature: ");
  Serial.println(temp);
  
  lcd.setCursor(0,0);          
  lcd.print("current temp="); 
  lcd.setCursor(2,1);           
  lcd.print(temp); 

  if(temp<20)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(8,LOW);
    }
    else if(temp>=20 && temp<55)
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    }
    else if(temp>=threshold)
  {
    ;
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    tonechecker();
    
    }
  }

  tonechecker()
  {
    tone(13,400,15);
    }
