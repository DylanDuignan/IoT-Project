#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const byte ROWS = 4;                /*Define the number of rows*/
const byte COLS = 4;                /*Define the number of columns*/
const char PASSWORD[4] = "1245";    /*Define the password*/
double cashMoney = 0;                     /*Define Balance*/

char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char currentPassword[4];            /*Character Array for storing received password*/
char index = 0;                     /*Index for storing received character*/



void setup() {
    Serial.begin(9600);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setCursor(0,0);            /*Set the cursor to column 0*/
    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("Enter PIN");

    
}

void loop() {
    char key = keypad.getKey();     /*Get received character from keypad*/

    
          Serial.println(key);

          if(key){
          Serial.begin(9600);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setCursor(0,0);            /*Set the cursor to column 0*/
    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("Enter PIN");
     
      
        
         
      
         if ((key >= '0') && (key <= '9'))
         {
                       /*Print received character to LCD*/
          currentPassword[index] = key; 
          for(int x=0; x<4; x++)
          {
            lcd.setCursor(x,1); 
      lcd.print( currentPassword[x]);
          }
          
          
          
          /*Move received character in character array*/
          index++;    
          
          /*Increase index by 1*/

          if (index >= 4)       
          /*We have 4 characters*/      
          {
            index = 0;

            if((currentPassword[0] == PASSWORD[0]) && (currentPassword[1] == PASSWORD[1]) && (currentPassword[2] == PASSWORD[2]) && (currentPassword[3] == PASSWORD[3]))
            {
              lcd.setCursor(0,0);
              lcd.clear();
                lcd.print("1. Depo/Withdraw");
                lcd.setCursor(0,1);
                lcd.print("2. Check Balance");


char input1 = keypad.getKey();     /*Get received character from keypad*/

    
          Serial.println(input1);
          if(input1){
            
          }
                if(input1 = "1")
                {
                 do
                 {
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print("1=5 2=10 4=20 5=50");
                 lcd.setCursor(0,1);
                 lcd.print("7=100 8=500 0=Exit");
                 char userInput = keypad.getKey() ;
                 Serial.println(userInput);
                 switch(userInput)
                 case "1": cashMoney =cashMoney+ 5; break;
                 case "2": cashMoney =cashMoney+ 10; break; 
                 case "4": cashMoney =cashMoney+ 20; break;
                 case "5": cashMoney =cashMoney+ 50; break;
                 case "7": cashMoney =cashMoney+ 100; break;
                 case "8": cashMoney =cashMoney+ 200; break;
                 case "0": break; 
                 default: lcd.clear(); lcd.setCursor(0.0); lcd.print("Error");
                }
                 while(userInput != 0 )
          }}
          else{
            lcd.setCursor(0,1);
                lcd.print("NO!!!!!!!!!!!!!!!!!!!!");
                
                for(int i=0; i<4; i++)
                {
                  currentPassword[i] = 0; 
                }
                
          }
         }
          } 
          }
          
    }







/*********************************************************************************************************
    END FILE
*********************************************************************************************************/