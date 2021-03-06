/**
 * This is the brain of the arm control, for now.
 * Author: Pablo Blanco Celdrán
 * Argochamber Interactive 2016
 * 28 - 01 - 2016
 */
 
#ifndef __BRAIN_ARM_H
#define __BRAIN_ARM_H

#include <Common.h>
#include <Vector.h>

class Controller{
public:
	Controller();

	void setPos(real, real, real);
	
private:
	Vector position;
};

#endif
