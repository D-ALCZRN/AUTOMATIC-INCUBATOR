void title(){ lcd.setCursor(6, 1);
  lcd.print("PROJECT");
  lcd.setCursor(7, 2);
  lcd.print("HATCHIT");
}
    

void printbig(int i, int x)
{
  //  prints each segment of the big numbers

  if (i == 0) {
      lcd.setCursor(x,0);
      lcd.write(8);  
      lcd.write(1); 
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.write(3);  
      lcd.write(4);  
      lcd.write(5);
  }
    else if  (i == 1) {
      lcd.setCursor(x,0);
      lcd.write(8);
      lcd.write(255);
      lcd.print(" ");
      lcd.setCursor(x, 1);
      lcd.print(" ");
      lcd.write(255);
      lcd.print(" ");
    }

    else if  (i == 2) {
      lcd.setCursor(x,0);
      lcd.write(1);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(4);
    }

    else if (i == 3) {
      lcd.setCursor(x,0);
      lcd.write(1);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.write(4);
      lcd.write(7);
      lcd.write(5); 
    }

    else if (i == 4) {
      lcd.setCursor(x,0);
      lcd.write(3);
      lcd.write(4);
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.print("  ");
      lcd.write(5);
    }

    else if (i == 5) {
      lcd.setCursor(x,0);
      lcd.write(255);
      lcd.write(6);
      lcd.write(1);
      lcd.setCursor(x, 1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
    }

    else if (i == 6) {
      lcd.setCursor(x,0);
      lcd.write(8);
      lcd.write(6);
      lcd.print(" ");
      lcd.setCursor(x, 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
    }

    else if (i == 7) {
      lcd.setCursor(x,0);
      lcd.write(1);
      lcd.write(1);
      lcd.write(5);
      lcd.setCursor(x, 1);
      lcd.print(" ");
      lcd.write(8);
      lcd.print(" ");
    }
    
    else if (i == 8) {
      lcd.setCursor(x,0);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
    }

    else if (i == 9) {
      lcd.setCursor(x,0);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(x, 1);
      lcd.print(" ");
      lcd.write(4);
      lcd.write(5);
    }

  } 
void timeset() 
{
  //fill in the clock numbers
  printbig((h%10),3);
  printbig((h/10),0);
  printbig((m%10),10);
  printbig((m/10),7);
  printbig((s%10),17);
  printbig((s/10),14);

  // fill in the date
  /*lcd.setCursor(0, 2);
  lcd.print(DOW[dy]);
  lcd.setCursor(4, 2);
  lcd.print(dt/10);
  lcd.print(dt%10);
  lcd.setCursor(7, 2);
  lcd.print(MTH[mt]);
*/
  DateTime now = rtc.now();   // read again the time
}

void GMTCLOCKSET() {

 // set up the LCD's number of columns and rows:
 

 // *******DEFINE CUSTOM CHARACTERS FOR BIG FONT*****************
  byte A[8] =
  {
  B00011,
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111
  };
  byte B[8] =
  {
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
  };
  byte C[8] =
  {
  B11000,
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
  };
  byte D[8] =
  {
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111,
  B00011
  };
  byte E[8] =
  {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
  };
  byte F[8] =
  {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100,
  B11000
  };
  byte G[8] =
  {
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
  };
  byte H[8] =
  {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
  };
  
  lcd.createChar(8,A);
  lcd.createChar(6,B);
  lcd.createChar(2,C);
  lcd.createChar(3,D);
  lcd.createChar(7,E);
  lcd.createChar(5,F);
  lcd.createChar(1,G);
  lcd.createChar(4,H);
 
  // Print a message to the LCD.
  // lcd.setCursor(col, row);
  // lcd.print("text");
 
delay(1000);
  

    
  // print all the fix text - never changes
 lcd.setCursor(0, 0);
  lcd.print(" __ __"+String(char(165))+" __ __"+(char(165))+" __ __");  // char(165) is big point symbol
  lcd.setCursor(0, 1);
lcd.print("      "+String(char(165))+"      "+(char(165))+"      ");
  lcd.setCursor(3, 3);
  lcd.print("/");
    lcd.setCursor(6, 3);
  lcd.print("/");
  
    
// char(223) is degree symbol  
// read all time and date and display
  DateTime now = rtc.now();
  h  = now.hour();
  m  = now.minute();
  s  = now.second();
  yr = now.year();
  mt = now.month();
  dt = now.day();
  dy = now.dayOfTheWeek();
  olds = s;

// fill the display with all the data
  printbig((h%10),3);
  printbig((h/10),0);
  printbig((m%10),10);
  printbig((m/10),7);
  printbig((s%10),17);
  printbig((s/10),14);

  lcd.setCursor(0, 3);
  lcd.print(DOW[dy]);
  lcd.setCursor(4, 3);
  lcd.print(dt/10);
  lcd.print(dt%10);
  lcd.setCursor(7, 3);
  lcd.print(MTH[mt]);
  lcd.setCursor(12, 3);
  lcd.print(rtc.getTemperature()+String(char(223)));
  lcd.print("C");
  

}

void GMTCLOCK() {
  GMTCLOCKSET();
  DateTime now = rtc.now();
 
  s  = now.second();                        // read seconds
  if (olds != s) {                          // if seconds changed
/*    Serial.println(dy);
    Serial.println(mt);
    Serial.println(dt);
    Serial.println(yr); */
      printbig((s%10),17);                  // display seconds
      printbig((s/10),14);
      olds = s;
      //timeset();                      // verify if user wants to set time
      if ( s == 0 ) {                       // minutes change
          m  = now.minute();                // read minutes
          printbig((m%10),10);              // display minutes
          printbig((m/10),7);
          if (m == 0) {                     // hours change
            h  = now.hour();                // read hours
            printbig((h%10),3);             // dislay hours
            printbig((h/10),0);
            if (h == 0) {                   // day change
              dt = now.day();               // read day
              dy = now.dayOfTheWeek();
              mt = now.month();             // read month
              yr = now.year();              // read year
              //lcd.setCursor(0, 2);          // display date full
              //lcd.print(DOW[dy]);
              //lcd.setCursor(4, 2);
              //lcd.print(dt/10);
              //lcd.print(dt%10);
              //lcd.setCursor(7, 3);
              //lcd.print(MTH[mt]);
          }
      }
    }

}
}
