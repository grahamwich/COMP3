#pragma once
#include <iostream>

using namespace std;

class Point
{
public:
	//init functions
	Point();
	Point(int initX, int initY);
	//accessor functions:
	int getX(void);
	int getY(void);
	//move point
	void movePoint(int distanceX, int distanceY);
	//rotate
	void rotateAroundOrigin();

private:
	int x, y;
	const int SIN_90_DEGREES = 1;
	const int COS_90_DEGREES = 0;
};

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(int initX, int initY) {
	x = initX;
	y = initY;
}

int Point::getX(void) {
	return x;
}
int Point::getY(void) {
	return y;
}

void Point::movePoint(int distanceX, int distanceY) {
	x += distanceX;
	y += distanceY;
}

void Point::rotateAroundOrigin() {
	/* Calculation:
	 * Using sin and cos however since rotation by 90 degrees, sin and cos of 90 degrees are whole numbers thus
	 * doulbe is not needed.
	 * Using origin to rotate so the rotation point is (0,0) and not needed in calculations
	 * newPointX = (originalPointX * cos(90)) + (originalPointY * sin(90))
	 * newPointY = (originalPointY * cos(90)) + (originalPointX * sin(90))
	 * Since locating the new points in relation to the old points, and moving through the function changes the
	 * values of the original points, temporary points are needed as a psuedo-swap
	 */
	int origX = x;
	int origY = y;
	x = (origX * COS_90_DEGREES) + (origY * SIN_90_DEGREES);
	y = (origY * COS_90_DEGREES) - (origX * SIN_90_DEGREES);
}



