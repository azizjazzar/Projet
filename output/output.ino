#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
char data='0';
  
void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();

   Serial.begin(9600);
   pinMode(3,INPUT);
  
}

void loop()
{ 
          if((digitalRead(3)==HIGH)&&(data!='1'))
              {
                Serial.write('1');
                data='1';
              }
        else if((digitalRead(3)==LOW)&&(data!='0'))
              {
                Serial.write('0');
                data='0';
              }
       delay(5);
  if (Serial.available())
{
  data=Serial.read();
  if (data=='2')
  {
    // Print the message to the LCD.
    lcd.setCursor(4,0);
    lcd.print("Voyage");
    lcd.setCursor(3,1);
     lcd.print("en retard");
     delay (3000);
     lcd.clear();
 
  }
 if (data== '3') 
  {
    // Print the message to the LCD.
     
     lcd.setCursor(4,0);
    lcd.print("Voyage");
    lcd.setCursor(4,1);
    lcd.print("termine");
     delay (3000);
     lcd.clear();
  }
}



}
