/**
 * Joystick definition block.
 * Author: Pablo Blanco Celdr�n
 */

#define __PINSET(x) pinMode(this->axisXPin, x); pinMode(this->axisYPin, x); pinMode(this->buttonPin, x); 
#define MAX_ANALOG 1024.0

#include <Joystick.h>

Joystick::Joystick(byte_t px, byte_t py, byte_t pb){
	this->axisXPin = px;
	this->axisYPin = py;
	this->buttonPin = pb;
	__PINSET(INPUT);
	point max;
	max.x = 1;
	max.y = 1;
	point min;
	min.x = 0;
	min.y = 0;
	this->max = max;
	this->min = min;
}

byte_t Joystick::getXPin(){
	return this->axisXPin;
}

byte_t Joystick::getYPin(){
	return this->axisYPin;
}

byte_t Joystick::getButtonPin(){
	return this->buttonPin;
}

void Joystick::resetBounds(){
	this->max.x = 0;
	this->max.y = 0;
	this->min.x = 0;
	this->min.y = 0;
}

void Joystick::setAxisBounds(point max, point min){
	this->max = max;
	this->min = min;
}

point Joystick::getInput(){
	point p;
	p.x = analogRead(this->axisXPin);
	p.y = analogRead(this->axisYPin);
	return p;
}

point Joystick::normalize(point raw){
	point p;
	p.x =  (((raw.x/MAX_ANALOG)*2.0) - 0.5);
	p.y = (((raw.y/MAX_ANALOG)*2.0) - 0.5);
	return p;
}

point Joystick::getAxis(){
	point p = this->normalize(this->getInput());
	return p;
}

void Joystick::callibrate(){
	point p = this->getInput();
	if (p.x > this->max.x){
		this->max.x = p.x;
	} else if (p.x < this->min.x){
		this->min.x = p.x;
	}
	if (p.y > this->max.y){
		this->max.y = p.y;
	} else if (p.y < this->min.y){
		this->min.y = p.y;
	}
}
