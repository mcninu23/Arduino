/**
 * Brain's Main Controller
 * Author: Pablo Blanco Celdrán
 */

#include <Controller.h>

Controller::Controller(){
	
}


void Controller::setPos(real x, real y, real z){
	this->position.setValue(x,y,z);
}
