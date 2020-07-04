
//#include<time.h>
#include <MI0283QT2.h>
#include <Arduino.h>
#include <OneButton.h>

#define BUTTON_PIN 3

  String x = ""; //getting the random alphabet for training
  String disp = "";  //for displaying the short dots and long lines 
  String morse ="";  //keeping values s for shortpress and l for long press of the button for later comparison.
  int btntc=0;      // counting how many times button was pressed in a single test
  int rstCode=0;    //control integer for resetting the page
  
  const int buzzer = 2; //buzzer to arduino pin 2



OneButton btn(BUTTON_PIN, false); //declaring the button


//Declare only one display !
 MI0283QT2 lcd;  //MI0283QT2 Adapter v1



//Configuring Longpress Button
void longPress()
{
   btntc = btntc +1; //increasing button count
   morse = morse+"l"; //adding a long bit as l
  disp=disp +" ___ "; //adding a line for long press to show on display
  lcd.drawText(30, 180,disp, RGB(255,0,0), RGB(0,255,255), 2);  
   
  tone(buzzer, 1000); //buzzer tone with 1khz current
  
} 

//Configuring short press button
void singleClick()
{
  btntc = btntc+1;
  disp=disp +" . ";
  morse = morse +"s";
  lcd.drawText(30, 180,disp, RGB(255,0,0), RGB(0,255,255), 2);
   
 tone(buzzer, 1000);
  delay(300);
    noTone(buzzer);
}


void setup()
{
  
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 2 as an output

   
   btn.attachClick(singleClick);  //attach shortclick to button
   btn.attachLongPressStart(longPress); //attach longclick to button

  Serial.begin(9600);
 
  //init display
  lcd.begin(7); //spi-clk=SPI_CLOCK_DIV4
 

  //set touchpanel calibration data
  lcd.touchRead();
  Serial.print("\nTouchX: ");
  Serial.print(lcd.touchX());
  Serial.print("\nTouchY: ");
  Serial.print(lcd.touchY());
  Serial.print("\nTouchZ: ");
  Serial.print(lcd.touchZ());
  if(lcd.touchZ())  // || readCalData()) //calibration data in EEPROM?
  {
    lcd.touchStartCal(); //calibrate touchpanel

  }

  //clear screen
  lcd.fillScreen(RGB(0 ,255,255));

  //show backlight power and cal text
  lcd.led(50); //backlight 0...100%
  lcd.drawText(60, 100, "Touch to Start", RGB(255,0,0), RGB(255,255,255), 2);
 
}


// for generating a random Alphabet for training morse code
String randalpha()

{
  //srand((unsigned int)time(NULL)); //seeding the random operator
  int alpha = (rand() % 26);

  String alphaArray[26] = {"Z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y"};

  return alphaArray[alpha];
}

//For getting the size of the morse code of the trainer value
int giveBackSize(){
  
   if(x.compareTo("A") ==0) return 2;
    else if (x.compareTo("B") ==0) return 4;
    else if (x.compareTo("C") ==0) return 4;
    else if (x.compareTo("D") ==0) return 3;
    else if (x.compareTo("E") ==0) return 1;
    else if (x.compareTo("F") ==0) return 4;
    else if (x.compareTo("G") ==0) return 3;
    else if (x.compareTo("H") ==0) return 4;
    else if (x.compareTo("I") ==0) return 2;
    else if (x.compareTo("J") ==0) return 4;
    else if (x.compareTo("K") ==0) return 3;
    else if (x.compareTo("L") ==0) return 4;
    else if (x.compareTo("M") ==0) return 2;
    else if (x.compareTo("N") ==0) return 2;
    else if (x.compareTo("O") ==0) return 3;
    else if (x.compareTo("P") ==0) return 4;
    else if (x.compareTo("Q") ==0) return 4;
    else if (x.compareTo("R") ==0) return 3;
    else if (x.compareTo("S") ==0) return 3;
    else if (x.compareTo("T") ==0) return 1;
    else if (x.compareTo("U") ==0) return 3;
    else if (x.compareTo("V") ==0) return 4;
    else if (x.compareTo("W") ==0) return 3;
    else if (x.compareTo("X") ==0) return 4;
    else if (x.compareTo("Y") ==0) return 4;
    else if (x.compareTo("Z") ==0) return 4;

  return "";
  }


