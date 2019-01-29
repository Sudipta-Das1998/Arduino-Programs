

// include the library code:
#include <LiquidCrystal.h>
int a=0;
int b=15;
int 
LiquidCrystal lcd (12,11,5,4,3,2);

void setup()
{
  lcd.begin(16,2);
 lcd.print('A');
 lcd.setCursor(15,0);
 lcd.print('B');
 while((a<=9)&&(b>=8))
 {
  lcd.clear();
  lcd.setCursor(a,0);
  lcd.print('A');
  lcd.setCursor(b,0);
  lcd.print('B
  ');
  a++;
  b--;
  delay(100);
  
  
 }
  
  
}
void loop()
{

}

