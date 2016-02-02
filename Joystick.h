/**
 * Joystick Input handler
 * Author: Pablo Blanco Celdrán
 * Argochamber Interactive 2016
 * 24 - 01 - 2016
 */

#ifndef __JOYSTICK_H
#define __JOYSTICK_H

#include <Common.h>

class Joystick {
public:
	Joystick(byte_t px, byte_t py, byte_t pb); // Pin maps: Pin Axis X, Pin Axis Y, Pin Button.
	
	byte_t getXPin(); // Gets the analog input pin of the X axis.
	byte_t getYPin(); // Gets the analog input pin of the Y axis.
	byte_t getButtonPin(); // Gets the pin of the center pushbutton.
	
	point getAxis(); // Calculates the position of the X/Y axis. Normalized -1,0,1
	void resetBounds(); // Sets the bounds to 0,0 & 0,0 to start callibrating.
	void setAxisBounds(point max, point min); // Sets the axis bounds, manually.
	void callibrate(); // While this is called, it will register the highest and lowest inputs.
	
	point getInput(); // Gets the raw input of the axis.
	point normalize(point raw); // Gets the calculated XY, takes into account the max, and the mins, also normalizes (-1,0,1)
	
private:
	byte_t axisXPin, axisYPin, buttonPin;
	point max, min;
	
};


#endif