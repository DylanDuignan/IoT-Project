#include <Servo.h>
#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;
const byte ROWS = 4;                /*Define the number of rows*/
const byte COLS = 4;                /*Define the number of columns*/
const char PASSWORD[4] = "2085";    /*Define the password*/
double cashMoney = 0;                     /*Define Balance*/
char userInput = 0;

char keys[ROWS][COLS] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Servo myservo;

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

    myservo.attach(10);   //attaches the servo on pin 10 to the servo object
    myservo.write(0);    
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
                Menu();
                
          }
          else{
            lcd.setRGB(255, 0, 0);
            lcd.setCursor(0,1);
                lcd.print("Invalid PIN");
                
                for(int i=0; i<4; i++)
                {
                  currentPassword[i] = 0; 
                }
}
         }
          } 
          }
          }
          
void Menu()
{
             
              myservo.write(90);
              lcd.setCursor(0,0);
              lcd.clear();
                lcd.print("1.$5 2.$10 4.$20");
                lcd.setCursor(0,1);
                lcd.print("5.$50 7.$100");
                /*char devid[] = "v963896FDE673C9F";
                char serverName[] = "api.pushingbox.com";
                boolean DEBUG = true;
                #include <Bridge.h>
                #include <HttpClient.h>
                Serial.begin(9600);
  while (!Serial); // wait for a serial connection

  // Initialize the client library
  HttpClient client;

  //Setup sensorValue to read a value from Analog Port A0
  char depositValueChoice = keypad.getKey();
  int depositValue;
  
  switch(depositValueChoice)
  {
    case '1': depositValue = 5; break;
    case '2': depositValue = 10;break;
    case '4': depositValue = 20;break;
    case '5': depositValue = 50;break;
    case '6': depositValue = 100;break;
    default: break;
  }
  //Testing value - when sensor is not connected - comment out when sketch is shown to be working - and take value from A0 instead
  //sensorValue=1500;

  // Make a HTTP request:  
  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&TempC="+depositValue;
  client.get (APIRequest);
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();

  }
  Serial.flush();
  String UploadMessage;
  Serial.print("\n Uploaded temp value: ");
  Serial.print(depositValue);
  delay(5000);*/
}
            
            
            







/*********************************************************************************************************
    END FILE
*********************************************************************************************************/
