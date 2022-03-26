#include <iostream>

using namespace std;


int main(int argv, char* argc[]) {

	double num1, num2;
	double avg, num3, num4;

	cout << "Enter 2 numbers: " << endl;
	cin >> num1 >> num2;
	//static_cast<double> (num1);
	//static_cast<double> (num2);

	avg = static_cast<double>(num1 + num2) / 2;

	cout << "Average is: " << avg << endl;

	return 0;

}