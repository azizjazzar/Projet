// include the library code:
#include <LiquidCrystal.h>

char data;

// initialize the library by associating any needed LCD interface pin with the arduino pin number it is connected to
const int rs = 1, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
//rs pin , enable pin , register D4 , register D5 , register D6 , register D7
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//initialize the LCD and set dimensions
void setup() {
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  Serial.begin(9600);
 }

void loop() {
// set the cursor to column 2, line 0
 lcd.setCursor(2,0);
if (Serial.available())
{
  data=Serial.read();
  if (data=='2')
  {
    // Print the message to the LCD.
     lcd.print("en retard");
     delay (1500);
 
  }
 if (data== '3') 
  {
    // Print the message to the LCD.
     lcd.print("termine");
     delay (1500);
  }
}
 

 lcd.clear();
}
