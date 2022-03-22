/*
    Hello World.ino
    2013 Copyright (c) Seeed Technology Inc.  All right reserved.

    Author:Loovee
    2013-9-18

    Grove - Serial LCD RGB Backlight demo.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const byte ROWS = 4;                /*Define the number of rows*/
const byte COLS = 4;                /*Define the number of columns*/
const char PASSWORD[4] = "1234";    /*Define the password*/
double bal = 0;                     /*Define Balance*/

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

    if (key)
    {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("IT WORKS");  
        
          Serial.println(key);              /*Debug print received character to serial port*/

         if ((key >= '0') && (key <= '9'))
         {
          lcd.setCursor(index,1);               /*Move Cursor to next place on LCD*/
          lcd.print(key);                 /*Print received character to LCD*/
          currentPassword[index] = key;   /*Move received character in character array*/
          index++;                              /*Increase index by 1*/

          if (index >= 4)       
          /*We have 4 characters*/      
          {
            index = 0;

            if((currentPassword[0] == PASSWORD[0]) && (currentPassword[1] == PASSWORD[1]) && (currentPassword[2] == PASSWORD[2]) && (currentPassword[3] == PASSWORD[3]))
            {
              lcd.setCursor(0,1);
              lcd.print("Bal: €{bal}");
                
            }
          }
         }
         }
    }







/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
