This is a our graphics core library, for all our displays. We'll be adapting all the
existing libaries to use this core to make updating, support and upgrading easier!

At this time, only the SSD1306 library uses it - but we'll be adding more!
    https://github.com/adafruit/Adafruit_SSD1306

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above must be included in any redistribution

To download. click the DOWNLOADS button in the top right corner, rename the uncompressed folder Adafruit_GFX. Check that the Adafruit_GFX folder contains Adafruit_GFX.cpp and Adafruit_GFX.h

Place the Adafruit_GFX library folder your <arduinosketchfolder>/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE.



Modified June 10, 2012 by Sabernetics,  Added support for Mini I2C OLED 96x16 display. See Below for additional instructions.

To install for Arduino:
Copy the "OLED_I2C" folder to your Arduino Library folder "arduino-1.0.1/libraries/".  Restart the Arduino IDE. Navigate to File>>Examples>>OLED_I2C for the single and multi OLED sample code.

Check the "Adafruit_GFX.h" and "Adafruit_SSD1306.h" header files for a complete list of display functions.