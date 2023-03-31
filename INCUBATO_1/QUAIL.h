float QUAIL_TEMP = 37;
float QUAIL_TEMPTOLERANCE = 0.1;
float QUAIL_TEMPTRESHOLD = 0.1;

float QUAIL_HUMID_15 = 65;
float QUAIL_HUMIDTOLERANCE_15 = 5.0;
float QUAIL_HUMIDTRESHOLD_15 = 1;

float QUAIL_HUMID_18 = 73;
float QUAIL_HUMIDTOLERANCE_18 = 3.0;
float QUAIL_HUMIDTRESHOLD_18 = 1;

int QUAIL_INCUBATION = 0;
int QUAIL_DAYS_REMAIN = 0;

int QUAIL_TSPIN = 0;
int QUAIL_SECSPIN = 0;
int QUAIL_MINUTESPIN = 0;
int QUAIL_SPIN = 0;

void BLINKQUAIL(void)
{
  if(QUAIL_SECSPIN>0)
  QUAIL_SECSPIN = QUAIL_SECSPIN -1;
}

void QUAIL18(){
  QUAIL_DAYS_REMAIN = 0+18;
  QUAIL_INCUBATION = 0+18;
  QUAIL_SECSPIN = 0+59;
  QUAIL_MINUTESPIN = 0+59;
  QUAIL_SPIN = 0+6;
  QUAIL_TSPIN = 0+6;
lcd.createChar(0,customChar);
lcd.createChar(1,customChar1);
lcd.createChar(10,arrow);
Timer1.initialize(1000000);
Timer1.attachInterrupt(BLINKQUAIL); // BLINKQUAIL to run every 0.15 seconds
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
}

void QUAILREAD_TH (void) //QUAILREAD_TH
{
   temperature = dht.readTemperature();
   humidity = dht.readHumidity();
   lcd.setCursor(6,0);
   lcd.print(temperature);
   lcd.setCursor(7,1);
   lcd.print(humidity);
}

void Qalarm(){

               digitalWrite(ALARMPIN,HIGH);
               delay(100);
               digitalWrite(ALARMPIN,LOW);
               delay(40);
}

