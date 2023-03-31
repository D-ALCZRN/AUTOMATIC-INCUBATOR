#include <Arduino.h>
#include <Adafruit_Sensor.h>

#include "Adafruit_GFX.h"     
#include "Adafruit_ILI9341.h" 
#include "URTouch.h"    

#include "DHT.h"
#define DHTPIN A3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#include "RTClib.h"
#include <TimerOne.h>
RTC_DS3231 rtc; //rtc type
LiquidCrystal_I2C lcd(0x27,20,4); 
  
#define MENUBUTTON 4
#define RIGHTBUTTON 5
#define LEFTBUTTON 3 // YELLOW



//#define WATERSENSOR A4
#define CANDLING 12
#define ALARMPIN 6
#define HUMIDIFIERPIN 14
#define WATERVALVE 15
#define FANPIN 16
#define MOTORPIN 17
#define HEATERPIN 18

#define NOTPRESSED 1
#define PRESSED  0




#define TFT_DC 33          
#define TFT_RST 35

// MUST SPI
#define TFT_MISO 50         
#define TFT_MOSI 51          
#define TFT_CLK 52 
#define TFT_CS 53
        
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK  
, TFT_RST, TFT_MISO);

#define t_IRQ 23
#define t_MISO 25    
#define t_MOSI 27
#define t_CS 29 
#define t_SCK 31                 
              
URTouch ts(t_SCK, t_CS, t_MOSI, t_MISO, t_IRQ);

//extern uint8_t BigFont[];

int x, y;
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";
