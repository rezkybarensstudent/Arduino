#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int sensorPin = A0; // Choose the input pin (for Gas Sensor)  
int buzzer = 13; // Choose the pin for the Buzzer
int G_led = 8; // Choose the pin for the Green LED
int R_led = 9; // Choose the pin for the Red LED


int read_value; // Variable for reading the gaspin status
int set = 50;  // 2e start, assuming Smoke detected

void setup(){ 
pinMode(sensorPin, INPUT); // Declare sensor as input

pinMode(buzzer,OUTPUT); // Declare Buzzer as output 
pinMode(R_led,OUTPUT); // Declare Red LED as output
pinMode(G_led,OUTPUT); // Declare Green LED as output

lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("   Welcome To   ");
lcd.setCursor(0,1);
lcd.print("  Gas Leak Detector  ");
delay(2000);
lcd.clear();
}

void loop(){
read_value = (analogRead(sensorPin)); // Read input value

read_value = read_value - 50;
if(read_value<0){read_value=0;}

lcd.setCursor(0, 0);
lcd.print("Smoke/Gas Level: ");
lcd.print(read_value);
lcd.print("  ");

if(read_value>set){ // Check if the Smoke variable is High
lcd.setCursor(0, 1);
lcd.print("Alert....!!!    ");    
digitalWrite(buzzer, HIGH); // Turn LED on.  
digitalWrite(R_led, HIGH); // Turn LED on.
digitalWrite(G_led, LOW); // Turn LED off.
delay(1000);
}

if(read_value<set){ // Check if the Smoke variable is Low
lcd.setCursor(0, 1);
lcd.print(".....Normal.....");   
digitalWrite(buzzer, LOW); // Turn LED on.  
digitalWrite(R_led, LOW); // Turn LED on.
digitalWrite(G_led, HIGH); // Turn LED on.
}
delay(100);
}
