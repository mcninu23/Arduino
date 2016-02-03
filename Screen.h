/**
 * Screen Wrapper for the TFT Screen.
 * Author: Pablo Blanco Celdrán
 * Argochamber Interactive 2016
 * 28 - 01 - 2016
 * Thanks to the Adafruit team for providing TFT Screen Controllers.
 */


#ifndef __SCREEN_H
#define __SCREEN_H

#include "gfx/Adafruit_GFX.h"    // Core graphics library
#include "tft/Adafruit_TFTLCD.h" // Hardware-specific library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

class Screen: public Adafruit_TFTLCD {
public:
	Screen();
	
	void init(); // Initializes the screen.
	
private:
	uint16_t id;
};

#endif
