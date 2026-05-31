#include<String.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int IN1=27;
int IN2=26;
int IN3=25;
int IN4=33;

int SW5=23; //Ground Floor
int SW6=12;
//1st Floor

int SW3=14;  //Ground Floor
int SW4=32;   //2nd Floor

int SW1=18;    //1st Floor
int SW2=19;    //2nd Floor


int IR1=15; //Ground
int IR2=4;  //First
int IR3=5;
//Second


char ch;
String readvoice;

int a,b,c;
void setup() 
{
  
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  pinMode(SW3,INPUT_PULLUP);
  pinMode(SW4,INPUT_PULLUP);
  pinMode(SW5,INPUT_PULLUP);
  pinMode(SW6,INPUT_PULLUP);

  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);


  Serial.begin(9600); 
  Serial2.begin(9600);
  
  lcd.init();                      // Initialize the LCD
  lcd.backlight(); 
  lcd.clear();
  lcd.print("Smart Lift");//Initialize serial
  Serial.println("Smart Lift");
  delay(2000);
//UP();
//delay(30000);
// UP_DOWN_STOP();
//  delay(2000);
//
//Door_Open();
//delay(3000);
//Door_Close();
}

void loop() 
{
  
  Voice_Mode();

}
void Voice_Mode()
{
  
  lcd.clear();
  lcd.print("Give Voice");
  Serial.println("$Give Voice...#");
  while(1)
  {  
     while(Serial2.available())
     {
        delay(10);
        char ch=Serial2.read();
        readvoice+=ch;
     }
        Serial.println(readvoice);
        //  delay(1000);
      if (readvoice== "First"||readvoice== "first"||readvoice== "1st")
      {
         Voice_First_floor();
      }
      if (readvoice== "Second"||readvoice== "second"||readvoice== "2nd")
      {
         Voice_Second_floor();
      }
      if (readvoice== "Ground"||readvoice== "ground"||readvoice== "ground floor")
      {
          Voice_Ground_floor();
      }
  
       readvoice="";
       Switch_Check();
  } 

}
void Voice_First_floor()
{
  if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Groud Floor to First Floor");
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      First_floor_G();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
  
}
void Voice_Second_floor()
{
  if(digitalRead(IR1)==LOW)
    {
     
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Second_floor_G();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
      if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }

}
void Voice_Ground_floor()
{
   if(digitalRead(IR3)==LOW)
    {
    
      
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Ground_floor_2();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
      Second_floor_1();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Ground Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
  
}
void Door_Open()
{
  lcd.clear();
  lcd.print("Door Open");
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(6000);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  delay(500);
  
}
void Door_Close()
{
  lcd.clear();
  lcd.print("Door Close");
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(6000);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  delay(500);
  
}
void First_floor_G()
{
  UP();
  delay(180*1000);
  UP_DOWN_STOP();
}
void Second_floor_G()
{
  UP();
  delay(360*1000);
  UP_DOWN_STOP();
}
void Ground_floor_2()
{
  DOWN();
  delay(360*1000);
  UP_DOWN_STOP();
}
void Ground_floor_1()
{
  DOWN();
   delay(180*1000);
  UP_DOWN_STOP();
}

void First_floor_2()
{
  DOWN();
   delay(180*1000);
  UP_DOWN_STOP();
}
void Second_floor_1()
{
  UP();
  delay(180*1000);
  UP_DOWN_STOP();

}

void Switch_Check()
{
  if((digitalRead(SW1)==LOW))
  {
    if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Groud Floor to First Floor");
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      First_floor_G();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    
   
  }
  if((digitalRead(SW2)==LOW))
  {
    if(digitalRead(IR1)==LOW)
    {
     
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Second_floor_G();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
      if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Groud Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Groud Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
   
  }
  if((digitalRead(SW3)==LOW))
  {
   if(digitalRead(IR2)==LOW)
    {
     
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Ground_floor_1();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Second Floor to First Floor");
      delay(1000);
      First_floor_2();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
      if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
       Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("First Floor to Ground Floor");
      delay(1000);
      Ground_floor_1();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
   
  }
  if((digitalRead(SW4)==LOW))
  {
   if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Ground Floor to First Floor");
      delay(1000);
      First_floor_G();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
      Second_floor_1();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
   
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Second_floor_1();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
     if(digitalRead(IR3)==LOW)
    {
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Second Floor to First Floor");
      delay(1000);
      First_floor_2();
      delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
      Second_floor_1();
      delay(2000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
   
  }
  if((digitalRead(SW5)==LOW))
  {
    if(digitalRead(IR3)==LOW)
    {
    
      
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      Ground_floor_2();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
      Second_floor_1();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Ground Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to Ground Floor");
      delay(1000);
      Ground_floor_2();
      delay(2000);
        Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
   
  }
   if((digitalRead(SW6)==LOW))
  {
    if(digitalRead(IR3)==LOW)
    {
      
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to First Floor");
      Serial.println("Second Floor to First Floor");
      delay(1000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      First_floor_2();
       delay(2000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR2)==LOW)
    {
      lcd.clear();
      lcd.print("First Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("First Floor to Second Floor");
      delay(1000);
      Second_floor_1();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to First Floor");
      delay(1000);
      First_floor_2();
      delay(2000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
    if(digitalRead(IR1)==LOW)
    {
      lcd.clear();
      lcd.print("Ground Floor");
      lcd.setCursor(0,1);
      lcd.print("to Second Floor");
      Serial.println("Ground Floor to Second Floor");
      delay(1000);
      Second_floor_G();
      delay(1000);
      Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
      lcd.clear();
      lcd.print("Second Floor");
      lcd.setCursor(0,1);
      lcd.print("to Ground Floor");
      Serial.println("Second Floor to First Floor");
      delay(1000);
      First_floor_2();
      delay(2000);
         Door_Open();
      delay(2000);
      Door_Close();
      delay(2000);
    }
   
  }
  

}

void UP()
{
  Serial.println("UP...");
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
}
void DOWN()
{
  Serial.println("DOWN...");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
}
void UP_DOWN_STOP()
{
  Serial.println("UP DOWN STOP...");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}
