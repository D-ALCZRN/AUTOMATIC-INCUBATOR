float CHICKEN_TEMP = 37;
float CHICKEN_TEMPTOLERANCE = 0.1;
float CHICKEN_TEMPTRESHOLD = 0.1;

float CHICKEN_HUMID_18 = 65;
float CHICKEN_HUMIDTOLERANCE_18 = 5.0;
float CHICKEN_HUMIDTRESHOLD_18 = 1;

float CHICKEN_HUMID_21 = 73;
float CHICKEN_HUMIDTOLERANCE_21 = 3.0;
float CHICKEN_HUMIDTRESHOLD_21 = 1;

int CHICKEN_INCUBATION = 0;
int CHICKEN_DAYS_REMAIN = 0;

int CHICKEN_TSPIN = 0;
int CHICKEN_SECSPIN = 0;
int CHICKEN_MINUTESPIN = 0;
int CHICKEN_SPIN = 0;

void BLINKCHICKEN(void)
{
  if(CHICKEN_SECSPIN>0)
  CHICKEN_SECSPIN = CHICKEN_SECSPIN -1;
}

void CHICKEN21(){
  CHICKEN_DAYS_REMAIN = 0+21;
  CHICKEN_INCUBATION = 0+21;
  CHICKEN_SECSPIN = 0+59;
  CHICKEN_MINUTESPIN = 0+59;
  CHICKEN_SPIN = 0+6;
  CHICKEN_TSPIN = 0+6;
lcd.createChar(0,customChar);
lcd.createChar(1,customChar1);
lcd.createChar(10,arrow);
Timer1.initialize(1000000);
Timer1.attachInterrupt(BLINKCHICKEN); // BLINKCHICKEN to run every 0.15 seconds
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

void CHICKENREAD_TH (void) //CHICKENREAD_TH
{
   temperature = dht.readTemperature();
   humidity = dht.readHumidity();
   lcd.setCursor(6,0);
   lcd.print(temperature);
   lcd.setCursor(7,1);
   lcd.print(humidity);
}

void Calarm(){

               digitalWrite(ALARMPIN,HIGH);
               delay(100);
               digitalWrite(ALARMPIN,LOW);
               delay(40);
}

void C_TEMP_REG(void)
{

if (temperature==CHICKEN_TEMP)
{

  digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}
   else if ( (temperature>=(CHICKEN_TEMP-CHICKEN_TEMPTOLERANCE))&& (temperature<=(CHICKEN_TEMP+CHICKEN_TEMPTOLERANCE)) )
      {
        digitalWrite(FANPIN,HIGH);
        digitalWrite(HEATERPIN,HIGH);
        lcd.setCursor(16,0);
        lcd.write(0);
      }

CHICKENREAD_TH();
  if (temperature>(CHICKEN_TEMP+CHICKEN_TEMPTOLERANCE))
          {
              digitalWrite(FANPIN,HIGH);
              digitalWrite(HEATERPIN,HIGH);
              if(temperature>=(CHICKEN_TEMP+CHICKEN_TEMPTOLERANCE+CHICKEN_TEMPTRESHOLD))
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

CHICKENREAD_TH();
  if (temperature<(CHICKEN_TEMP - CHICKEN_TEMPTOLERANCE))
          {
            digitalWrite(FANPIN,HIGH);
            digitalWrite(HEATERPIN,LOW);
            if(temperature<=(CHICKEN_TEMP - CHICKEN_TEMPTOLERANCE - CHICKEN_TEMPTRESHOLD))
                {
                  Calarm();
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

void C_HUMIDITY_REG18(){

Serial.println(" C_HUMIDITY_REG18");
   if ( (humidity>=(CHICKEN_HUMID_18-CHICKEN_HUMIDTOLERANCE_18))&& (humidity<=(CHICKEN_HUMID_18+CHICKEN_HUMIDTOLERANCE_18)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
CHICKENREAD_TH();
  if (humidity>(CHICKEN_HUMID_18+CHICKEN_HUMIDTOLERANCE_18))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(CHICKEN_HUMID_18+CHICKEN_HUMIDTOLERANCE_18+CHICKEN_HUMIDTRESHOLD_18))
                 {
                    digitalWrite(FANPIN,LOW);
                    Calarm();
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
          
CHICKENREAD_TH();
  if (humidity<(CHICKEN_HUMID_18 - CHICKEN_HUMIDTOLERANCE_18))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(CHICKEN_HUMID_18 - CHICKEN_HUMIDTOLERANCE_18 - CHICKEN_HUMIDTRESHOLD_18))
                {
                  
                  Calarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Calarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void C_HUMIDITY_REG21(){

Serial.print(" C_HUMIDITY_REG21");
   if ( (humidity>=(CHICKEN_HUMID_21-CHICKEN_HUMIDTOLERANCE_21))&& (humidity<=(CHICKEN_HUMID_21+CHICKEN_HUMIDTOLERANCE_21)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
CHICKENREAD_TH();
  if (humidity>(CHICKEN_HUMID_21+CHICKEN_HUMIDTOLERANCE_21))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(CHICKEN_HUMID_21+CHICKEN_HUMIDTOLERANCE_21+CHICKEN_HUMIDTRESHOLD_21))
                 { 
                    digitalWrite(FANPIN,LOW);
                    Calarm();
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
          
CHICKENREAD_TH();
  if (humidity<(CHICKEN_HUMID_21 - CHICKEN_HUMIDTOLERANCE_21))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(CHICKEN_HUMID_21 - CHICKEN_HUMIDTOLERANCE_21 - CHICKEN_HUMIDTRESHOLD_21))
                { 
                  Calarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Calarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void CHICKEN()
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
  lcd.print(CHICKEN_SECSPIN); 
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

if (CHICKEN_TSPIN==0){
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
  lcd.print(CHICKEN_SPIN);
  lcd.setCursor(11,2);
  lcd.print(":");
  lcd.setCursor(12,2);
  lcd.print(CHICKEN_MINUTESPIN);
  lcd.setCursor(14,2);
  lcd.print(":");
  lcd.setCursor(15,2);
  lcd.print(CHICKEN_SECSPIN);   
}
  DateTime startday(a,b,c,d,e,f);
  startday = rtc.now();
  lcd.setCursor(0,3);
  lcd.print("HATCH IN = ");
  lcd.setCursor(11,3);
  lcd.print(CHICKEN_DAYS_REMAIN);
     if (CHICKEN_DAYS_REMAIN<10){
            lcd.setCursor(12,3);
            lcd.print(" ");
            }

  lcd.setCursor(14,3);
  lcd.print("Days");
  lcd.setCursor(15,2);
  lcd.print(CHICKEN_SECSPIN);
     if(CHICKEN_SECSPIN<10)
             lcd.setCursor(16,2);
             lcd.print(""); 
 
     if(CHICKEN_MINUTESPIN<10)
             lcd.setCursor(13,2);
             lcd.print(" "); 

     if(CHICKEN_SPIN<10){
             lcd.setCursor(10,2);
             lcd.print(" ");
             }

if ((CHICKEN_SECSPIN==0)&& CHICKEN_MINUTESPIN)
{
  CHICKEN_MINUTESPIN = CHICKEN_MINUTESPIN - 1;
  CHICKEN_SECSPIN = 59;
}

if ((CHICKEN_MINUTESPIN==0)&& CHICKEN_SPIN)
{
  CHICKEN_SPIN = CHICKEN_SPIN - 1;
  CHICKEN_MINUTESPIN = 59;
}

if((CHICKEN_SPIN ==0) && (CHICKEN_MINUTESPIN==0) && (CHICKEN_SECSPIN==0))
{
  digitalWrite(MOTORPIN,LOW);
  delay(10000);
  digitalWrite(MOTORPIN,HIGH);
  CHICKEN_SPIN = CHICKEN_TSPIN ;
  CHICKEN_MINUTESPIN =00;
  CHICKEN_SECSPIN =00;
}
  lcd.setCursor(15,2);
  lcd.print(CHICKEN_SECSPIN); 
 
C_TEMP_REG();  


if(CHICKEN_DAYS_REMAIN >3)
{ 
  C_HUMIDITY_REG18();
} 
else {
  C_HUMIDITY_REG21();}
  
 lcd.setCursor(15,2);
 lcd.print(CHICKEN_SECSPIN); 
 lcd.setCursor(15,2);
 lcd.print(CHICKEN_SECSPIN); 

if(CHICKEN_DAYS_REMAIN == 0)
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
  lcd.print(CHICKEN_SECSPIN); 

DateTime now (a,b,c,d,e,f); 
delay(20);
       for (int n=1; n<50; n++)

         if (CHICKEN_INCUBATION >= n){
            {
                    if (rtc.now() == ( now + TimeSpan(n,0,0,0))) 
                            {
                             CHICKEN_DAYS_REMAIN = CHICKEN_INCUBATION - n;
                             Serial.print(CHICKEN_DAYS_REMAIN);
                            } 
             }}
 }

    /*       for (int kl=1; kl<50; kl++)

         if (CHICKEN_DAYS_REMAIN >= kl){
            {
                    if (rtc.now() == ( now + TimeSpan(0,0,0,kl))) 
                            {
                             CHICKEN_INCUBATION  = CHICKEN_DAYS_REMAIN - kl;
                             Serial.print(CHICKEN_DAYS_REMAIN);
                            } 
             }}
              
 }*/             

      
      


/*  FOR DAYS NA
             
{ if  ((rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,0,30,0)))||(rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,2,0,0)))||(rtc.now() == ( startday + TimeSpan(n,5,0,0)))||(rtc.now() == ( startday + TimeSpan(n,10,0,0)))) 
                            {
                              CHICKEN_DAYS_REMAIN = CHICKEN_INCUBATION - n;
                              EEPROM.write(CHICKEN_DAYS_REMAINaddress,CHICKEN_DAYS_REMAIN);
                              delay(10);
                            }

                  }

      } 


 }*/
