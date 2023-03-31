float DUCK_TEMP = 37;
float DUCK_TEMPTOLERANCE = 0.1;
float DUCK_TEMPTRESHOLD = 0.1;

float DUCK_HUMID_25 = 65;
float DUCK_HUMIDTOLERANCE_25 = 5.0;
float DUCK_HUMIDTRESHOLD_25 = 1;

float DUCK_HUMID_28 = 73;
float DUCK_HUMIDTOLERANCE_28 = 3.0;
float DUCK_HUMIDTRESHOLD_28 = 1;

int DUCK_INCUBATION = 0;
int DUCK_DAYS_REMAIN = 0;

int DUCK_TSPIN = 0;
int DUCK_SECSPIN = 0;
int DUCK_MINUTESPIN = 0;
int DUCK_SPIN = 0;

void BLINKDUCK(void)
{
  if(DUCK_SECSPIN>0)
  DUCK_SECSPIN = DUCK_SECSPIN -1;
}

void DUCK28(){
  DUCK_DAYS_REMAIN = 0+28;
  DUCK_INCUBATION = 0+28;
  DUCK_SECSPIN = 0+59;
  DUCK_MINUTESPIN = 0+59;
  DUCK_SPIN = 0+6;
  DUCK_TSPIN = 0+6;
lcd.createChar(0,customChar);
lcd.createChar(1,customChar1);
lcd.createChar(10,arrow);
Timer1.initialize(1000000);
Timer1.attachInterrupt(BLINKDUCK); // BLINKDUCK to run every 0.15 seconds
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

void DUCKREAD_TH (void) //DUCKREAD_TH
{
   temperature = dht.readTemperature();
   humidity = dht.readHumidity();
   lcd.setCursor(6,0);
   lcd.print(temperature);
   lcd.setCursor(7,1);
   lcd.print(humidity);
}

void Dalarm(){

               digitalWrite(ALARMPIN,HIGH);
               delay(100);
               digitalWrite(ALARMPIN,LOW);
               delay(40);
}

void D_TEMP_REG(void)
{

if (temperature==DUCK_TEMP)
{

  digitalWrite(FANPIN,HIGH);
  digitalWrite(HEATERPIN,HIGH);

}
   else if ( (temperature>=(DUCK_TEMP-DUCK_TEMPTOLERANCE))&& (temperature<=(DUCK_TEMP+DUCK_TEMPTOLERANCE)) )
      {
        digitalWrite(FANPIN,HIGH);
        digitalWrite(HEATERPIN,HIGH);
        lcd.setCursor(16,0);
        lcd.write(0);
      }

DUCKREAD_TH();
  if (temperature>(DUCK_TEMP+DUCK_TEMPTOLERANCE))
          {
              digitalWrite(FANPIN,HIGH);
              digitalWrite(HEATERPIN,HIGH);
              if(temperature>=(DUCK_TEMP+DUCK_TEMPTOLERANCE+DUCK_TEMPTRESHOLD))
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

DUCKREAD_TH();
  if (temperature<(DUCK_TEMP - DUCK_TEMPTOLERANCE))
          {
            digitalWrite(FANPIN,HIGH);
            digitalWrite(HEATERPIN,LOW);
            if(temperature<=(DUCK_TEMP - DUCK_TEMPTOLERANCE - DUCK_TEMPTRESHOLD))
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

void D_HUMIDITY_REG25(){

Serial.println(" D_HUMIDITY_REG25");
   if ( (humidity>=(DUCK_HUMID_25-DUCK_HUMIDTOLERANCE_25))&& (humidity<=(DUCK_HUMID_25+DUCK_HUMIDTOLERANCE_25)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
DUCKREAD_TH();
  if (humidity>(DUCK_HUMID_25+DUCK_HUMIDTOLERANCE_25))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(DUCK_HUMID_25+DUCK_HUMIDTOLERANCE_25+DUCK_HUMIDTRESHOLD_25))
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
          
DUCKREAD_TH();
  if (humidity<(DUCK_HUMID_25 - DUCK_HUMIDTOLERANCE_25))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(DUCK_HUMID_25 - DUCK_HUMIDTOLERANCE_25 - DUCK_HUMIDTRESHOLD_25))
                {
                  
                  Dalarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Dalarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void D_HUMIDITY_REG28(){

Serial.print(" C_HUMIDITY_REG21");
   if ( (humidity>=(DUCK_HUMID_28-DUCK_HUMIDTOLERANCE_28))&& (humidity<=(DUCK_HUMID_28+DUCK_HUMIDTOLERANCE_28)) )
      {
        digitalWrite(HUMIDIFIERPIN,HIGH);
         digitalWrite(FANPIN,HIGH);
        lcd.setCursor(16,1);
       lcd.write(0);
        
      }
DUCKREAD_TH();
  if (humidity>(DUCK_HUMID_28+DUCK_HUMIDTOLERANCE_28))
          {
           
              digitalWrite(HUMIDIFIERPIN,HIGH);
              if(humidity>=(DUCK_HUMID_28+DUCK_HUMIDTOLERANCE_28+DUCK_HUMIDTRESHOLD_28))
                 { 
                    digitalWrite(FANPIN,LOW);
                    Dalarm();
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
          
DUCKREAD_TH();
  if (humidity<(DUCK_HUMID_28 - DUCK_HUMIDTOLERANCE_28))
          {
            
            digitalWrite(HUMIDIFIERPIN,LOW);
            if(humidity<=(DUCK_HUMID_28 - DUCK_HUMIDTOLERANCE_28 - DUCK_HUMIDTRESHOLD_28))
                { 
                  Dalarm();
                  lcd.setCursor(16,1);
                  lcd.write(1);
                  delay(100);
                  Dalarm();
                  lcd.setCursor(16,1);
                  lcd.print(" "); 
                  delay(100);
                }
          }}

void DUCK()
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
  lcd.print(DUCK_SECSPIN); 
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

if (DUCK_TSPIN==0){
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
  lcd.print(DUCK_SPIN);
  lcd.setCursor(11,2);
  lcd.print(":");
  lcd.setCursor(12,2);
  lcd.print(DUCK_MINUTESPIN);
  lcd.setCursor(14,2);
  lcd.print(":");
  lcd.setCursor(15,2);
  lcd.print(DUCK_SECSPIN);   
}
  DateTime startday(a,b,c,d,e,f);
  startday = rtc.now();
  lcd.setCursor(0,3);
  lcd.print("HATCH IN = ");
  lcd.setCursor(11,3);
  lcd.print(DUCK_DAYS_REMAIN);
     if (DUCK_DAYS_REMAIN<10){
            lcd.setCursor(12,3);
            lcd.print(" ");
            }

  lcd.setCursor(14,3);
  lcd.print("Days");
  lcd.setCursor(15,2);
  lcd.print(DUCK_SECSPIN);
     if(DUCK_SECSPIN<10)
             lcd.setCursor(16,2);
             lcd.print(""); 
 
     if(DUCK_MINUTESPIN<10)
             lcd.setCursor(13,2);
             lcd.print(" "); 

     if(DUCK_SPIN<10){
             lcd.setCursor(10,2);
             lcd.print(" ");
             }

if ((DUCK_SECSPIN==0)&& DUCK_MINUTESPIN)
{
  DUCK_MINUTESPIN = DUCK_MINUTESPIN - 1;
  DUCK_SECSPIN = 59;
}

if ((DUCK_MINUTESPIN==0)&& DUCK_SPIN)
{
  DUCK_SPIN = DUCK_SPIN - 1;
  DUCK_MINUTESPIN = 59;
}

if((DUCK_SPIN ==0) && (DUCK_MINUTESPIN==0) && (DUCK_SECSPIN==0))
{
  digitalWrite(MOTORPIN,LOW);
  delay(10000);
  digitalWrite(MOTORPIN,HIGH);
  DUCK_SPIN = DUCK_TSPIN ;
  DUCK_MINUTESPIN =00;
  DUCK_SECSPIN =00;
}
  lcd.setCursor(15,2);
  lcd.print(DUCK_SECSPIN); 
 
D_TEMP_REG();  


if(DUCK_DAYS_REMAIN >3)
{ 
  D_HUMIDITY_REG25();
} 
else {
  D_HUMIDITY_REG28();}
  
 lcd.setCursor(15,2);
 lcd.print(DUCK_SECSPIN); 
 lcd.setCursor(15,2);
 lcd.print(DUCK_SECSPIN); 

if(DUCK_DAYS_REMAIN == 0)
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
  lcd.print(DUCK_SECSPIN); 

DateTime now (a,b,c,d,e,f); 
delay(20);
       for (int n=1; n<50; n++)

         if (DUCK_INCUBATION >= n){
            {
                    if (rtc.now() == ( now + TimeSpan(n,0,0,0))) 
                            {
                             DUCK_DAYS_REMAIN = DUCK_INCUBATION - n;
                             Serial.print(DUCK_DAYS_REMAIN);
                            } 
             }}
 }

    /*       for (int kl=1; kl<50; kl++)

         if (DUCK_DAYS_REMAIN >= kl){
            {
                    if (rtc.now() == ( now + TimeSpan(0,0,0,kl))) 
                            {
                             DUCK_INCUBATION  = DUCK_DAYS_REMAIN - kl;
                             Serial.print(DUCK_DAYS_REMAIN);
                            } 
             }}
              
 }*/             

      
      


/*  FOR DAYS NA
             
{ if  ((rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,0,30,0)))||(rtc.now() == ( startday + TimeSpan(n,0,0,0)))||(rtc.now() == ( startday + TimeSpan(n,2,0,0)))||(rtc.now() == ( startday + TimeSpan(n,5,0,0)))||(rtc.now() == ( startday + TimeSpan(n,10,0,0)))) 
                            {
                              DUCK_DAYS_REMAIN = DUCK_INCUBATION - n;
                              EEPROM.write(DUCK_DAYS_REMAINaddress,DUCK_DAYS_REMAIN);
                              delay(10);
                            }

                  }

      } 


 }*/
