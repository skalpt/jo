#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

String message = "Dear Jo, happy 18th birthday from your father in the year 2013! It is hard to imagine what you and the world around you will be like in 2030. The only thing I am certain of is that I will have loved you from the moment I wrote this message to the moment you are reading it.";
int screenSize = 16;
int pos = -screenSize;
long delayTimer = 0;
int scrollDelay = 400;

int loveMode = 0;
int loveDelay = 1000;
int loveCount = 0;
int loveRepeat = -1;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1,heart);
  lcd.clear();
}

void loop() {
  if (loveMode == 0 && millis() - delayTimer >= scrollDelay) {
    if (pos > 0 && pos > message.length()) {
      pos = -screenSize;
      loveMode = 1;
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("LOVE");
      lcd.setCursor(7, 1);
      lcd.print("YOU");
    } else {
      delayTimer = millis();
      if (pos < 0) {
        lcd.setCursor(-pos, 0);
        lcd.print(message.substring(0, screenSize + pos));
      } else {
        lcd.setCursor(0, 0);
        lcd.print(message.substring(pos, pos + 16));
      }
      if (message.length() - pos < 16) {
        lcd.print(" ");
      }
    pos++;
    }
  }
  if (loveMode == 1 && millis() - delayTimer >= loveDelay) {
    delayTimer = millis();
    loveCount++;

    lcd.setCursor(0, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(2, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(4, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(10, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(12, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(14, 0);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(1, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(3, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(5, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(11, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(13, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }
    lcd.setCursor(15, 1);
    if (loveCount % 2 == 1) {
      lcd.write(1);
    } else {
      lcd.print(" ");
    }

    if (loveCount == loveRepeat) {
      loveCount = 0;
      loveMode = 0;
      delayTimer = millis();
      lcd.clear();
    }
  }
}
