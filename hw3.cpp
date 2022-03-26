/***********************************************
Author: Graham Stelzer
Date: 2/5/22
Purpose: Practice using class
Sources of Help: Asked a senior programmer for help with finding the new points in relation to the original (see calculation section)
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 2/5/22
Name: Graham Stelzer
*/
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

//default point init
Point::Point() {
	x = 0;
	y = 0;
} 
//normal point init, requires ints for x and y, will set the x and y values within the class to the given arguments in the call
Point::Point(int initX, int initY) {
	x = initX;
	y = initY;
}

//returns the x value
int Point::getX(void) {
	return x;
}
//returns the y value
int Point::getY(void) {
	return y; 
}

//"moves" the point by the given int values by adding them to the current class x and y values
void Point::movePoint(int distanceX, int distanceY) {
	x += distanceX;
	y += distanceY;
}

//rotates the point 90 degrees around the origin clockwise, see below comments for calculation
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


//driver function included here since the assignment says to only include one file

int main(int argc, char* argv[]) {

	Point origin; //not a function, no need for ()
	cout << "Point origin:" << endl << "x: " << origin.getX() << endl << "y: " << origin.getY() << endl;

	//start at (1,2), rotate 4 times
	Point a(1, 2);
	a.rotateAroundOrigin();
	a.rotateAroundOrigin();
	a.rotateAroundOrigin();
	a.rotateAroundOrigin();
	cout << "Point A:" << endl << "x: " << a.getX() << endl << "y: " << a.getY() << endl;

	//start at (3,4), move right 1 and up 2 (should end at (4,6))
	Point b(3, 4);
	b.movePoint(1, 2);
	cout << "Point B: " << endl << "x: " << b.getX() << endl << "y: " << b.getY() << endl;

	//start at (5,-4), move left 5 and up 4 (should end at (0,0)
	Point c(5, -4);
	c.movePoint(-5, 4);
	cout << "Point C: " << endl << "x: " << c.getX() << endl << "y: " << c.getY() << endl;

	return 0;
}