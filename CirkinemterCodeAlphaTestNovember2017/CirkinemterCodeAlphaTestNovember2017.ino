//---------OLED Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306();

//--------------Joystick Pins and Variables
int x = A0; //X axis pin
int y = A1; //Y axis pin
int xval = 0;
int yval = 0;
int oldXval =0;
int oldYval =0;
int speedval = 0;

//--------------TB66 Pins; MOTOR CONTROL
int Button_C=5;  //RPM control

//BO pins control direction
int BO1=6;  //BIN1
int BO2=9;  //BIN2
int pwmB=11;//int pwmB=5;

#define LEDPIN 13
int buttonCLED =12;
#define SENSORPIN 10

int count = 0;
float rps = 0.0, omega = 0.0;

int sensorState = 0, lastState = 0;       // variable for reading the pushbutton status
int buttoncount =0;
const int maxcount = 5;
unsigned long curtime = 0;

void setup() {
  pinMode(buttonCLED,OUTPUT);
  pinMode(Button_C, INPUT_PULLUP);
  
  //LED is an OUTPUT
  pinMode(LEDPIN, OUTPUT);

  // IR Receiver
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH); //This forces the sensor to activate for the first time, afterwards, only digital READS

  Serial.begin(115200);  //Speed of data being sent to Serial Monitor

  //OLED setup
  oledSetup();

  //Joystick
  pinMode(x, INPUT);  //gets values from joystick
  pinMode(y, INPUT);

  pinMode(BO1, OUTPUT);  //sends values to TB66
  pinMode(BO2, OUTPUT);  //sends values to TB66
}

void loop() {
/* -- Changed on 11/19 because these are don in the countRevs while loop anyway----
  xval = analogRead(x);
  yval = analogRead(y);
  getSetSpeed();
  getSetDirection();
 ---------- end 11/19 change ---*/
  curtime = millis();
  countRevs();
  
   if (count == maxcount)
    {
      publishRPS();
    }
}

