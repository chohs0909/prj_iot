String inputString = "";
unsigned int x = 0;
unsigned int y = 0;


#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup()
{
  inputString.reserve(16);
  Serial.begin(9600);
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
lcd.print("     Hello");
lcd.setCursor(5, 1);
lcd.print("World!");
lcd.clear();
}
void loop()
{
 while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar != '\n') {
     inputString += inChar;
     lcd.print(inputString);
    }
    else {
      Serial.println(inputString);
      lcd.print(inputString);
      if(x < 16) x++;
      else x = 0;
      lcd.setCursor(x, y);
      inputString = "";
    }
  }
}
