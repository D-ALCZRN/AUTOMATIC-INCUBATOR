#include "chicken.h"
#include "DUCK.h"
#include "QUAIL.h"
#include "GMTCLOCK.h"
#include "manual.h"
#include "CALIBRATE.h"



void touchscreen(){ 
  RESETINC();
  MAINSET();
  lcd.clear();
  digitalWrite(ALARMPIN,HIGH);
  delay(100);
  digitalWrite(ALARMPIN,LOW);
  delay(100);

  while (1){
    
    GMTCLOCK();
     
     if (ts.dataAvailable())
    {
      ts.read();
      x=ts.getX();
      y=ts.getY();
      
  
         if ((x>=10) && (x<=145) && (y>=80) && (y<=150))    // INCUBATION BUTTON BUTTON
      { tft.fillScreen(ILI9341_WHITE);
        drawButtons();
              while (true)
  {
   GMTCLOCK();
   
 
    if (ts.dataAvailable())
    {
      ts.read();
      x=ts.getX();
      y=ts.getY();
      
  
         if ((x>=10) && (x<=145) && (y>=80) && (y<=150))    // CHICKEN BUTTON
      { 
        
          tft.fillScreen(ILI9341_CYAN);
          tft.setTextColor(ILI9341_BLACK);
          tft.setTextSize(4);
          tft.setCursor(77,25);
          tft.print("CHICKEN");

        
          tft.fillRoundRect (53,  180,   80,   30, 0,  ILI9341_BLACK);  // BACK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(70,187);
          tft.print("BACK");
          
          tft.fillRoundRect (186,  180,   80,   30, 0,  ILI9341_BLUE);  // OK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(204,187);
          tft.print("OKAY");
          
          tft.fillRoundRect (70,  80,   180,   80, 5,  ILI9341_WHITE); 
           tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,103);
              tft.print("Do you want");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,122);
              tft.print("to proceed?");
 
          while (1) {
            if (ts.dataAvailable())
                  {
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();

            if ((x>=186) && (x<=266) && (y>=180) && (y<=210))
            { 
              
              tft.fillScreen(ILI9341_PINK);
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(3);
              tft.setCursor(15,15);
              tft.print("INCUBATING...");
               
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,50);
              tft.print("Types of egg:Chicken");
              
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,80);
              tft.print("Temperature: 35-37.5 C");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,110);
              tft.print("Humidity: 60%");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,140);
              tft.print("Required days: 21 days");
              
              tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
              tft.setTextColor(ILI9341_WHITE);
              tft.setTextSize(2);
              tft.setCursor(143,187);
              tft.print("END");
              lcd.clear();
              CHICKEN21();
              //Serial.print("setalarm");
              //rtc.setAlarm1(rtc.now() + TimeSpan(0,0,2,0),DS3231_A1_Minute);
              while (1){
                      
                      CHICKEN();
                      WATER_LEVEL_CHECK();
                      
                     if (ts.dataAvailable()){
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();
                          if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }}
                
                else if (CHICKEN_DAYS_REMAIN <1 ) {  
                                                      Serial.print("HATCH!!!");
                                                      tft.fillScreen(0xFA20);
                                                      tft.fillRoundRect (50,  65,   220, 80, 10,  ILI9341_WHITE); 

                                                   
                                                      tft.setTextColor(ILI9341_BLACK);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(70,96);
                                                      tft.print("INCUBATION DONE");
                                                      tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
                                                      tft.setTextColor(ILI9341_WHITE);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(137,187);
                                                      tft.print("OKAY");
                                             while(1){
                                                        alarm();
                                                        lcd.setCursor(0,3);
                                                        lcd.print("HATCH IN = ");
                                                        lcd.setCursor(11,3);
                                                        lcd.print(CHICKEN_DAYS_REMAIN);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                   ");
                                                        delay(300);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("INCUB. TIME REACHED");
                                                        delay(500);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                    ");
                                                        delay(300);
                                                        if (ts.dataAvailable()){
                                                                            ts.read();
                                                                            x=ts.getX();
                                                                            y=ts.getY();
                                                                            if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }
              }    
              }
              }
              }
              
               
            }
              
            else if ((x>=53) && (x<=133) && (y>=180) && (y<=210))
            {
              return(1);
              
              }
              
      }

      }
      }

         else if ((x>=165) && (x<=290) && (y>=80) && (y<=150))    // DUCK BUTTON
      {
          tft.fillScreen(0x05FF);
          tft.setTextColor(ILI9341_BLACK);
          tft.setTextSize(4);
          tft.setCursor(115,25);
          tft.print("DUCK");

          tft.fillRoundRect (70,  80,   180,   80, 5,  ILI9341_WHITE); 
           tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,103);
              tft.print("Do you want");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,122);
              tft.print("to proceed?");
          
          tft.fillRoundRect (53,  180,   80,   30, 0,  ILI9341_BLACK);  // BACK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(70,187);
          tft.print("BACK");
          
          tft.fillRoundRect (186,  180,   80,   30, 0,  ILI9341_BLUE);  // OK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(204,187);
          tft.print("OKAY");
          
          
          while (1) {
            if (ts.dataAvailable())
                  {
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();

            if ((x>=186) && (x<=266) && (y>=180) && (y<=210))
            {
              tft.fillScreen(ILI9341_PINK);
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(3);
              tft.setCursor(15,15);
              tft.print("INCUBATING...");
               
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,50);
              tft.print("Types of egg:Duck");
              
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,80);
              tft.print("Temperature: 35-37.5 C");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,110);
              tft.print("Humidity: 60%");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,140);
              tft.print("Required days: 28 days");
              
              tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
              tft.setTextColor(ILI9341_WHITE);
              tft.setTextSize(2);
              tft.setCursor(143,187);
              tft.print("END");
              lcd.clear();
              DUCK28();
             
              while (1){
              
             DUCK();
             WATER_LEVEL_CHECK();
                      
                    if (ts.dataAvailable()){
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();
                          if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }}
                
                else if (DUCK_DAYS_REMAIN <1 ) {  
                                                      Serial.print("HATCH!!!");
                                                      tft.fillScreen(0xFA20);
                                                      tft.fillRoundRect (50,  65,   220, 80, 10,  ILI9341_WHITE); 

                                                   
                                                      tft.setTextColor(ILI9341_BLACK);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(70,96);
                                                      tft.print("INCUBATION DONE");
                                                      tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
                                                      tft.setTextColor(ILI9341_WHITE);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(137,187);
                                                      tft.print("OKAY");
                                             while(1){
                                                        alarm();
                                                        lcd.setCursor(0,3);
                                                        lcd.print("HATCH IN = ");
                                                        lcd.setCursor(11,3);
                                                        lcd.print(QUAIL_DAYS_REMAIN);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                   ");
                                                        delay(300);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("INCUB. TIME REACHED");
                                                        delay(500);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                    ");
                                                        delay(300);
                                                        if (ts.dataAvailable()){
                                                                            ts.read();
                                                                            x=ts.getX();
                                                                            y=ts.getY();
                                                                            if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }
              }    
              }
              }
              }
              
               
            }
              
            else if ((x>=53) && (x<=133) && (y>=180) && (y<=210))
            {
              return(1);
              
              }
              
      }
      }
        }
        
        
        else if ((x>=10) && (x<=145) && (y>=170) && (y<=220))    // QUAIL BUTTON
      {
          tft.fillScreen(0x1C9F);
          tft.setTextColor(ILI9341_BLACK);
          tft.setTextSize(4);
          tft.setCursor(105,25);
          tft.print("QUAIL");

          tft.fillRoundRect (70,  80,   180,   80, 5,  ILI9341_WHITE); 
           tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,103);
              tft.print("Do you want");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,122);
              tft.print("to proceed?");
              
          tft.fillRoundRect (53,  180,   80,   30, 0,  ILI9341_BLACK);  // BACK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(70,187);
          tft.print("BACK");
          
          tft.fillRoundRect (186,  180,   80,   30, 0,  ILI9341_BLUE);  // OK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(204,187);
          tft.print("OKAY");
          
          while (1) {
            if (ts.dataAvailable())
                  {
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();

            if ((x>=186) && (x<=266) && (y>=180) && (y<=210))
            {
              tft.fillScreen(ILI9341_PINK);
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(3);
              tft.setCursor(15,15);
              tft.print("INCUBATING...");
               
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,50);
              tft.print("Types of egg:Quail");
              
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,80);
              tft.print("Temperature: 36.9-37.2 C");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,110);
              tft.print("Humidity: 70%");

              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,140);
              tft.print("Required days: 18 days");
              
              tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
              tft.setTextColor(ILI9341_WHITE);
              tft.setTextSize(2);
              tft.setCursor(143,187);
              tft.print("END");
              lcd.clear();
              QUAIL18();
             
              while (1){
               
                      QUAIL();
                      WATER_LEVEL_CHECK();
                      
                    if (ts.dataAvailable()){
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();
                          if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }}
                
                else if (QUAIL_DAYS_REMAIN <1 ) {  
                                                      Serial.print("HATCH!!!");
                                                      tft.fillScreen(0xFA20);
                                                      tft.fillRoundRect (50,  65,   220, 80, 10,  ILI9341_WHITE); 

                                                   
                                                      tft.setTextColor(ILI9341_BLACK);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(70,96);
                                                      tft.print("INCUBATION DONE");
                                                      tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
                                                      tft.setTextColor(ILI9341_WHITE);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(137,187);
                                                      tft.print("OKAY");
                                             while(1){
                                                        alarm();
                                                        lcd.setCursor(0,3);
                                                        lcd.print("HATCH IN = ");
                                                        lcd.setCursor(11,3);
                                                        lcd.print(QUAIL_DAYS_REMAIN);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                   ");
                                                        delay(300);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("INCUB. TIME REACHED");
                                                        delay(500);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                    ");
                                                        delay(300);
                                                        if (ts.dataAvailable()){
                                                                            ts.read();
                                                                            x=ts.getX();
                                                                            y=ts.getY();
                                                                            if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }
              }    
              }
              }
              }
              
               
            }
              
            else if ((x>=53) && (x<=133) && (y>=180) && (y<=210))
            {
              return(1);
              
              }
              
              
              
      }
      }
        }

       else if ((x>=165) && (x<=290) && (y>=170) && (y<=220))    // MANUAL BUTTON
      {
          tft.fillScreen(0x0011);
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(58,25);
          tft.print("MANUAL INCUBATION");

          tft.fillRoundRect (70,  80,   180,   80, 5,  ILI9341_WHITE); 
           tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,103);
              tft.print("Do you want");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(95,122);
              tft.print("to proceed?");

           tft.fillRoundRect (53,  180,   80,   30, 0,  ILI9341_BLACK);  // BACK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(70,187);
          tft.print("BACK");
          
          tft.fillRoundRect (186,  180,   80,   30, 0,  ILI9341_BLUE);  // OK
          tft.setTextColor(ILI9341_WHITE);
          tft.setTextSize(2);
          tft.setCursor(204,187);
          tft.print("OKAY");
          
          while (1) {
            if (ts.dataAvailable())
                  {
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();

            if ((x>=186) && (x<=266) && (y>=180) && (y<=210))
            { 
              tft.fillScreen(ILI9341_PINK);
              tft.setTextColor(ILI9341_BLUE);
              tft.setTextSize(2);
              tft.setCursor(15,15);
              tft.print("MANUAL INCUBATION");
               
              tft.fillRoundRect (100,  50,   120,   30, 0,  ILI9341_BLACK);  // END
              tft.setTextColor(ILI9341_CYAN);
              tft.setTextSize(2);
              tft.setCursor(119,58);
              tft.print("WARNING");
              
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,90);
              tft.print("Please monitor carefully");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,110);
              tft.print("while using manual");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,130);
              tft.print("incubation to properly");
              tft.setTextColor(ILI9341_BLACK);
              tft.setTextSize(2);
              tft.setCursor(15,150);
              tft.print("hatch the egg.");
              
             
              tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
              tft.setTextColor(ILI9341_WHITE);
              tft.setTextSize(2);
              tft.setCursor(143,187);
              tft.print("END");
              menu();
              while (1){
                
                MANUAL_LCDPRINT();
                WATER_LEVEL_CHECK();
                if (ts.dataAvailable()){
                    ts.read();
                    x=ts.getX();
                    y=ts.getY();
                          if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }}
                
                else if (NoINCUBATIONDAYSLEFT <1 ) {  
                                                      Serial.print("HATCH!!!");
                                                      tft.fillScreen(0xFA20);
                                                      tft.fillRoundRect (50,  65,   220, 80, 10,  ILI9341_WHITE); 

                                                   
                                                      tft.setTextColor(ILI9341_BLACK);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(70,96);
                                                      tft.print("INCUBATION DONE");
                                                      tft.fillRoundRect (120,  180,   80,   30, 0,  ILI9341_BLUE);  // END
                                                      tft.setTextColor(ILI9341_WHITE);
                                                      tft.setTextSize(2);
                                                      tft.setCursor(137,187);
                                                      tft.print("OKAY");
                                             while(1){
                                                        alarm();
                                                        lcd.setCursor(0,3);
                                                        lcd.print("HATCH IN = ");
                                                        lcd.setCursor(11,3);
                                                        lcd.print(NoINCUBATIONDAYSLEFT);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                   ");
                                                        delay(300);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("INCUB. TIME REACHED");
                                                        delay(500);
                                                        lcd.setCursor(0,3);
                                                        lcd.print("                    ");
                                                        delay(300);
                                                        if (ts.dataAvailable()){
                                                                            ts.read();
                                                                            x=ts.getX();
                                                                            y=ts.getY();
                                                                            if ((x>=120) && (x<=200) && (y>=180) && (y<=210))
                                                                            {return(1); }
              }    
              }
              }
              }
              
               
            }
              
            else if ((x>=53) && (x<=133) && (y>=180) && (y<=210))
            {
              return(1);
              }
              
      }
      }
        }
  
        }
      
    }
}
        
      else if ((x>=165) && (x<=290) && (y>=80) && (y<=150)) {
    CALIBRATE();
    return(1);} }
      
 
  }
}


   
  
  
  
