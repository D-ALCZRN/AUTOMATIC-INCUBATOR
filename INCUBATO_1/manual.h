void blinkLED(void)
{
  if(SECSPIN>0)
  SECSPIN = SECSPIN -1;
   
}

void readtempandhumid(void)
{
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  lcd.setCursor(6,0);
  lcd.print(temperature);
  lcd.setCursor(7,1);
  lcd.print(humidity);
   
 
}



void alarm(){

               digitalWrite(ALARMPIN,HIGH);
               delay(100);
               digitalWrite(ALARMPIN,LOW);
               delay(40);
}

void savechanges(void)
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


NoINCUBATIONDAYSLEFT = NoINCUBATIONDAYS;
delay(20);
EEPROM.write(Noincubationdaysleftaddress,NoINCUBATIONDAYSLEFT);
delay(20);
DateTime startday(a,b,c,d,e,f);

startday = rtc.now();

EEPROM.write(startdayyearaddress,startday.year());
delay(20);
EEPROM.write(startdaymonthaddress,startday.month());
delay(20);
EEPROM.write(startdaydayaddress,startday.day());
delay(20);
EEPROM.write(startdayhouraddress,startday.hour());
delay(20);
EEPROM.write(startdayminuteaddress,startday.minute());
delay(20);
EEPROM.write(startdaysecondaddress,startday.second());
delay(20);

EEPROM.write(tspinaddress,TSPIN);
delay(20);
EEPROM.write(timeduringrotationaddress,timeduringrotation);
delay(20);
SPIN = TSPIN -1;
delay(20);
EEPROM.write(spinaddress,SPIN);

delay(20);
 a = EEPROM.read(startdayyearaddress)  + 1792 ;
delay(20);
  b = EEPROM.read(startdaymonthaddress) ;
 delay(20);
 c = EEPROM.read(startdaydayaddress);
delay(20);
 d = EEPROM.read(startdayhouraddress); 
 delay(20);
  e= EEPROM.read(startdayminuteaddress); 
 delay(20);
  f= EEPROM.read(startdaysecondaddress);
 delay(20); 
 timeduringrotationaddress =timeduringrotation;

if(TSPIN)
{SECSPIN = 59;
}

}



void temperatureregulation(void)
{

if (temperature==REFTEMPERATURE)
{

  digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}

   else if ( (temperature>=(REFTEMPERATURE-REFTEMPTOLERANCE))&& (temperature<=(REFTEMPERATURE+REFTEMPTOLERANCE)) )
      {
        digitalWrite(FANPIN,HIGH);
        digitalWrite(HEATERPIN,HIGH);
       lcd.setCursor(16,0);
       
       lcd.write(0);
  
      }

readtempandhumid();
  if (temperature>(REFTEMPERATURE+REFTEMPTOLERANCE))
          {
              digitalWrite(FANPIN,HIGH);
              digitalWrite(HEATERPIN,HIGH);
              if(temperature>=(REFTEMPERATURE+REFTEMPTOLERANCE+REFTEMPTRESHOLD))
                 {
                   digitalWrite(ALARMPIN,HIGH);
                  lcd.setCursor(16,0);
                    lcd.write(1);
                  delay(100);
                  digitalWrite(ALARMPIN,LOW);
                   lcd.setCursor(16,0);
                    lcd.print(" ");
                  delay(150);
                 }
                 lcd.setCursor(16,0);
                    lcd.write(1);
          }

readtempandhumid();
  if (temperature<(REFTEMPERATURE - REFTEMPTOLERANCE))
          {
            digitalWrite(FANPIN,HIGH);
            digitalWrite(HEATERPIN,LOW);
            if(temperature<=(REFTEMPERATURE - REFTEMPTOLERANCE - REFTEMPTRESHOLD))
                {
                  alarm();
                  lcd.setCursor(16,0);
                    lcd.write(1);
                  delay(100);
                   lcd.setCursor(16,0);
                    lcd.print(" ");
                  delay(100);
                }
               
                 lcd.setCursor(16,0);
                    lcd.write(1);
          }

      
}