//for comparing trainer Alphabet with button pressed morese code alphabet
String giveBackAlpha(){
  
    if(morse.compareTo("sl") ==0) return "A";
    else if (morse.compareTo("lsss") ==0) return "B";
    else if (morse.compareTo("lsls") ==0) return "C";
    else if (morse.compareTo("lss") ==0) return "D";
    else if (morse.compareTo("s") ==0) return "E";
    else if (morse.compareTo("ssls") ==0) return "F";
    else if (morse.compareTo("lls") ==0) return "G";
    else if (morse.compareTo("ssss") ==0) return "H";
    else if (morse.compareTo("ss") ==0) return "I";
    else if (morse.compareTo("slll") ==0) return "J";
    else if (morse.compareTo("lsl") ==0) return "K";
    else if (morse.compareTo("slss") ==0) return "L";
    else if (morse.compareTo("ll") ==0) return "M";
    else if (morse.compareTo("ls") ==0) return "N";
    else if (morse.compareTo("lll") ==0) return "O";
    else if (morse.compareTo("slls") ==0) return "P";
    else if (morse.compareTo("llsl") ==0) return "Q";
    else if (morse.compareTo("sls") ==0) return "R";
    else if (morse.compareTo("sss") ==0) return "S";
    else if (morse.compareTo("l") ==0) return "T";
    else if (morse.compareTo("ssl") ==0) return "U";
    else if (morse.compareTo("sssl") ==0) return "V";
    else if (morse.compareTo("sll") ==0) return "W";
    else if (morse.compareTo("lssl") ==0) return "X";
    else if (morse.compareTo("lsll") ==0) return "Y";
    else if (morse.compareTo("llss") ==0) return "Z";

  return "";
  }


//start of the program
void loop()
{


    btn.tick();   //for invoking shortpress or long press when button pressed
    if(!btn.isLongPressed())noTone(buzzer); //turning of the buzzer




 

  //service routine for touch panel
  lcd.touchRead();
  Serial.print("\nTouchX: ");
  Serial.print(lcd.touchX());
  Serial.print("\nTouchY: ");
  Serial.print(lcd.touchY());
  Serial.print("\nTouchZ: ");
  Serial.print(lcd.touchZ());

  
  if(lcd.touchZ()||rstCode>1) //touch press or reset code changed
  {
   
  
     rstCode=0;
     disp ="";
     morse ="";
    
       
          x = randalpha(); 
         //clear screen
        lcd.fillScreen(RGB(0 ,255,255));
        lcd.drawText(100, 80,x, RGB(255,0,0), RGB(255,255,255), 11);

      
      }


   if(btntc>0){ //if button pressed atleast once

        String mCompare = giveBackAlpha(); 
        
        if(mCompare.compareTo(x)==0){
        delay(500);
        noTone(buzzer);
        lcd.fillScreen(RGB(0 ,128,0));
        lcd.drawText(10, 80,"CORRECT!", RGB(255,0,0), RGB(255,255,255),4 );
        

        delay(3000);
        btntc=0;
        rstCode=2;
        }else if(btntc>=giveBackSize()){ //if number of time for button pressed is equals to or greater than the requiered number for morse code
           noTone(buzzer);

           lcd.fillScreen(RGB(255 ,0,0));
           lcd.drawText(10, 80,"Wrong!", RGB(255,255,255), RGB(255,0,0),4 );
          
           delay(3000);
        btntc=0;
        rstCode=2;
          }

        
     }
}
