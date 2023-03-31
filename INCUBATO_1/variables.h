short int spinaddress = 55;
short const startdayyearaddress = 81;
short const startdaymonthaddress = 82;
short const startdaydayaddress = 83;
short const startdayhouraddress = 84;
short const startdayminuteaddress = 85;
short const startdaysecondaddress = 86;
short const reftempaddress = 0;
short const refhumidaddress = 10;
short const reftemptoladdress = 20;
short const refhumidtoladdress = 30;
short const tspinaddress = 40;
short const NoINCUBATIONDAYSaddress = 50;
short const reftemptresholdaddress = 60;
short const refhumidtresholddadress = 70;
short const Noincubationdaysleftaddress = 80;
short const motordirectionaddress = 33;


int timeduringrotation = 0;
int timeduringrotationaddress = 100;

// initial set temp and humid
float REFTEMPERATURE = 35.0;
float REFTEMPTOLERANCE = 0.1;
float REFTEMPTRESHOLD = 0.3;

float REFHUMIDITY = 60.0;
float REFHUMIDTOLERANCE = 2.0;
float REFHUMIDTRESHOLD = 3;



unsigned short TSPIN = 0;
unsigned short NoINCUBATIONDAYS = 12;
unsigned short NoINCUBATIONDAYSLEFT = 12;

bool millisflag = 1;
unsigned short MINUTESPIN = 59;
unsigned short SECSPIN = 59;
unsigned short SPIN = 2;
unsigned short SPINHOLDER = 5;

float REFTEMPERATUREHOLDER ;
float REFHUMIDITYHOLDER ;
float REFTEMPTOLERANCEHOLDER ;
float REFHUMIDTOLERANCEHOLDER ;
float REFTEMPTRESHOLDHOLDER ;
float REFHUMIDTRESHOLDHOLDER;
unsigned short  TSPINHOLDER ;
int NoINCUBATIONDAYSHOLDER ;
unsigned short NoINCUBATIONDAYSLEFTHOLDER;
int timeduringrotationholder;


unsigned int a = 2003;
unsigned short b = 0;
unsigned short c = 0;
unsigned short d = 0;
unsigned short e = 0;
unsigned short f = 0;
unsigned long count, count1;


bool Home = 1;
float humidity;
float temperature;

DateTime now, endday;



int h, m, s, yr, mt, dt, dy, olds; // hous, minutes, seconds, year, month, date of the month, day, previous second
char *DOW[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; //define day of the week
char *MTH[13] = {" ", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"}; //define month
int EncoderMax;   // varialbe for h, m, s, ... max value

int encoderPos = 0;          // a counter for the dial
unsigned int lastReportedPos = 1;   // change management
static boolean rotating = false;    // debounce management

// interrupt service routine vars
boolean A_set = false;
boolean B_set = false;

// varialbe to know if we are in time setting mode
boolean set_h = false;     //hours
boolean set_m = false;     //minutes
boolean set_s = false;     //seconds
boolean set_yr = false;    //year
boolean set_mt = false;    //month
boolean set_dt = false;    //date of the month

boolean intbme = true;
boolean extbme = true;
/////////////////////////////////////////////////////


byte customChar[] = {
  B00100,
  B00100,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00100
};

byte customChar1[] = {
  B00100,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};

byte arrow[8] = {
  0b01000,
  0b01100,
  0b01110,
  0b01111,
  0b01110,
  0b01100,
  0b01000,
  0b00000
};





/*

  int b = EEPROM.read(startdaymonthaddress) ;

  int c = EEPROM.read(startdaydayaddress);

  int  d = EEPROM.read(startdayhouraddress);

  int  e= EEPROM.read(startdayminuteaddress);

  int f= EEPROM.read(startdaysecondaddress);

  int a = EEPROM.read(startdayyearaddress) /* +1791 */


// DateTime startday (EEPROM.read(startdayyearaddress), EEPROM.read(startdaymonthaddress), EEPROM.read(startdaydayaddress), EEPROM.read(startdayhouraddress), EEPROM.read(startdayminuteaddress),  EEPROM.read(startdaysecondaddress));


//DateTime startday(a,b,c,d,e,f);