void humidityregulation(){

   if ( (humidity>=(REFHUMIDITY-REFHUMIDTOLERANCE))&& (humidity<=(REFHUMIDITY+REFHUMIDTOLERANCE)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
readtempandhumid();
  if (humidity>(REFHUMIDITY+REFHUMIDTOLERANCE))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(REFHUMIDITY+REFHUMIDTOLERANCE+REFHUMIDTRESHOLD))
                 {
                  
                    alarm();
                      lcd.setCursor(16,1);
                  lcd.write(1);
                    delay(100);
                    lcd.setCursor(16,1);
                  lcd.print(" ");
                    
                   
                    delay(100);
                      
                    
                 }
                 lcd.setCursor(16,1);
                  lcd.write(1);
          }
readtempandhumid();
  if (humidity<(REFHUMIDITY - REFHUMIDTOLERANCE))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(REFHUMIDITY - REFHUMIDTOLERANCE - REFHUMIDTRESHOLD))
                {
                  alarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                 alarm();
                  lcd.setCursor(16,1);
                  lcd.print(" ");
                    
                  delay(100);
                }
          }


}


/*void milsecdelay(){

    if (millisflag){
      millisflag=0;
      count =millis();
    }

    count1=millis();
    if ((count1-count)>=50)
    {
      // action
      millisflag=1;
    }
}*/

void discardchanges()
{
  REFTEMPERATURE  =  REFTEMPERATUREHOLDER;
  REFHUMIDITY = REFHUMIDITYHOLDER;
  REFTEMPTOLERANCE = REFTEMPTOLERANCEHOLDER ;
  REFHUMIDTOLERANCE = REFHUMIDTOLERANCEHOLDER  ;
  REFTEMPTRESHOLD = REFTEMPTRESHOLDHOLDER ;
  REFHUMIDTRESHOLD = REFHUMIDTRESHOLDHOLDER  ;
  TSPIN =  TSPINHOLDER;
  SPIN =SPINHOLDER;
  NoINCUBATIONDAYS = NoINCUBATIONDAYSHOLDER ;
  NoINCUBATIONDAYSLEFT = NoINCUBATIONDAYSLEFTHOLDER;
  timeduringrotation= timeduringrotationholder;
}


