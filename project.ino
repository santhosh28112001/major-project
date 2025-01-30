#include <Servo.h>
Servo myservo1;  
Servo myservo2;

#include <LiquidCrystal.h>
#include <stdio.h>


LiquidCrystal lcd(6, 7, 5, 4, 3, 2);


int ir1 = 12;
int ir2 = 13;

int buzzer = A0;

int red_led    = 10;
int yellow_led = 11;


int sti=0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void beep()
{
  digitalWrite(buzzer, LOW);delay(1000);digitalWrite(buzzer, HIGH);
}
 
void setup() 
{
 Serial.begin(9600);//serialEvent();
    
    myservo1.attach(8);
    myservo2.attach(9);
    pinMode(ir1, INPUT);
    pinMode(ir2, INPUT);
    pinMode(buzzer, OUTPUT); // Sets the trigPin as an Output
    pinMode(red_led, OUTPUT);
    pinMode(yellow_led, OUTPUT);
    
   digitalWrite(buzzer, HIGH);
   myservo1.write(10); 
   myservo2.write(10);
   digitalWrite(red_led, HIGH);
   digitalWrite(yellow_led, HIGH);

  lcd.begin(16, 2);lcd.cursor();
  lcd.print("Railway Gate Control");
  delay(2000);
  
   lcd.clear();
   lcd.setCursor(0,0);
   
   digitalWrite(red_led, HIGH);digitalWrite(yellow_led, LOW);
}

void loop() 
{
  if(digitalRead(ir1) == LOW)
    {
      digitalWrite(red_led, LOW);digitalWrite(yellow_led, HIGH);
      
      lcd.setCursor(0,0);lcd.print("Train Coming ");
      lcd.setCursor(0,1);lcd.print("Gate Close    ");
      myservo1.write(120);myservo2.write(120); 
       delay(2000);
     
     while(digitalRead(ir2) == HIGH);
    
     lcd.setCursor(0,0);lcd.print("Train Going  ");
     lcd.setCursor(0,1);lcd.print("Gate Open    ");
     myservo1.write(10);myservo2.write(10); 
       delay(2000);
       
     digitalWrite(red_led, HIGH);digitalWrite(yellow_led, LOW);
       delay(12000);
    }

  if(digitalRead(ir2) == LOW)
    {
      digitalWrite(red_led, LOW);digitalWrite(yellow_led, HIGH);
      
      lcd.setCursor(0,0);lcd.print("Train Coming ");
      lcd.setCursor(0,1);lcd.print("Gate Close    ");
      myservo1.write(120);myservo2.write(120); 
       delay(2000);
     
     while(digitalRead(ir1) == HIGH);
    
     lcd.setCursor(0,0);lcd.print("Train Going  ");
     lcd.setCursor(0,1);lcd.print("Gate Open    ");
     myservo1.write(10);myservo2.write(10); 
       delay(2000);
       
     digitalWrite(red_led, HIGH);digitalWrite(yellow_led, LOW);
      delay(12000);
    }  
    
  delay(500);  
}


void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   Serial.write(a);
   Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   lcd.write(a);
   lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}

void convertk(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
  // lcd.write(a);
  // lcd.write(c);
  // lcd.write(e); 
  // lcd.write(g);
   lcd.write(h);
}
