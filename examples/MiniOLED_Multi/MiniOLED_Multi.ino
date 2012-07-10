/* Multi I2C Mini OLED Sample Code
*/

#define OLED_RESET 13  //Pin # the OLED module's RST pin is connected to.
#define NUM_DISPLAYS 2

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//It is only necessary to declare Adafruit_SSD1306 class once.
//Multiple declarations will fill the Arduino's SRAM
Adafruit_SSD1306 display(OLED_RESET);  //Declares display buffer and Adafruit Graphics library

const uint8_t CS[NUM_DISPLAYS]={8,9}; //Replace with the pins # the displays CS pins are connected to.

unsigned long time=0,Ptime=0;

void setup(){
  
  for(uint8_t i=0; i<NUM_DISPLAYS; i++){  
    pinMode(CS[i],OUTPUT);       //Sets all CS pins at output
    digitalWrite(CS[i],HIGH);    //Allows all displays to receive data simultaneously
  }
  display.begin(SSD1306_SWITCHCAPVCC); //Initializes all displays
  
  for(uint8_t i=0; i<NUM_DISPLAYS; i++){
    digitalWrite(CS[i],LOW);    //Turns off comm to all displays
  }
  display.clearDisplay();

}

int16_t value;
void loop(){
  value = (int16_t)(analogRead(A0));
  Ptime=time;
  time=micros();

  digitalWrite(CS[0],HIGH);    //Enables comm for display 0
  display.drawRect(0,0,value/10.667,15,WHITE);  //Draws a bar graph based on Analog Pin 0
  display.display();  
  digitalWrite(CS[0],LOW);    //Disables comm for display 0
  
  display.clearDisplay();   //Since a single buffer is used for all displays it must be cleared in between different display writes
  
  digitalWrite(CS[1],HIGH);  //Enables comm for display 1
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(1/((time-Ptime)*.000001));    //Calculate FPS
  display.display();  
  digitalWrite(CS[1],LOW);  //Disables comm for display 1
  
  display.clearDisplay(); 
  /*  //Uncomment the code below if you have 3 or 4 displays
  digitalWrite(CS[2],HIGH);  //Enables comm for display 2
  display.drawRect(0,0,95,value/64,WHITE);
  display.display();  
  
  digitalWrite(CS[2],LOW);  //Disables comm for display 2
  
  display.clearDisplay(); 
  
  digitalWrite(CS[3],HIGH);  //Enables comm for display 3
  if(value>>2>40){
    display.drawChar(80,0,value>>2,WHITE,BLACK,2);
     display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Sabernetics");
    display.setCursor(0,8);
    display.print("Tech");
    display.display();
  } 
  digitalWrite(CS[3],LOW);  //Disables comm for display 3
  
  display.clearDisplay(); 
  */
  
 delay(100);
  
  //delay(1);  
}

