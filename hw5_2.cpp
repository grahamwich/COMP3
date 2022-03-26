//c/***********************************************
//Author: Graham Stelzer
//Date: 2/22/2022
//Purpose: Practice overloading operational functions with classes
//Sources of Help: Used class notes as well as Euclidean algorithm (practiced in previous COMP classes).
//Time Spent: 1-3 hours
//***********************************************/
///*
//Computing III -- COMP.2010 Honor Statement
//The practice of good ethical behavior is essential for maintaining
//good order in the classroom, providing an enriching learning
//experience for students, and as training as a practicing computing
//professional upon graduation. This practice is manifested in the
//University’s Academic Integrity policy. Students are expected to
//strictly avoid academic dishonesty and adhere to the Academic
//Integrity policy as outlined in the course catalog. Violations will
//be dealt with as outlined therein.
//All programming assignments in this class are to be done by the
//student alone. No outside help is permitted except the instructor and
//approved tutors.
//I certify that the work submitted with this assignment is mine and was
//generated in a manner consistent with this document, the course
//academic policy on the course website on Blackboard, and the UMass
//Lowell academic code.
//Date: 2/22/2022
//Name: Graham Stelzer
//*/
//#include <iostream>
//using namespace std;
//
//class Rational {
//public:
//	Rational() : numerator(0), denom(1) {}
//	Rational(int wholeNumber) : numerator(wholeNumber), denom(1) {}
//	Rational(int iNumerator, int iDenom);
//
//	//copy
//	Rational(const Rational& rat1) { numerator = rat1.numerator; denom = rat1.denom; }
//
//	void normalize();
//
//	int getNumerator() const {
//		return numerator;
//	}
//	int getDenom() const {
//		return denom;
//	}
//
//private:
//	int numerator;
//	int denom;
//};
//
//
//int euclidean(int a, int b); //had this saved from a previous class
//bool operator==(const Rational& leftOp, const Rational& rightOp); //
//bool operator<=(const Rational& leftOp, const Rational& rightOp); //
//bool operator>=(const Rational& leftOp, const Rational& rightOp); //
//bool operator>(const Rational& leftOp, const Rational& rightOp); //
//bool operator<(const Rational& leftOp, const Rational& rightOp); //
//
//const Rational operator+(const Rational& leftOp, const Rational& rightOp); // 
//const Rational operator-(const Rational& leftOp, const Rational& rightOp); // 
//ostream& operator<<(ostream& outStream, const Rational& m); // 
//istream& operator>>(istream& inStream, Rational& m); //
//
////not needed for assignment
////const Rational& operator++(Rational& op);
////const Rational operator++(Rational& op, int);
////const Rational operator-(const Rational& op);
//
//int main(int argc, char* argv[]) {
//
//	Rational a;
//	cout << a << endl;
//	Rational b(1, 2);
//	Rational c(3, 2);
//	Rational d(3, 5);
//	Rational e(6, 10);
//	Rational f(-3, 5);
//	Rational g(3, -6);
//	Rational h;
//
//	cout << b << " + " << c << " = " << b + c << endl;
//	cout << b << " + " << d << " = " << b + d << endl;
//	cout << b << " - " << c << " = " << b - c << endl;
//	cout << b << " - " << d << " = " << b - d << endl << endl;
//
//	if (d == e) {
//		cout << d << " == " << e << endl;
//	}
//	else {
//		cout << d << " != " << e << endl;
//	}
//	if (c == e) {
//		cout << c << " == " << e << endl;
//	}
//	else {
//		cout << c << " != " << e << endl;
//	}
//
//	if (f < g) {
//		cout << f << " < " << g << endl;
//	}
//	else {
//		cout << f << " !< " << g << endl;
//	}
//	if (f > g) {
//		cout << f << " > " << g << endl;
//	}
//	else {
//		cout << f << " !> " << g << endl;
//	}
//
//	if (d <= e) {
//		cout << d << " <= " << e << endl;
//	}
//	else {
//		cout << d << " !<= " << e << endl;
//	}
//	if (d >= e) {
//		cout << d << " >= " << e << endl;
//	}
//	else {
//		cout << d << " !>= " << e << endl;
//	}
//	if (b >= e) {
//		cout << b << " >= " << e << endl;
//	}
//	else {
//		cout << b << " !>= " << e << endl;
//	}
//
//	cout << "enter fraction (format: num/num): ";
//	cin >> h;
//
//	cout << endl << "user entered: " << h;
//
//	cout << endl << "normalize " << h << ": ";
//	h.normalize();
//	cout << h << endl;
//
//	return 0;
//}
//
////constructor
//Rational::Rational(int iNumerator, int iDenom) {
//	numerator = iNumerator;
//	denom = iDenom;
//	if (denom == 0) {
//		cout << "denominator is 0, you have summoned a demon who will now hunt you for eternity." << endl;
//		exit(-1);
//	}
//}
//
////euclidean
//int euclidean(int a, int b) {
//	if (a == 0)
//		return b;
//	return euclidean(b % a, a);
//}
//
////operates on current Rational value, DOES NOT MAKE OR RETURN A COPY
////there are probably more efficient ways to do this but heck if i care:
////changes a negative to a positive by adding the value twice (ex. -5 + (5 * 2) = 5) and a positive to a negative by the same method
////if both num and den are negative, changes both
//void Rational::normalize() { //unfinished, must test if both num and denom are negative
//
//	if (denom == 0) {
//		cout << "denom is 0, you have summoned a demon who will now hunt you for eternity (or your death)." << endl;
//		exit(-1);
//	}
//
//	int divisor = euclidean(numerator, denom);
//	numerator /= divisor;
//	denom /= divisor;
//
//	if (denom < 0 && numerator > 0) {
//		numerator = numerator - (numerator * 2);
//		denom = denom + (denom * -2);
//	}
//	else if (denom < 0 && numerator < 0) {
//		numerator = numerator + (numerator * -2);
//		denom = denom + (denom * -2);
//	}
//}
//
////bool functions
////all bool functions use some version of provided "hint" which uses a*d and c*b provided a/b and c/d (which are input as classes with numerator and denominator
////since all bool functions use the same general formula, it is really easy to manipulate, for example; a > d is the same as testing if d < a
//bool operator==(const Rational& leftOp, const Rational& rightOp) {
//
//	int ad = leftOp.getNumerator() * rightOp.getDenom();
//	int cb = rightOp.getNumerator() * leftOp.getDenom();
//	if (ad == cb) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//bool operator<=(const Rational& leftOp, const Rational& rightOp) {
//
//	Rational copyLeft = leftOp;
//	Rational copyRight = rightOp;
//
//	if (copyLeft.getDenom() < 0) {
//		//cout << "copy left before norm " << copyLeft << endl;
//		copyLeft.normalize();
//		//cout << "copy left after norm " << copyLeft << endl;
//	}
//	if (copyRight.getDenom() < 0) {
//		//cout << "copy right before norm " << copyRight << endl;
//		copyRight.normalize();
//		//cout << "copy right after norm " << copyRight << endl;
//	}
//
//	int ad = copyLeft.getNumerator() * copyRight.getDenom();
//	int cb = copyRight.getNumerator() * copyLeft.getDenom();
//	if ((ad < cb) || (ad == cb)) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//bool operator>=(const Rational& leftOp, const Rational& rightOp) {
//
//	Rational copyLeft = rightOp;
//	Rational copyRight = leftOp;
//
//	if (copyLeft.getDenom() < 0) {
//		//cout << "copy left before norm " << copyLeft << endl;
//		copyLeft.normalize();
//		//cout << "copy left after norm " << copyLeft << endl;
//	}
//	if (copyRight.getDenom() < 0) {
//		//cout << "copy right before norm " << copyRight << endl;
//		copyRight.normalize();
//		//cout << "copy right after norm " << copyRight << endl;
//	}
//
//	int ad = copyLeft.getNumerator() * copyRight.getDenom();
//	int cb = copyRight.getNumerator() * copyLeft.getDenom();
//	if (ad < cb || (ad == cb)) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//bool operator<(const Rational& leftOp, const Rational& rightOp) {
//
//	Rational copyLeft = leftOp;
//	Rational copyRight = rightOp;
//
//	if (copyLeft.getDenom() < 0) {
//		//cout << "copy left before norm " << copyLeft << endl;
//		copyLeft.normalize();
//		//cout << "copy left after norm " << copyLeft << endl;
//	}
//	if (copyRight.getDenom() < 0) {
//		//cout << "copy right before norm " << copyRight << endl;
//		copyRight.normalize();
//		//cout << "copy right after norm " << copyRight << endl;
//	}
//
//	int ad = copyLeft.getNumerator() * copyRight.getDenom();
//	int cb = copyRight.getNumerator() * copyLeft.getDenom();
//	if (ad < cb) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//bool operator>(const Rational& leftOp, const Rational& rightOp) {
//
//	Rational copyLeft = rightOp;
//	Rational copyRight = leftOp;
//
//	if (copyLeft.getDenom() < 0) {
//		//cout << "copy left before norm " << copyLeft << endl;
//		copyLeft.normalize();
//		//cout << "copy left after norm " << copyLeft << endl;
//	}
//	if (copyRight.getDenom() < 0) {
//		//cout << "copy right before norm " << copyRight << endl;
//		copyRight.normalize();
//		//cout << "copy right after norm " << copyRight << endl;
//	}
//
//	int ad = copyLeft.getNumerator() * copyRight.getDenom();
//	int cb = copyRight.getNumerator() * copyLeft.getDenom();
//	if (ad < cb) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////NOTE: > and < creates copy and normalizes the COPY (instead of the original since the assignment said there can be inputs and outputs like 3/-2 or something)
//
////+ and -
////checks if denominators are the same (which makes the addition very simple, else does multiplication to get common denominator
////returns a Rational type
//const Rational operator+(const Rational& leftOp, const Rational& rightOp) {
//
//	int numeratorSum, denomSum;
//	if (leftOp.getDenom() == rightOp.getDenom()) {
//		numeratorSum = leftOp.getNumerator() + rightOp.getNumerator();
//		Rational sum(numeratorSum, leftOp.getDenom());
//		return sum;
//	}
//
//	numeratorSum = (leftOp.getNumerator() * rightOp.getDenom()) + (rightOp.getNumerator() * leftOp.getDenom());
//	denomSum = leftOp.getDenom() * rightOp.getDenom();
//
//	Rational sum(numeratorSum, denomSum);
//
//	return sum;
//}
//const Rational operator-(const Rational& leftOp, const Rational& rightOp) {
//
//	int numeratorDiff, denomDiff;
//	if (leftOp.getDenom() == rightOp.getDenom()) {
//		numeratorDiff = leftOp.getNumerator() - rightOp.getNumerator();
//		Rational diff(numeratorDiff, leftOp.getDenom());
//		return diff;
//	}
//
//	numeratorDiff = (leftOp.getNumerator() * rightOp.getDenom()) - (rightOp.getNumerator() * leftOp.getDenom());
//	denomDiff = leftOp.getDenom() * rightOp.getDenom();
//
//	Rational sum(numeratorDiff, denomDiff);
//
//	return sum;
//}
//
////cout and cin
//ostream& operator<<(ostream& outStream, const Rational& m)
//{
//	outStream << m.getNumerator() << "/" << m.getDenom();
//	return outStream;
//}
//istream& operator>>(istream& inStream, Rational& m) {
//
//	int iNum;
//	inStream >> iNum;
//
//	char c;
//	inStream >> c;
//	if (c != '/')
//	{
//		cout << "Wrong format";
//		exit(1);
//	}
//
//	int iDen;
//	inStream >> iDen;
//
//	m = Rational(iNum, iDen);
//
//	return inStream;
//}