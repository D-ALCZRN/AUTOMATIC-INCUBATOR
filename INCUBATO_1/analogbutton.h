void MAINSET(){
   tft.fillScreen(ILI9341_BLACK);
   
   tft.fillRoundRect (10,  60,   145,   80,  0,  0xFFFC);   // INCUBATION
   tft.fillRoundRect (165, 60,   150,   80,  0,  ILI9341_YELLOW);         // CALIBRATION 
   tft.drawRoundRect (10,  60,   145,   80, 0,  ILI9341_WHITE);  // INCUBATION
   tft.drawRoundRect (165, 60,   150,   80, 0,  ILI9341_WHITE);  // CALIBRATION 

   tft.setTextColor(ILI9341_WHITE);
   tft.setTextSize(3);
   tft.setCursor(78,15);
   tft.print("MAIN MENU");
   
   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(2);
   tft.setCursor(175,95);
   tft.print("CALIBRATION");
   
   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(2);
   tft.setCursor(23,95);
   tft.print("INCUBATION");

              tft.setTextColor(ILI9341_CYAN);
              tft.setTextSize(1);
              tft.setCursor(15,170);
              tft.print("NOTE: IF THE SYSTEM HAS JUST BEEN OPENED OR IS");
              tft.setTextColor(ILI9341_CYAN);
              tft.setTextSize(1);
              tft.setCursor(15,180);
              tft.print("BEING USED FOR FIRST TIME, IT MUST GO THROUGH ");
              tft.setTextColor(ILI9341_CYAN);
              tft.setTextSize(1);
              tft.setCursor(15,190);
              tft.print("CALIBRATION FIRST.");
              //tft.setTextColor(ILI9341_BLUE);
              //tft.setTextSize(1);
              //tft.setCursor(15,200);
              //tft.print("FIRST");
              
   }
void drawButtons()
{

  
//Draw buttons
 // for (x=0; x<5; x++)
  {
  // tft.drawRoundRect (3,      40, 100,  160,    10,  ILI9341_WHITE); 
 

   // (X, Y, WIDTH, LENGHT, RADIUS)
   tft.fillRoundRect (0,  0,    320,   50,    0,  0x8800);        // MENU
   tft.fillRoundRect (10,  60,   145,   80,  0,  ILI9341_CYAN);   // CHICKEN
   tft.fillRoundRect (165, 60,   150,   80,  0,  0x05FF);         // DUCK 
   tft.fillRoundRect (10,  150,  145,   80,  0,  0x1C9F);         // QUAIL
   tft.fillRoundRect (165, 150,  150,   80,  0,  ILI9341_BLUE);   // MANUAL

   tft.drawRoundRect (0,   0,    320,   50, 0,  ILI9341_BLACK);  // MENU
   tft.drawRoundRect (10,  60,   145,   80, 0,  ILI9341_BLACK);  // CHICKEN
   tft.drawRoundRect (165, 60,   150,   80, 0,  ILI9341_BLACK);  // DUCK 
   tft.drawRoundRect (10,  150,  145,   80, 0,  ILI9341_BLACK);  // QUAIL
   tft.drawRoundRect (165, 150,  150,   80, 0,  ILI9341_BLACK);  // MANUAL


   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(3);
   tft.setCursor(21,90);
   tft.print("CHICKEN");
  
   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(3);
   tft.setCursor(207,90);
   tft.print("DUCK");
  
   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(3);
   tft.setCursor(43,178);
   tft.print("QUAIL");

   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(2);
   tft.setCursor(207,170);
   tft.print("MANUAL");
   tft.setTextColor(ILI9341_BLACK);
   tft.setTextSize(2);
   tft.setCursor(183,190);
   tft.print("INCUBATION");

   tft.setTextColor(ILI9341_WHITE);
   tft.setTextSize(3);
   tft.setCursor(19,15);
   tft.print("INCUBATION MENU");
}
}
