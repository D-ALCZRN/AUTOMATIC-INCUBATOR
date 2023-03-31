#include "library.h"
#include "variables.h"
#include "memorywipe.h"
#include "analogbutton.h"
#include "touchscreen.h"
 

void setup()
{
  Serial.begin(9600);
  pinMode(MENUBUTTON, INPUT_PULLUP);    //YELLOW BUTTON
  pinMode(RIGHTBUTTON,INPUT_PULLUP);    //RED BUTTON
  pinMode(LEFTBUTTON,INPUT_PULLUP);     //BLUE BUTTON
  
  pinMode(CANDLING,OUTPUT);             //LED STRIP
  pinMode(11,INPUT);                    //WATER LEVEL SENSOR
  pinMode(ALARMPIN,OUTPUT);             //BUZZER
  pinMode(HUMIDIFIERPIN,OUTPUT);        //HUMIDIFIER
  pinMode(WATERVALVE,OUTPUT);           //SOLENOID LOCK
  pinMode(FANPIN,OUTPUT);               //RTX FAN
  pinMode(MOTORPIN,OUTPUT);             //TURNING MOTOR
  pinMode(HEATERPIN,OUTPUT);            //LIGHT BULB
  
  initialisation();
  dht.begin();
  rtc.disable32K();
  rtc.clearAlarm(1);
  rtc.clearAlarm(2);
  rtc.disableAlarm(2);
  rtc.writeSqwPinMode(DS3231_OFF);
  title();
  digitalWrite(ALARMPIN,HIGH);
  delay(100);
  digitalWrite(ALARMPIN,LOW);
  delay(100);
  
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{
  
 touchscreen();
  
 }
