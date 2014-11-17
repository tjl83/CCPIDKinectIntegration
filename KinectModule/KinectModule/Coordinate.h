#ifndef KINECTMODULE_COORDINATE_H
#define KINECTMODULE_COORDINATE_H

class Coordinate{
public:
	Coordinate();
	Coordinate(float x, float y, float z);
	~Coordinate();

	float x();
	float y();
	float z();

private:
	float xVal;
	float yVal;
	float zVal;
};

#endif // !KINECTMODULE_COORDINATE_H