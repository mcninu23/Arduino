/**
 * Vector, simple maths.
 * Author: Pablo Blanco Celdrán
 * Argochamber interactive 2016
 * 02 - 02 - 2016
 */


#ifndef __VECTOR_H_3D
#define __VECTOR_H_3D

#include <Common.h>

typedef long double real;

class Vector {
public:
	Vector();
	Vector(real, real, real);
	
	real length();
	void setValue(real, real, real);
	real getX();
	real getY();
	real getZ();
	String toString();
	
	//Operators
	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(real);
	
	//Pseudo
	void add(real, real, real);
	
private:
	real x,y,z;
};

#endif
