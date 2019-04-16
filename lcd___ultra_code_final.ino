 /*LCD circuit:
   LCD RS pin to digital pin 1
   LCD Enable pin to digital pin 2
   LCD D4 pin to digital pin 6
   LCD D5 pin to digital pin 5
   LCD D6 pin to digital pin 4
   LCD D7 pin to digital pin 3
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
  trigger pin =12
  echo pin = 13

*/



#include<LiquidCrystal.h>

LiquidCrystal lcd(7, 2, 6, 5, 4, 3); //Interface pins of the LCD
const int trig_pin = 12;
const int echo_pin = 13;
long int h1, h2;
long  distance1 = 0, distance2 = 0, phase1, phase2, weight, vol_of_water, duration, water_rise, switchPin, bellPin, buttonPin=8, low, high;

void setup() {
  pinMode(buttonPin, INPUT);
  //pinMode(bellPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0); //set the cursor to column 0 and line 0
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
  lcd.clear();
}


void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW)
  {
    lcd.clear();
    distance1=50;
//    digitalWrite(trig_pin, LOW);
//    delayMicroseconds(2);
//    digitalWrite(12, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(12, LOW);
//    duration = pulseIn(echo_pin, HIGH); //To receive the reflected signal.
//    distance1 = duration * 0.034 / 2;
//    Serial.println(distance1);
  }
  else
  {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(12, HIGH);
    delayMicroseconds(10);
    digitalWrite(12, LOW);
    duration = pulseIn(echo_pin, HIGH); //To receive the reflected signal.
    distance2 = duration * 0.034 / 2;
    Serial.println(distance2);

    lcd.clear();

    h1 = distance1;
    phase1 = 3.14285714285 * 10 * 10 * h1;
    //r=10 h1= initial water height
    distance2 = duration * 0.034 / 2;
    h2 = distance2;
    phase2 = 3.14285714285 * 10 * 10 * h2;
    //r=10 h2 = final water rise
    vol_of_water = h1 - h2;
    weight = phase1 - phase2;





    //Serial.println(distance);
    lcd.setCursor(0, 0); //set the cursor to column 0 and line 1
    lcd.print("water_rise=");
    lcd.print(vol_of_water);
    lcd.print("cc");
    lcd.setCursor(0, 1); //set the cursor to column 0 and line 1
    lcd.print("weight=");
    lcd.print(weight = weight);
    lcd.print("gm");

    delay(1000);
  }
} 
