/**
 * Engine definition block.
 * Author: Pablo Blanco Celdr�n
 */

#include "Engine.h"

Engine::Engine(byte_t map[]){
	this->phase = 0;
	this->driveMode = DEFAULT_DRIVE_MODE;
	this->angle = 0;
	this->phaseCount = DEFAULT_PHASE_COUNT;
	this->pinMapping = map;
	this->setPinMode(OUTPUT);
}

Engine::Engine(byte_t map[], DriveMode mode){
	this->phase = 0;
	this->driveMode = mode;
	this->angle = 0;
	this->phaseCount = DEFAULT_PHASE_COUNT;
	this->pinMapping = map;
	this->setPinMode(OUTPUT);
}

Engine::Engine(byte_t map[], DriveMode mode, byte_t count){
	this->phase = 0;
	this->driveMode = mode;
	this->angle = 0;
	this->phaseCount = count;
	this->pinMapping = map;
	this->setPinMode(OUTPUT);
}

short Engine::getPhase(){
	return this->phase;
}

void Engine::stepUp(){
	this->phase++;
	this->angle++;
	if (this->phase >= this->phaseCount){
		this->phase = 0;
	}
	this->setCoilOutput();
}

void Engine::stepDown(){
	this->phase--;
	this->angle--;
	if (this->phase < 0){
		this->phase = this->phaseCount - 1;
	}
	this->setCoilOutput();
}

void Engine::resetAngle(){
	this->angle = 0;
}

long int Engine::getAngle(){
	return this->angle;
}

void Engine::gotoAngle(long int target){
	this->gotoMode = true;
	this->targetAngle = target;
}

void Engine::setCoilMapping(byte_t map[]){
	this->pinMapping = map;
}

void Engine::setCoilOutput(){
	for (int i = 0; i < this->phaseCount; i++){
		if (this->phase == i){
			digitalWrite(this->pinMapping[i], HIGH);
		} else {
			digitalWrite(this->pinMapping[i], LOW);
		}
	}
}

void Engine::setPinMode(int mode){
	for (int i = 0; i < this->phaseCount; i++){
		pinMode(this->pinMapping[i], mode);
	}
}

void Engine::setThrole(long double throle){
	this->throle = throle;
	this->interval = this->calcInterval();
	this->gotoMode = false;
}

long double Engine::getThrole(){
	return this->throle;
}

void Engine::loop(){
	unsigned long currentTime = millis();
	if ((currentTime  - this->lastTime) >= this->interval && abs(this->throle) > 0.0) {
		this->tick();
	}
}

void Engine::tick(){
	this->lastTime = millis();
	
	// There, branch if there's the setAngle or the throle first.
	if (this->gotoMode == true){
		if (this->angle > this->targetAngle){
			this->stepDown();
		} else if (this->angle < this->targetAngle){
			this->stepUp();
		}
	} else {
		if (this->throle > 0){
			this->stepUp();
		} else if (this->throle < 0){
			this->stepDown();
		}
	}
}

unsigned long Engine::calcInterval(){
	if (abs(this->throle) > 0.0){
		return (1.0 - abs(this->throle)) * MAX_DELAY;
	} else {
		return 0;
	}
}