void menu(void)
{ 

  //entering menu
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Entering MENU");
  lcd.setCursor(4,1);
  lcd.print("Please Wait...");
  REFTEMPERATUREHOLDER = REFTEMPERATURE ;
  REFHUMIDITYHOLDER = REFHUMIDITY;
  REFTEMPTOLERANCEHOLDER = REFTEMPTOLERANCE;
  REFHUMIDTOLERANCEHOLDER = REFHUMIDTOLERANCE ;
  REFTEMPTRESHOLDHOLDER = REFTEMPTRESHOLD;
  REFHUMIDTRESHOLDHOLDER = REFHUMIDTRESHOLD ;
  TSPINHOLDER = TSPIN ;
  NoINCUBATIONDAYSHOLDER = NoINCUBATIONDAYS;
  NoINCUBATIONDAYSLEFTHOLDER = NoINCUBATIONDAYSLEFT;
  SPINHOLDER = SPIN;
  timeduringrotationholder= timeduringrotation;

  delay(200);
  lcd.clear();


 do{
lcd.setCursor(4,1);
      lcd.print("=>");// special select item character
   lcd.setCursor(1,0);
            lcd.print("Set Temperature:");
            lcd.setCursor(6,1);
            lcd.print(REFTEMPERATURE);
            lcd.setCursor(10,1);
            lcd.print((char) 223);
            lcd.setCursor(11,1);
            lcd.print("C");

            lcd.setCursor(2,2);
            lcd.print("Temp Tolerance:");
            lcd.setCursor(6,3);
            lcd.print(REFTEMPTOLERANCE);
            lcd.setCursor(10,3);
            lcd.print((char) 223);
            lcd.setCursor(11,3);
            lcd.print("C");
      
      if ((digitalRead(RIGHTBUTTON)==PRESSED)&&(REFTEMPERATURE<99))
          { 
            REFTEMPERATURE = REFTEMPERATURE + 0.1;
            delay(200);
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED)&&(REFTEMPERATURE>2))
          {
            REFTEMPERATURE = REFTEMPERATURE - 0.1;
             delay(200);
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED);
 
 do{

}while (digitalRead(MENUBUTTON)==PRESSED);// debouncing of the menubutton pressing
   lcd.setCursor(4,1);
    lcd.print("  ");// special select item character removal
  

// selecting the reference temperature tolerance for editing
 do{ 
      lcd.setCursor(4,3);
      lcd.print("=>");// special select item character
        
        if ((digitalRead(RIGHTBUTTON)==PRESSED)&&(REFTEMPTOLERANCE<5))
            { 
              REFTEMPTOLERANCE = REFTEMPTOLERANCE + 0.1;
               delay(200);
            }
        if ((digitalRead(LEFTBUTTON)==PRESSED)&&(REFTEMPTOLERANCE>0))
            {
              REFTEMPTOLERANCE = REFTEMPTOLERANCE - 0.1;
               delay(200);
            }
            //display of reference humdity
            lcd.setCursor(2,2);
            lcd.print("Temp Tolerance:");
            lcd.setCursor(6,3);
            lcd.print(REFTEMPTOLERANCE);
            lcd.setCursor(10,3);
            lcd.print((char) 223);
            lcd.setCursor(11,3);
            lcd.print("C");

    }   while (digitalRead(MENUBUTTON)==NOTPRESSED);
   

do{

}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();


 do{
   // display and selection of reference humidity for editing
    lcd.setCursor(4,1);
    lcd.print("=>");// special select item character
    lcd.setCursor(3,0);
    lcd.print("Set Humidity:");
    lcd.setCursor(6,1);
    lcd.print(REFHUMIDITY);
    lcd.setCursor(11,1);
    lcd.print("% RH");
   //display of reference humdity
    lcd.setCursor(1,2);
    lcd.print("Humidity Tolerance:");
    lcd.setCursor(6,3);
    lcd.print(REFHUMIDTOLERANCE);
    lcd.setCursor(10,3);
    lcd.print("% RH");

    
      
      if ((digitalRead(RIGHTBUTTON)==PRESSED)&&(REFHUMIDITY<99))
          { 
            REFHUMIDITY = REFHUMIDITY + 0.1;
            delay(200);
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED)&&(REFHUMIDITY>5))
          {
            REFHUMIDITY = REFHUMIDITY - 0.1;
             delay(200);
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED);
 
 do{

}while (digitalRead(MENUBUTTON)==PRESSED);// debouncing of the menubutton pressing
   lcd.setCursor(4,1);
    lcd.print("  ");// special select item character removal
  

// selecting the reference humidity tolerance for editing
 do{ 
      lcd.setCursor(4,3);
      lcd.print("=>");// special select item character
        
        if (digitalRead(RIGHTBUTTON)==PRESSED)
            { 
              REFHUMIDTOLERANCE = REFHUMIDTOLERANCE + 0.1;
               delay(200);
            }
        if (digitalRead(LEFTBUTTON)==PRESSED)
            {
              REFHUMIDTOLERANCE = REFHUMIDTOLERANCE- 0.1;
               delay(200);
            }
            //display of reference humdity
          lcd.setCursor(1,2);
          lcd.print("Humidity Tolerance:");
          lcd.setCursor(6,3);
          lcd.print(REFHUMIDTOLERANCE);
          lcd.setCursor(10,3);
          lcd.print("% RH");

    }   while (digitalRead(MENUBUTTON)==NOTPRESSED);
   

do{

}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();


do{
   // display and selection of reference temprature for editing
    lcd.setCursor(4,1);
    lcd.print("=>");// special select item character
    lcd.setCursor(1,0);
    lcd.print("Temp_Diff Treshold:");
    lcd.setCursor(6,1);
    lcd.print(REFTEMPTRESHOLD);
    lcd.setCursor(10,1);
    lcd.print((char) 223);
    lcd.setCursor(11,1);
    lcd.print("C");
  // display and selection of reference humidity 
   
    lcd.setCursor(0,2);
    lcd.print("Humid_Diff Treshold:");
    lcd.setCursor(6,3);
    lcd.print(REFHUMIDTRESHOLD);
    lcd.setCursor(10,3);
    lcd.print("% RH");
    
      
      if (digitalRead(RIGHTBUTTON)==PRESSED)
          { 
            REFTEMPTRESHOLD = REFTEMPTRESHOLD + 0.1;
            delay(200);
          }
      if (digitalRead(LEFTBUTTON)==PRESSED)
          {
            REFTEMPTRESHOLD = REFTEMPTRESHOLD - 0.1;
             delay(200);
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED);
 
 do{

}while (digitalRead(MENUBUTTON)==PRESSED);// debouncing of the menubutton pressing
   lcd.setCursor(4,1);
    lcd.print("  ");// special select item character removal


do{
   // display and selection of reference humidity for editing
    lcd.setCursor(4,3);
    lcd.print("=>");// special select item character
    lcd.setCursor(0,2);
   lcd.setCursor(0,2);
    lcd.print("Humid_Diff Treshold:");
    lcd.setCursor(6,3);
    lcd.print(REFHUMIDTRESHOLD);
    lcd.setCursor(10,3);
    lcd.print("% RH");


      if (digitalRead(RIGHTBUTTON)==PRESSED)
          { 
            REFHUMIDTRESHOLD = REFHUMIDTRESHOLD+ 0.1;
            delay(200);
          }
      if (digitalRead(LEFTBUTTON)==PRESSED)
          {
            REFHUMIDTRESHOLD = REFHUMIDTRESHOLD - 0.1;
             delay(200);
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED);
 
 do{
  
  } while (digitalRead(MENUBUTTON)==PRESSED);// debouncing of the menubutton pressing
  lcd.clear();
  


 do{
   if(NoINCUBATIONDAYS>50)
   {
     NoINCUBATIONDAYS=21;
   }
  // display of incubation time in days
   lcd.setCursor(4,2);
      lcd.print("=>");
    lcd.setCursor(0,0);
    lcd.print("Set Incubation_Time:");
    lcd.setCursor(6,2);
    lcd.print(NoINCUBATIONDAYS);
    lcd.setCursor(9,2);
    lcd.print("Days");
   
    if ((digitalRead(RIGHTBUTTON)==PRESSED)&&(NoINCUBATIONDAYS<46))
          { 
            NoINCUBATIONDAYS = NoINCUBATIONDAYS + 1;
            delay(200);
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED)&&(REFTEMPERATURE>1))  
          {
            NoINCUBATIONDAYS = NoINCUBATIONDAYS - 1;
             delay(200);
          }

 if (NoINCUBATIONDAYS<10){
   lcd.setCursor(7,2);
   lcd.print(" ");
 }



}while (digitalRead(MENUBUTTON)==NOTPRESSED);

do{

}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();
 

 do{

  // display of incubation time in days
   lcd.setCursor(4,2);
      lcd.print("=>");
    lcd.setCursor(0,0);
    lcd.print("Time Between Spins:");
    lcd.setCursor(6,2);
    lcd.print(TSPIN );
    lcd.setCursor(9,2);
    lcd.print("Hour/s");
   
    if ((digitalRead(RIGHTBUTTON)==PRESSED) && (TSPIN <13) )
          { 
           TSPIN = TSPIN + 1;
            delay(100);
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED) && (TSPIN >=1) )
          {
            TSPIN = TSPIN - 1;
             delay(100);
          }

           if (TSPIN<10){
   lcd.setCursor(7,2);
   lcd.print(" ");
 }

}while (digitalRead(MENUBUTTON)==NOTPRESSED);

do{

}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();





do{


 lcd.setCursor(4,2);
      lcd.print("=>");
    lcd.setCursor(0,0);
    lcd.print("Time During Rot.");
    lcd.setCursor(6,2);
    lcd.print(timeduringrotation);
    lcd.setCursor(8,2);
    lcd.print("s");
      
       if(timeduringrotation<10)
            {
               lcd.setCursor(7,2);
                lcd.print(" ");
            }

  if ((digitalRead(RIGHTBUTTON)==PRESSED)&& (timeduringrotation<100))
          { 
            timeduringrotation = timeduringrotation+ 1;
            delay(200);
            if(timeduringrotation<10)
            {
               lcd.setCursor(7,2);
                lcd.print(" ");
            }
          }
      if ((digitalRead(LEFTBUTTON)==PRESSED)&& (timeduringrotation>1))
          {
            timeduringrotation = timeduringrotation - 1;
             delay(200);
              lcd.setCursor(7,2);
                lcd.print(" ");
          }
  } while(digitalRead(MENUBUTTON)== NOTPRESSED);

do{

}while (digitalRead(MENUBUTTON)==PRESSED);
lcd.clear();

 

 do{
    lcd.setCursor(0,0);
    lcd.print(" Press 'Ok' to save");
    lcd.setCursor(2,1);
    lcd.print(" Changes or any");
    lcd.setCursor(0,2);
    lcd.print("Other key to discard");
    
 }while (  (digitalRead(MENUBUTTON)==NOTPRESSED) && (digitalRead(RIGHTBUTTON)==NOTPRESSED) && (digitalRead(LEFTBUTTON)==NOTPRESSED));


if(!digitalRead(MENUBUTTON))

{lcd.clear();
  savechanges();
 /*  lcd.setCursor(0,0);
  lcd.print("saved");
  delay(300); */

lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("SAVING...");
        lcd.setCursor(3, 3);
        for (int i = 0; i < 17; i++)
        {
          lcd.setCursor(i + 1, 1);
          lcd.write(byte(10));
          lcd.setCursor(i + 1, 2);
          lcd.write(byte(10));
          delay(60);
        }
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("SAVED SUCCESSFULLY!!");
        delay(500);


}
else{
lcd.clear();
  discardchanges();
  lcd.setCursor(0,0);
  lcd.print("changes discarded");
  delay(300);
}

lcd.clear();


}




