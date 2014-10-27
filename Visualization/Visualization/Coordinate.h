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