/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 1/27/2022
Name: Graham Stelzer (with groupmates)
*/

//Group No. 12
//Group Names: Joseph Beausoleil, Aaron Soibelman, Graham Stelzer

#include <iostream>

using namespace std;

const int FALSE = 0;
const int TRUE = 1;

const double MONTHS_IN_A_YEAR = 12.0;

int main(int argc, char* argv[]) {

    double amountNeeded, interestRate, durationInMonths;
    double faceValue, monthlyPayment;
    int checkQuitting = FALSE;

    while (checkQuitting == FALSE) {
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
        cin >> interestRate;
        if (interestRate == FALSE) { //check if user wants to exit
            checkQuitting = TRUE;
            exit(0);
        }
        interestRate /= 100.0; //convert input from percentage to decimal

        cout << "Please enter the amount you would like to receive: ";
        cin >> amountNeeded;

        cout << "Please enter loan period in months: ";
        cin >> durationInMonths;
        durationInMonths /= MONTHS_IN_A_YEAR; //convert to months

        faceValue = amountNeeded / (1.0 - (interestRate * durationInMonths)); //calculation

        monthlyPayment = faceValue / MONTHS_IN_A_YEAR; //calculate monthly payment

        double roundedPayment = (round(monthlyPayment * 100)) / 100; //rounding used for output

        cout << "The total amount of your loan (including interest at " << static_cast<int>(interestRate * 100) << "% per annum) is " << faceValue << endl;
        cout << "Your monthly payment for " << durationInMonths * MONTHS_IN_A_YEAR << " months is " << roundedPayment << endl;
    }

    return 0;
}

