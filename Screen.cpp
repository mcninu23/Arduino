/**
 * Screen Wrapper definition block
 * Author: Pablo Blanco Celdrán
 */

#include <Screen.h>

Screen::Screen()
: Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET) {
	// TODO add if need some body to the constructor.
	
}

void Screen::init(){
	this->reset();
	this->id = this->readID();
	this->begin(this->id);
}
