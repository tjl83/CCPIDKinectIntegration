#include "Coordinate.h"

Coordinate::Coordinate(){}

Coordinate::Coordinate(float x, float y, float z){
	xVal = x;
	yVal = y;
	zVal = z;
}

Coordinate::~Coordinate(){}

float Coordinate::x(){
	return xVal;
}

float Coordinate::y(){
	return yVal;
}

float Coordinate::z(){
	return zVal;
}