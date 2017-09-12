/* 4-Phase 5-Wire Stepper Motor (28BYJ-48) [D021] : http://rdiot.tistory.com/284 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
const int stepsPerRevolution = 2048; // 2048:(360 Degree), 1024:(180 degree)

// ULN2003 IN4, IN2, IN3, IN1
Stepper myStepper(stepsPerRevolution,11,9,10,8); 

int val;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  delay(1000);
  
  myStepper.setSpeed(14); 
  lcd.clear();
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("D021:28BYJ-48");
  lcd.setCursor(0,1);
  lcd.print("B002:X113647");

  // Left 1 round
  myStepper.step(stepsPerRevolution);
  val = stepsPerRevolution;
  lcd.setCursor(0,2);
  lcd.print("right=" + (String)val + "  ");
  delay(500);

  // Right 1 round
  myStepper.step(-stepsPerRevolution);
  val = -stepsPerRevolution;
  lcd.setCursor(0,2);
  lcd.print("left=" + (String)val + "   ");
  delay(500);
}
