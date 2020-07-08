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

