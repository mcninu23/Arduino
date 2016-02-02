/**
 * Definition block for the vector
 * Do logic
 */

#include <Vector.h>

Vector::Vector(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(real x, real y, real z){
	this->x = x;
	this->y = y;
	this->z = z;
}

real Vector::length(){
	return sqrt( pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) );
}

Vector Vector::operator+(Vector v){
	Vector vec(v.getX(),v.getY(), v.getZ());
	vec.add(this->x, this->y, this->z);
	return vec;
}

Vector Vector::operator-(Vector v){
	Vector vec(-v.getX(),-v.getY(), -v.getZ());
	vec.add(this->x, this->y, this->z);
	return vec;
}

Vector Vector::operator*(real r){
	Vector vec(this->x * r, this->y * r, this->z * r);
	return vec;
}

void Vector::add(real dx, real dy, real dz){
	this->x += dx;
	this->y += dy;
	this->z += dz;
}

void Vector::setValue(real x, real y, real z){
	this->x = x;
	this->y = y;
	this->z = z;
}

real Vector::getX(){
	return this->x;
}

real Vector::getY(){
	return this->y;
}

real Vector::getZ(){
	return this->z;
}

String Vector::toString(){
	String a;
	String X((float)this->x);
	String Y((float)this->y);
	String Z((float)this->z);
	String sep(" , ");
	return a + X + sep + Y + sep + Z;
}



