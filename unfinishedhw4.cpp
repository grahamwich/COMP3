#include <iostream>
#include <string>

using namespace std;

class ZipCode { //asftsrn lt g

public:
	ZipCode();
	ZipCode(int input);
	ZipCode(string input);

	

private:

	//store as int or string, must either convert from string to int or vice versa
	int zipCode;

};

ZipCode::ZipCode(int input){
	zipCode = input;
}
ZipCode::ZipCode(string input) {
	//convert from string to int, will receive binary number, convert to zipcode using assignment sheet
	//read numbers in groups of 4?
	//use bool?
	//use array

	int sizeOfInput = 80;//find size of array;
	int i = 0;
	
	while (input[i] != nullptr /*end of line*/ && i < sizeOfInput /*one of these might be uneccessary*/) {

	}

}


