/***********************************************
Author: Graham Stelzer
Date: 1/30/22
Purpose: Write a C++ program that has the user guess a randomly generated number between a given range with an input number of guesses;
Sources of Help: Used Piazza for general question about input validation.
Time Spent: 1 hour max though I did not time myself
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
Date: 1/30/22
Name: Graham Stelzer
*/

#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

	//inputs:
	int inputMin, inputMax, numGuesses;
	int num, guess;

	char playingCheck = 'y';

	do {
		//take and check inputs:
		do {
			cout << "Enter a min number (must be a positive integer): ";
			cin >> inputMin;
		} while (inputMin <= 0);

		do {
			cout << "Enter a max number (must begreater than min and less than 1000): ";
			cin >> inputMax;
		} while (inputMax <= inputMin || inputMax >= 1000);

		do {
			cout << "Enter the number guesses (must be less than 10): ";
			cin >> numGuesses;
		} while (numGuesses <= 0 || numGuesses >= 10);

		//generate a random number withing given range
		srand(static_cast<unsigned>(time(NULL)));
		num = rand() % inputMax + inputMin; 

//cout << num << endl; //check what the actual random number was set as

		//initiate guesssing
		cout << "Guess the number between " << inputMin << " and " << inputMax << ", type your first guess: ";
		cin >> guess;

		while (1) {
			numGuesses--;
			if (numGuesses == 0) {
				break;
			}
			if (guess == num) {
				cout << "Correct." << endl;
				break;
			}
			else if (guess > num) {
				cout << "Too high. Guess again: ";
				cin >> guess;
			}
			else if (guess < num) {
				cout << "Too low. Guess again: ";
				cin >> guess;
			}
		}  

		//play again prompt
		if (numGuesses == 0) {
			cout << "No more guesses. The number was " << num << ". Play again? (y or n): ";
		}
		else {
			cout << "Play again? (y or n): ";
		}
		cin >> playingCheck;


	} while (playingCheck == 'y');

	return 0;
	
}