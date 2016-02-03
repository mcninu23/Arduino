/**
 * Common structs and typedefs.
 * Author: Pablo Blanco Celdrán
 * Argochamber Interactive 2016
 * 24 - 01 - 2016
 */

#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H
 
#include <Arduino.h>

typedef unsigned char byte_t;

struct point {
	long double x,y;
};

struct point3d {
	long double x,y,z;
};

#endif
