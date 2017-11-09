// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int toggleBtnPin = 9;
int confirmBtnPin = 10;
char* names[] = {"Brian Henderson","Zach Toner","Drew Burns","Tanner Senius","Jon Coogan"};
int currIndex = 0;
int arrSize = sizeof(names)/sizeof(names[0]);


void setup() {
  // set button pins
  pinMode(toggleBtnPin, INPUT);
  pinMode(confirmBtnPin, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(names[currIndex]);
}

void loop() {
  // set the cursor to column 0, line 1
  if(digitalRead(toggleBtnPin) == HIGH) {
    currIndex ++;
    if(currIndex == arrSize) {
      currIndex = 0;
    }
    lcd.clear();
    // set the cursor to column 0, line 1
    lcd.setCursor(0, 0);
    lcd.print(names[currIndex]);
    // set cursor to coloumn 0, line 2
    lcd.setCursor(0, 2);
    delay(100);
  }

  if(digitalRead(confirmBtnPin) == HIGH){
    Serial.print(names[currIndex]);
  }
}