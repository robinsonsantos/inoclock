/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include <TimerOne.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int seconds;
int minutes;
int hours;

void setup() {
  
  seconds = 0;
  minutes = 58;
  hours = 23;
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(8, 2);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("Is Alive");
  
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(update);
}

void loop() {
  // Main loop code
}

void update() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
  
  seconds++;
  if (seconds >= 60)
  {
    minutes++;
    seconds = 0;
  }
  
  if (minutes >= 60)
  {
    hours++;
    minutes = 0;
  }
  
  if (hours >= 24)
  {
    hours = 0;
  }
  
  if (hours < 10)
  {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");
  
  if (minutes < 10)
  {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  
  if (seconds < 10)
  {
    lcd.print("0");
  }
  lcd.print(seconds);
}

