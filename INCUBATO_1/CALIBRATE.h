float CALIBRATE_TEMP = 37;
float CALIBRATE_TEMPTOLERANCE = 0.1;
float CALIBRATE_TEMPTRESHOLD = 0.1;

float CALIBRATE_HUMID = 60;
float CALIBRATE_HUMIDTOLERANCE = 5;
float CALIBRATE_HUMIDTRESHOLD = 1;

const int analogInPin = A0;
int sensorValue = 0;
 
void WATER_LEVEL_CHECK() {
sensorValue = analogRead(analogInPin);

  if((sensorValue>=100)&&(sensorValue<=650)){
    digitalWrite(WATERVALVE,LOW);
    }                                        // CRITITAL LEVEL

  else {
  digitalWrite(WATERVALVE,HIGH);
  }
}

void tfttest(){
long x, y;
  
  while (ts.dataAvailable() == true)
  {
    ts.read();
    x = ts.getX();
    y = ts.getY();
    if ((x!=-1) and (y!=-1))
    {
      tft.drawPixel (x, y,ILI9341_WHITE);
    }
  }
}

void CALIBRATE_TH (void) //CALIBRATE_TH
{
   temperature = dht.readTemperature();
   humidity = dht.readHumidity();
   lcd.setCursor(6,2);
   lcd.print(temperature);
   lcd.setCursor(7,3);
   lcd.print(humidity);
}

void CALIBRATETEM(void)
{

if (temperature==CALIBRATE_TEMP)
{

  //digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}
   else if ( (temperature>=(CALIBRATE_TEMP-CALIBRATE_TEMPTOLERANCE))&& (temperature<=(CALIBRATE_TEMP+CALIBRATE_TEMPTOLERANCE)) )
      {
        //digitalWrite(FANPIN,HIGH);
        digitalWrite(HEATERPIN,HIGH);
      }

CALIBRATE_TH();
  if (temperature>(CALIBRATE_TEMP+CALIBRATE_TEMPTOLERANCE))
          {
              digitalWrite(FANPIN,LOW);
              digitalWrite(HEATERPIN,HIGH);
          }

CALIBRATE_TH();
  if (temperature<(CALIBRATE_TEMP - CALIBRATE_TEMPTOLERANCE))
          {
            //digitalWrite(FANPIN,HIGH);
            digitalWrite(HEATERPIN,LOW);
                 
          }
                } 


void CALIBRATEHUMID(){

if (humidity==CALIBRATE_HUMID)
{

  digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}
   else if ( (humidity>=(CALIBRATE_HUMID-CALIBRATE_HUMIDTOLERANCE))&& (humidity<=(CALIBRATE_HUMID+CALIBRATE_HUMIDTOLERANCE)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
        digitalWrite(FANPIN,HIGH);
      }
CALIBRATE_TH();
  if (humidity>(CALIBRATE_HUMID+CALIBRATE_HUMIDTOLERANCE))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              digitalWrite(FANPIN,LOW);
             
          
          }
          
CALIBRATE_TH();
  if (humidity<(CALIBRATE_HUMID - CALIBRATE_HUMIDTOLERANCE))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            digitalWrite(FANPIN,HIGH);
          }}


