**About**
As humans we communicate with each other by our natural sensors but what we should use to share some secret information with someone? A way by which one person can pass on information in such a way that even the third person can see the message but will not able to understand without knowing the key. For this reason, we have used Morse Code communication. Morse Code is a method of exchanging information that is done by showing the original letters to the combo of a dot . and dashes - (ex: A = .. , B = -...). Here we have used Arduino to design the Morse code trainer with Watterott MIO283QT-2 Touch Screen Panel with shield to show the random original letters and a button to press the Morse code with a buzzer to beep. If the pressed Morse Code matches with the given letter then it will show "Correct" on the display or else the "Wrong" will be visible.

**Arduino OneButton Library**
This Arduino library is improving the usage of a single button for input. It shows how to use an digital input pin with a single pushbutton attached for detecting some of the typical button press events like single clicks, double clicks and long-time pressing. This enables the reuse the same button for multiple functions and lowers the hardware investments.

**Getting Started**

`
#include <MI0283QT2.h>  
#include <Arduino.h>
#include <OneButton.h>
`

**Initialization of BUTTON_PIN 3**

| Name | Description |
| ------ | ------ |
| String 'x'= ""; | Getting the random alphabet for training |
| String disp = ""; | For displaying the short dots and long lines  |
| String morse ="";  | Keeping values s for shortpress and l for long press of the button for later comparison. |
| int btntc=0; | Counting how many times button was pressed in a single test
| int rstCode=0; | Control integer for resetting the page |
| const int buzzer = 2; | Buzzer to arduino pin 2 | 
| OneButton btn(BUTTON_PIN, false); | Declaring the button |
| MI0283QT2 | lcd | Declare only one display (MI0283QT2 Adapter v1) | 

**Function**

| Type | Name | Description |
| ------ | ------ | ------ |

| String | randalpha |seeding the random operator. Generating a random alphabet upon calling which has been mod by 26 (0-26)
| String | giveBackAlpha | for comparing trainer Alphabet with button pressed morese code alphabet |
| int | giveBackSize | For getting the size of the morse code of the trainer value |
| void | longPress | Configuring Longpress Button |
| void  | singleClick | Configuring short press button |

**Setup**

pinMode(buzzer, OUTPUT); // Set buzzer - pin 2 as an output

//attach shortclick to button

btn.attachClick(singleClick); 

//attach longclick to button

btn.attachLongPressStart(longPress); 

lcd.begin(7); //spi-clk=SPI_CLOCK_DIV4 , display initialization(LCD- clear screen, brightness 50% given)

**Void Loop**

`{


    btn.tick();   //for invoking shortpress or long press when button pressed
    if(!btn.isLongPressed())noTone(buzzer); //turning of the buzzer
    
`
    

`if(lcd.touchZ()||rstCode>1) //touch press or reset code changed
  {
   
  
     rstCode=0;
     disp ="";
     morse ="";
    
       
          x = randalpha(); //calling the random alphabet
         //clear screen
        lcd.fillScreen(RGB(0 ,255,255));
        lcd.drawText(100, 80,x, RGB(255,0,0), RGB(255,255,255), 11);

      
      }`
      
      `if(btntc>0){ //if button pressed atleast once

        String mCompare = giveBackAlpha(); //Comparing with Morse Code using giveBackAlpha 
        
        if(mCompare.compareTo(x)==0){
        delay(500);
        noTone(buzzer);
        lcd.fillScreen(RGB(0 ,128,0));
        lcd.drawText(10, 80,"CORRECT!", RGB(255,0,0), RGB(255,255,255),4 );
        

        delay(3000);
        btntc=0;
        rstCode=2;
        }`
        
        `else if(btntc>=giveBackSize()){ //if number of time for button pressed is equals to or greater than the requiered number for morse code
           noTone(buzzer);

           lcd.fillScreen(RGB(255 ,0,0));
           lcd.drawText(10, 80,"Wrong!", RGB(255,255,255), RGB(255,0,0),4 );
          
           delay(3000);
        btntc=0;
        rstCode=2; // entry to the loop again by resetting 
          }
`













