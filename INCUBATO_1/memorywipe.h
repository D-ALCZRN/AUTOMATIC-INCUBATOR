
void milsecdelay(){

    if (millisflag){
      millisflag=0;
      count =millis();
    }

    count1=millis();
    if ((count1-count)>=50)
    {
      // action
      millisflag=1;}}

void initialisation(void)
{
 

delay(20);
EEPROM.put(reftempaddress,REFTEMPERATURE);
delay(20);
EEPROM.put(reftemptoladdress,REFTEMPTOLERANCE);
delay(20);
EEPROM.put(refhumidaddress,REFHUMIDITY);
delay(20);
EEPROM.put(refhumidtoladdress,refhumidtoladdress);
delay(20);
EEPROM.put(reftemptresholdaddress,REFTEMPTRESHOLD);
delay(20);
EEPROM.put(refhumidtresholddadress,REFHUMIDTRESHOLD);
delay(20);

EEPROM.write(NoINCUBATIONDAYSaddress,NoINCUBATIONDAYS);
delay(20);
EEPROM.write(tspinaddress,TSPIN);
delay(20);
EEPROM.write(spinaddress, SPIN);
delay(20);
EEPROM.write(Noincubationdaysleftaddress,NoINCUBATIONDAYSLEFT);
delay(20);

EEPROM.write(tspinaddress,2);
delay(20);
EEPROM.write(timeduringrotationaddress,timeduringrotation);



// should be uncumented after first upload
 delay(20);
EEPROM.get(reftempaddress,REFTEMPERATURE);
delay(20);
EEPROM.get(reftemptoladdress,REFTEMPTOLERANCE);
delay(20);
EEPROM.get(refhumidaddress,REFHUMIDITY);
delay(20);
EEPROM.get(refhumidtoladdress,refhumidtoladdress);
delay(20);
EEPROM.get(reftemptresholdaddress,REFTEMPTRESHOLD);
delay(20);
EEPROM.get(refhumidtresholddadress,REFHUMIDTRESHOLD);
delay(20);

NoINCUBATIONDAYS = EEPROM.read(NoINCUBATIONDAYSaddress);
delay(20);
TSPIN = EEPROM.read(tspinaddress);
delay(20);
SPIN = EEPROM.read(spinaddress);
delay(20);
timeduringrotation = EEPROM.read(timeduringrotationaddress);
delay(20);

NoINCUBATIONDAYSLEFT = EEPROM.read(Noincubationdaysleftaddress);
delay(20);

digitalWrite(ALARMPIN,HIGH);
delay(500);
digitalWrite(ALARMPIN,LOW);

digitalWrite(CANDLING,LOW);

digitalWrite(HUMIDIFIERPIN,HIGH);
digitalWrite(WATERVALVE,HIGH);
digitalWrite(FANPIN,HIGH);
digitalWrite(WATERVALVE,HIGH);
digitalWrite(MOTORPIN,HIGH);
digitalWrite(HEATERPIN,HIGH);

rtc.begin();
now = rtc.now();
lcd.begin();
lcd.backlight();
tft.begin();
tft.setRotation(0);   
ts.InitTouch();
ts.setPrecision(PREC_MEDIUM);

 // lcd.setCursor(4, 1);
  //lcd.print(now);
   char date[18] = "hh:mm:ss MM/DD/YY";
   rtc.now().toString(date);
   //lcd.print(date);
   //delay(3000);
  
  /*lcd.setCursor(1, 3);
  for (int i = 0; i < 17; i++)
  {
    lcd.setCursor(i + 1, 3);
    lcd.print(slogan[i]);
    delay(100);
  }

delay(20);
*/

EEPROM.get(reftempaddress,REFTEMPERATURE);
delay(20);
EEPROM.get(reftemptoladdress,REFTEMPTOLERANCE);
delay(20);
EEPROM.get(refhumidaddress,REFHUMIDITY);
delay(20);
EEPROM.get(refhumidtoladdress,refhumidtoladdress);
delay(20);
EEPROM.get(reftemptresholdaddress,REFTEMPTRESHOLD);
delay(20);
EEPROM.get(refhumidtresholddadress,REFHUMIDTRESHOLD);
delay(20);

NoINCUBATIONDAYS = EEPROM.read(NoINCUBATIONDAYSaddress);
delay(20);
TSPIN = EEPROM.read(tspinaddress);
delay(20);
SPIN = EEPROM.read(spinaddress);
delay(20);
timeduringrotation = EEPROM.read(timeduringrotationaddress);
delay(20);

NoINCUBATIONDAYSLEFT = EEPROM.read(Noincubationdaysleftaddress);
delay(20);
lcd.clear();

    

}

void RESETINC(){digitalWrite(ALARMPIN,HIGH);
delay(500);
digitalWrite(ALARMPIN,LOW);

digitalWrite(CANDLING,HIGH);
digitalWrite(HUMIDIFIERPIN,HIGH);
digitalWrite(WATERVALVE,HIGH);
digitalWrite(FANPIN,HIGH);
digitalWrite(WATERVALVE,HIGH);
digitalWrite(MOTORPIN,HIGH);
digitalWrite(HEATERPIN,HIGH);}

/*
void blinkLED(void)
{
  if(SECSPIN>0)
  SECSPIN = SECSPIN -1;
   
}*/