//////////////////////////////////////////////////////////////////
void CALIBRATE()
{
  lcd.clear();
  tft.fillScreen(ILI9341_BLACK);
  do{
  
      lcd.setCursor(1,1);
      lcd.print("CALIBRATING BUTTON");
            
      if ((digitalRead(RIGHTBUTTON)==PRESSED))
          { lcd.clear();
            lcd.setCursor(2,1);
            lcd.print("RED BUTTON CLICK");
            delay(1000);
            lcd.clear();
            
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED))
          { lcd.clear();
            lcd.setCursor(1,1);
            lcd.print("BLUE BUTTON CLICK");
            delay(1000);
            lcd.clear();
          }

      if ((digitalRead(MENUBUTTON)==PRESSED))
          { lcd.clear();
            lcd.setCursor(0,1);
            lcd.print("YELLOW BUTTON CLICK");
            delay(1000);
            lcd.clear();
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED && digitalRead(LEFTBUTTON)== NOTPRESSED && digitalRead(RIGHTBUTTON)== NOTPRESSED);

   do{

}while (digitalRead(MENUBUTTON)== PRESSED && digitalRead(LEFTBUTTON)== PRESSED && digitalRead(RIGHTBUTTON)== PRESSED);
    


 do{ 
            
    if(!rtc.begin()) {
        lcd.print("NO RTC");
        delay(1000);
        lcd.clear();}
    else {
        lcd.setCursor(2,1);
        lcd.print("RTC IS OPERATING");
        delay(1000);
        lcd.clear();}
        
   
        
    }   while (digitalRead(MENUBUTTON)==NOTPRESSED);
   

do{}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();

  do{  
  lcd.setCursor(1,1);
  lcd.print("MOTOR IS ON");
  digitalWrite(MOTORPIN,LOW);
  delay(10000);
  digitalWrite(MOTORPIN,HIGH);
  lcd.clear();

  lcd.setCursor(0,1);
  lcd.print("HUMIDIFIERPIN IS ON");
  digitalWrite(HUMIDIFIERPIN,LOW);
  delay(5000);
  digitalWrite(HUMIDIFIERPIN,HIGH);
  lcd.clear();

  lcd.setCursor(1,1);
  lcd.print("CANDLING IS ON");
  digitalWrite(CANDLING,LOW);
  delay(5000);
  digitalWrite(CANDLING,HIGH);
  lcd.clear();
  
  }while (digitalRead(MENUBUTTON)==NOTPRESSED);

  
do{}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();
delay(2000);
  do{
  lcd.print("DRAW ON TOUCHSCREEN");
  tfttest();

  } while (digitalRead(MENUBUTTON)==NOTPRESSED);

do{}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();
tft.fillScreen(ILI9341_WHITE);
  
  lcd.setCursor(0,0);
  lcd.print("WATER LEVEL:");
  digitalWrite(ALARMPIN,LOW);
 
  do{
     
  
    sensorValue = analogRead(analogInPin);
    WATER_LEVEL_CHECK();

    Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\n");
    delay(1000);
    
  if((sensorValue>=500)){
    lcd.setCursor(4,2);
    lcd.print("           ");
    lcd.setCursor(0,2);
    lcd.print("FULL");
    }
    else {
    lcd.setCursor(8,2);
    lcd.print("           ");
    lcd.setCursor(0,2);
    lcd.print("CRITICAL");}

  } while (digitalRead(MENUBUTTON)==NOTPRESSED);
  
  
do{}while (digitalRead(MENUBUTTON)==PRESSED);

digitalWrite(ALARMPIN,LOW);
lcd.clear();
delay(2000);
lcd.setCursor(1,0);
lcd.print("DHT - CALIBRATION");

 do{
  
  
  lcd.setCursor(0,2);
  lcd.print("TEMP= ");
  lcd.setCursor(6,2);
  //lcd.print(temperature);
  lcd.setCursor(12,2);
  lcd.print((char) 223);
  lcd.setCursor(13,2);
  lcd.print("C");
  
  lcd.setCursor(0,3);
  lcd.print("HUMID= ");
  lcd.setCursor(7,3);
  lcd.print(humidity);
  lcd.setCursor(13,3);
  lcd.print("%");
  
  
  CALIBRATETEM();
  CALIBRATEHUMID();

  if(temperature <= CALIBRATE_TEMP+CALIBRATE_TEMPTOLERANCE && humidity <= CALIBRATE_HUMID+CALIBRATE_HUMIDTOLERANCE )
  {
  break;
  }
 
  }while(digitalRead(MENUBUTTON)== NOTPRESSED );

   do{}while (digitalRead(MENUBUTTON)== PRESSED );
   
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("CALIBRATION DONE");
  delay(2000);
  
}
 