void Q_TEMP_REG(void)
{

if (temperature==QUAIL_TEMP)
{

  digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}
   else if ( (temperature>=(QUAIL_TEMP-QUAIL_TEMPTOLERANCE))&& (temperature<=(QUAIL_TEMP+QUAIL_TEMPTOLERANCE)) )
      {
        digitalWrite(FANPIN,HIGH);
        digitalWrite(HEATERPIN,HIGH);
        lcd.setCursor(16,0);
        lcd.write(0);
      }

QUAILREAD_TH();
  if (temperature>(QUAIL_TEMP+QUAIL_TEMPTOLERANCE))
          {
              digitalWrite(FANPIN,HIGH);
              digitalWrite(HEATERPIN,HIGH);
              if(temperature>=(QUAIL_TEMP+QUAIL_TEMPTOLERANCE+QUAIL_TEMPTRESHOLD))
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

QUAILREAD_TH();
  if (temperature<(QUAIL_TEMP - QUAIL_TEMPTOLERANCE))
          {
            digitalWrite(FANPIN,HIGH);
            digitalWrite(HEATERPIN,LOW);
            if(temperature<=(QUAIL_TEMP - QUAIL_TEMPTOLERANCE - QUAIL_TEMPTRESHOLD))
                {
                  Qalarm();
                  lcd.setCursor(16,0);
                  lcd.write(1);
                  delay(100);
                  lcd.setCursor(16,0);
                  lcd.print(" ");
                  delay(100);
                }
                  lcd.setCursor(16,0);
                  lcd.write(1);
                }}

void Q_HUMIDITY_REG15(){

Serial.println(" Q_HUMIDITY_REG15");
   if ( (humidity>=(QUAIL_HUMID_15-QUAIL_HUMIDTOLERANCE_15))&& (humidity<=(QUAIL_HUMID_15+QUAIL_HUMIDTOLERANCE_15)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
QUAILREAD_TH();
  if (humidity>(QUAIL_HUMID_15+QUAIL_HUMIDTOLERANCE_15))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(QUAIL_HUMID_15+QUAIL_HUMIDTOLERANCE_15+QUAIL_HUMIDTRESHOLD_15))
                 {
                    digitalWrite(FANPIN,LOW);
                    Qalarm();
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
          
QUAILREAD_TH();
  if (humidity<(QUAIL_HUMID_15 - QUAIL_HUMIDTOLERANCE_15))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(QUAIL_HUMID_15 - QUAIL_HUMIDTOLERANCE_15 - QUAIL_HUMIDTRESHOLD_15))
                {
                  
                  Qalarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Calarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void Q_HUMIDITY_REG18(){

Serial.print(" Q_HUMIDITY_REG18");
   if ( (humidity>=(QUAIL_HUMID_18-QUAIL_HUMIDTOLERANCE_18))&& (humidity<=(QUAIL_HUMID_18+QUAIL_HUMIDTOLERANCE_18)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
QUAILREAD_TH();
  if (humidity>(QUAIL_HUMID_18+QUAIL_HUMIDTOLERANCE_18))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(QUAIL_HUMID_18+QUAIL_HUMIDTOLERANCE_18+QUAIL_HUMIDTRESHOLD_18))
                 { 
                    digitalWrite(FANPIN,LOW);
                    Qalarm();
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
          
QUAILREAD_TH();
  if (humidity<(QUAIL_HUMID_18 - QUAIL_HUMIDTOLERANCE_18))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(QUAIL_HUMID_18 - QUAIL_HUMIDTOLERANCE_18 - QUAIL_HUMIDTRESHOLD_18))
                { 
                  Qalarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Qalarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void QUAIL()
 { 
   now= rtc.now();
   Serial.println("");
   char date[18] = "hh:mm:ss";
   rtc.now().toString(date);
   Serial.println("");
   Serial.print(date);
   Serial.print(" TEMP:");
   Serial.print(temperature);
   Serial.print(" HUMID:");
   Serial.print(humidity);
  
  lcd.setCursor(15,2);
  lcd.print(QUAIL_SECSPIN); 
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

if (QUAIL_TSPIN==0){
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
  lcd.print(QUAIL_SPIN);
  lcd.setCursor(11,2);
  lcd.print(":");
  lcd.setCursor(12,2);
  lcd.print(QUAIL_MINUTESPIN);
  lcd.setCursor(14,2);
  lcd.print(":");
  lcd.setCursor(15,2);
  lcd.print(QUAIL_SECSPIN);   
}
  DateTime startday(a,b,c,d,e,f);
  startday = rtc.now();
  lcd.setCursor(0,3);
  lcd.print("HATCH IN = ");
  lcd.setCursor(11,3);
  lcd.print(QUAIL_DAYS_REMAIN);
     if (QUAIL_DAYS_REMAIN<10){
            lcd.setCursor(12,3);
            lcd.print(" ");
            }

  lcd.setCursor(14,3);
  lcd.print("Days");
  lcd.setCursor(15,2);
  lcd.print(QUAIL_SECSPIN);
     if(QUAIL_SECSPIN<10)
             lcd.setCursor(16,2);
             lcd.print(""); 
 
     if(QUAIL_MINUTESPIN<10)
             lcd.setCursor(13,2);
             lcd.print(" "); 

     if(QUAIL_SPIN<10){
             lcd.setCursor(10,2);
             lcd.print(" ");
             }

if ((QUAIL_SECSPIN==0)&& QUAIL_MINUTESPIN)
{
  QUAIL_MINUTESPIN = QUAIL_MINUTESPIN - 1;
  QUAIL_SECSPIN = 59;
}

if ((QUAIL_MINUTESPIN==0)&& QUAIL_SPIN)
{
  QUAIL_SPIN = QUAIL_SPIN - 1;
  QUAIL_MINUTESPIN = 59;
}

if((QUAIL_SPIN ==0) && (QUAIL_MINUTESPIN==0) && (QUAIL_SECSPIN==0))
{
  digitalWrite(MOTORPIN,LOW);
  delay(10000);
  digitalWrite(MOTORPIN,HIGH);
  QUAIL_SPIN = QUAIL_TSPIN ;
  QUAIL_MINUTESPIN =00;
  QUAIL_SECSPIN =00;
}
  lcd.setCursor(15,2);
  lcd.print(QUAIL_SECSPIN); 
 
Q_TEMP_REG();  


if(QUAIL_DAYS_REMAIN >3)
{ 
  Q_HUMIDITY_REG15();
} 
else {
  Q_HUMIDITY_REG18();}
  
 lcd.setCursor(15,2);
 lcd.print(QUAIL_SECSPIN); 
 lcd.setCursor(15,2);
 lcd.print(QUAIL_SECSPIN); 

if(QUAIL_DAYS_REMAIN == 0)
{ 
  
  lcd.setCursor(0,3);
  lcd.print("                   ");
  delay(10);
  lcd.setCursor(0,3);
  lcd.print("INCUB. TIME REACHED");
  lcd.setCursor(0,3);
  lcd.print("                    ");
  

} 

  lcd.setCursor(15,2);
  lcd.print(QUAIL_SECSPIN); 

DateTime now (a,b,c,d,e,f); 
delay(20);
       for (int n=1; n<50; n++)

         if (QUAIL_INCUBATION >= n){
            {
                    if (rtc.now() == ( now + TimeSpan(n,0,0,0))) 
                            {
                             QUAIL_DAYS_REMAIN = QUAIL_INCUBATION - n;
                             Serial.print(QUAIL_DAYS_REMAIN);
                            } 
             }}
 }

    /*       for (int kl=1; kl<50; kl++)

         if (QUAIL_DAYS_REMAIN >= kl){
            {
                    if (rtc.now() == ( now + TimeSpan(0,0,0,kl))) 
                            {
                             QUAIL_INCUBATION  = QUAIL_DAYS_REMAIN - kl;
                             Serial.print(QUAIL_DAYS_REMAIN);
                            } 
             }}
              
 }*/             

      
      


/*  FOR DAYS NA
             
{ if  ((rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,0,30,0)))||(rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,2,0,0)))||(rtc.now() == ( startday + TimeSpan(n,5,0,0)))||(rtc.now() == ( startday + TimeSpan(n,10,0,0)))) 
                            {
                              QUAIL_DAYS_REMAIN = QUAIL_INCUBATION - n;
                              EEPROM.write(QUAIL_DAYS_REMAINaddress,QUAIL_DAYS_REMAIN);
                              delay(10);
                            }

                  }

      } 


 }*/
