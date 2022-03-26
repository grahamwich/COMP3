/***********************************************
Author: Graham Stelzer
Date: 1/31/22
COMP.2010 HW 02 Sp22 - Dr. Lin
Purpose: Read a string from a file and replace certain words.
Sources of Help: Required the use of the textbook, lecture notes, stackoverflow and various official C++ syntax to understand how to use string and file opening in
an EFFICIENT manner. Ex: https://www.cplusplus.com/reference/string/string/npos/ used for figuring out what npos does.
Time Spent: 1 hour
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
Date: 1/31/22
Name: Graham Stelzer
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUM_CHARS_IN_REPLACED_WORD = 7;

int main(int argc, char* argv[]) {

	ifstream inStream;

	//attempt to open file and check if opened 
	inStream.open("C:/Users/Bellagio/source/repos/COMP3/COMP3/input.txt.txt"); //for some reason, the extra .txt is required for it to open without failure
	if (inStream.fail()) {
		cout << "failed";
		exit(1);
	}

	//read file into a string
	string line;
	while (getline(inStream, line)) {
		cout << "input from the file was: " << line << endl; //check the original input
	}
	
	//locate item to replace and execute 
	while (line.find("dislike") != (string::npos) /*locates end of string*/) {
		line.replace(line.find("dislike"), NUM_CHARS_IN_REPLACED_WORD, "love"); /*from my understanding (and using cppreference.com for the offical definition,
													    * .replace(<item to be replaced>, <num of characters to replace>, <what to replace with>")
													    */
	}
	cout << "replaced 'dislike' with 'love': " << line << endl;

	inStream.close();

	return 0;
}