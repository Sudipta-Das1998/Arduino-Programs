#include<LiquidCrystal.h>
char a;

 
  // put your setup code here, to run once:
 LiquidCrystal lcd(12,11,5,4,3,2);
 void setup()
 {
  lcd.begin(16,2);
  Serial.begin(9600);
 
 
  }
 

void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available()>0)
   {
     a=Serial.read();
     Serial.print(a);
     
    lcd.print(a);

   /* if(a==8)
    {
   lcd.clear();
    }*/
          
    
   } 

}
