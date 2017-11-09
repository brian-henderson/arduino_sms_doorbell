// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int toggleBtnPin = 9;
int confirmBtnPin = 10;
char* contactNames [] = {"Brian Henderson","Zach Toner","Drew Burns","Tanner Senius","Jon Coogan"};
char* contactNumbers[] = {"7323433511", "5165927041", "5185066268", "8452690469", "5187286461"};
int currIndex = 0;
int arrSize = sizeof(contactNames)/sizeof(contactNames[0]);


void setup() {
  // set button pins and type
  pinMode(toggleBtnPin, INPUT);
  pinMode(confirmBtnPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(contactNames[currIndex]);
}

void loop() {
  // set the cursor to column 0, line 1
  if(digitalRead(toggleBtnPin) == HIGH) {
    lcd.clear();
    currIndex ++;
    if(currIndex == arrSize) {
      currIndex = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print(contactNames[currIndex]);
    delay(200);
  }

  if(digitalRead(confirmBtnPin) == HIGH){
    lcd.setCursor(0, 1);
    lcd.print(contactNumbers[currIndex]);
  }
}