void MANUAL_LCDPRINT()
 {
lcd.createChar(0,customChar);
lcd.createChar(1,customChar1);
lcd.createChar(10,arrow);
Timer1.initialize(1000000);
Timer1.attachInterrupt(blinkLED); // BLINKCHICKEN to run every 0.15 seconds
 
  now= rtc.now();
  
/*
lcd.setCursor(0,2);
 lcd.print(now.year());
    lcd.setCursor(4,2);
    lcd.print('/');
    lcd.setCursor(5,2);
    lcd.print(now.month());
    lcd.setCursor(9,2);
    lcd.print('/');
    lcd.setCursor(10,2);
    lcd.print(now.day(), DEC);
    lcd.setCursor(12,2);
  */
    //lcd.setCursor(,);
    //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
   // lcd.setCursor(,);
   // lcd.print(") ");
  
   /* lcd.print(now.hour());
    lcd.setCursor(14,3);
    lcd.print(':');
    lcd.setCursor(15,2);
    lcd.print(now.minute());
    lcd.setCursor(16,3);
    lcd.print(':');
    lcd.setCursor(17,2);
    lcd.print(now.second());
*/




 lcd.setCursor(15,2);
  lcd.print(SECSPIN); 
 
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.setCursor(6,0);
  lcd.print(temperature);
  lcd.setCursor(12,0);
  lcd.print((char) 223);
  lcd.setCursor(13,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("HUMID= ");
  lcd.setCursor(7,1);
  lcd.print(humidity);
  lcd.setCursor(13,1);
  lcd.print("%");

if (TSPIN==0){
  lcd.setCursor(0,2);
  lcd.print("T_Spin =");
   lcd.setCursor(9,2);
  lcd.print("00");
   lcd.setCursor(11,2);
  lcd.print(":");
    lcd.setCursor(12,2);
  lcd.print("00");
    lcd.setCursor(14,2);
  lcd.print(":");
    lcd.setCursor(15,2);
  lcd.print("00"); 

}
else{
    lcd.setCursor(0,2);
  lcd.print("T_Spin =");
   lcd.setCursor(9,2);
  lcd.print(SPIN);
   lcd.setCursor(11,2);
  lcd.print(":");
    lcd.setCursor(12,2);
  lcd.print(MINUTESPIN);
    lcd.setCursor(14,2);
  lcd.print(":");
    lcd.setCursor(15,2);
  lcd.print(SECSPIN); 

  
}

   lcd.setCursor(0,3);
  lcd.print("HATCH IN = ");
   lcd.setCursor(11,3);
  lcd.print(NoINCUBATIONDAYSLEFT);
     if (NoINCUBATIONDAYSLEFT<10){
    lcd.setCursor(12,3);
    lcd.print(" ");
   
  }

lcd.setCursor(14,3);
  lcd.print("Days");

 lcd.setCursor(15,2);
  lcd.print(SECSPIN);

if(SECSPIN<10)
 lcd.setCursor(16,2);
  lcd.print(" "); 
 
if(MINUTESPIN<10)
 lcd.setCursor(13,2);
  lcd.print(" "); 

  if(SPIN<10){
    lcd.setCursor(10,2);
  lcd.print(" ");
   
  }


if ((SECSPIN==0)&& MINUTESPIN)
{
  MINUTESPIN = MINUTESPIN - 1;
  SECSPIN = 59;
}

if ((MINUTESPIN==0)&& SPIN)
{
  SPIN = SPIN - 1;
  MINUTESPIN = 59;
}

if((SPIN ==0) && (MINUTESPIN==0) && (SECSPIN==0))
{
  digitalWrite(MOTORPIN,LOW);
  delay(10000);
  digitalWrite(MOTORPIN,HIGH);
  
  TSPIN= EEPROM.read(tspinaddress);
  SPIN = TSPIN - 1;
  MINUTESPIN =00;
  SECSPIN =00;
}
  lcd.setCursor(15,2);
  lcd.print(SECSPIN); 
 


 
temperatureregulation();
 

humidityregulation ();

 lcd.setCursor(15,2);
  lcd.print(SECSPIN); 
if (digitalRead(MENUBUTTON)==PRESSED)
{ 
  menu();
  
}
 
 
 lcd.setCursor(15,2);
  lcd.print(SECSPIN); 



  
/*if(NoINCUBATIONDAYSLEFT == 0)
{ 
  alarm();
  lcd.setCursor(0,3);
  lcd.print("                   ");
  delay(10);
   lcd.setCursor(0,3);
  lcd.print("INCUB. TIME REACHED");
delay(500);
lcd.setCursor(0,3);
lcd.print("                    ");
delay(10);

} */



 lcd.setCursor(15,2);
  lcd.print(SECSPIN); 
// lcd.setCursor(0,3);

//startday = startday + TimeSpan(1,1,1,1);
  //lcd.print("                              ");

  //a = EEPROM.read(startdayyearaddress);
   
  DateTime startday(a,b,c,d,e,f); 

 /*   lcd.setCursor(0,3);
  lcd.print(startday.second()); */
/*  lcd.setCursor(15,2);
  lcd.print(SECSPIN); 
  */
delay(20);


/* this code below should be commented to stop the act 
of using seconds as incubation days. Note: this was
 made only for demonstration purposes in order to see how 
 effective the number of incubation days are being counted. */
      for (unsigned short n=1; n<50; n++)

         {   if (NoINCUBATIONDAYS >= n)
             
                  { if  (rtc.now() == ( startday + TimeSpan(n,0,0,0))) 
                            {
                              NoINCUBATIONDAYSLEFT = NoINCUBATIONDAYS - n;
                              EEPROM.write(Noincubationdaysleftaddress,NoINCUBATIONDAYSLEFT);
                              delay(10);
                            }

                  }

      }


/*  should be uncommented in order to make the number of days of incubation effectif.
for (unsigned short n=1; n<50; n++)

         {   if (NoINCUBATIONDAYS >= n)
             
{ if  ((rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,0,30,0)))||(rtc.now() == ( startday + TimeSpan(n,1,0,0)))||(rtc.now() == ( startday + TimeSpan(n,2,0,0)))||(rtc.now() == ( startday + TimeSpan(n,5,0,0)))||(rtc.now() == ( startday + TimeSpan(n,10,0,0)))) 
                            {
                              NoINCUBATIONDAYSLEFT = NoINCUBATIONDAYS - n;
                              EEPROM.write(Noincubationdaysleftaddress,NoINCUBATIONDAYSLEFT);
                              delay(10);
                            }

                  }

      } */


 }
