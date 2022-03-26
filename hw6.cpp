///***********************************************
//Author: Graham Stelzer
//Date: 3/14/22
//Purpose: String array that replicates vector behaviour
//Sources of Help: Used class materials, I engaged in a discussion with a senior programmer regarding the most efficient ways to carry out the assigned tasks. At 
//no point did he give me specific code to copy and paste and I did not give him anything. All code below is my own.
//Time Spent: 1 hour max
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
//Date: 3/14/22
//Name: Graham Stelzer
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class DynamicStringArray {
//private:
//	string* _dynamicArray;
//	int _size;
//public:
//	DynamicStringArray() {
//		_dynamicArray = nullptr;
//		_size = 0;
//	};
//	DynamicStringArray(int i_size) {
//		_size = i_size;
//		_dynamicArray = new string[_size];
//	};
//	int get_size() {
//		return _size;
//	};
//	void addEntry(string str);
//	bool deleteEntry(string str);
//	string* getEntry(const int index);
//	DynamicStringArray& operator=(const DynamicStringArray& arr);
//	~DynamicStringArray();
//};
//
//int main(int argc, char* argv[]) {
//
//	DynamicStringArray arr;
//	arr.addEntry("Bob");
//	arr.addEntry("Vance");
//	cout << *(arr.getEntry(0)) << " " << *(arr.getEntry(1)) << endl;
//	arr.deleteEntry("Bob");
//	arr.addEntry("Refridgeration");
//	cout << *(arr.getEntry(0)) << " " << *(arr.getEntry(1)) << endl;
//
//	return 0;
//}
//
//DynamicStringArray::~DynamicStringArray() {
//	delete[] _dynamicArray;
//}
//
//string* DynamicStringArray::getEntry(const int index) {
//
//	if (index < _size && index > -1) {
//		return &_dynamicArray[index];
//	}
//	else {
//		return nullptr;
//	}
//}
//
//void DynamicStringArray::addEntry(string str) {
//
//	_size++;
//	string* temp = new string[_size];
//	for (int i = 0; i < _size - 1; i++) {
//		temp[i] = _dynamicArray[i];
//	}
//	temp[_size - 1] = str;
//	_dynamicArray = temp;
//};
//
//bool DynamicStringArray::deleteEntry(string str) {
//
//	int foundIndex = -1;
//	for (int i = 0; i < _size; i++) {
//		if (_dynamicArray[i] == str) {
//			foundIndex = i;
//		}
//	}
//
//	if (foundIndex == -1) {
//		return false;
//	}
//
//	string* temp = new string[_size - 1];
//
//	for (int i = 0; i < _size; i++) {
//		if (i < foundIndex) {
//			temp[i] = _dynamicArray[i];
//		}
//		else if (i == foundIndex) {
//			continue;
//		}
//		else { 
//			temp[i - 1] = _dynamicArray[i];
//		}
//	}
//
//	_size--;
//	delete[] _dynamicArray;
//	_dynamicArray = temp;
//
//	return true;
//}
//
//
//DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& arr) {
//	if (this == &arr) return *this;
//	_size = arr._size;
//	for (int i = 0; i < _size; i++) {
//		_dynamicArray[i] = arr._dynamicArray[i];
//	}
//
//	return *this;
//}
//
//
