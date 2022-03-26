//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int getType(char c);
//
//int main(int argc, char* argv[]) {
//
//	string inputStr, tempStr1;
//
//	cout << "Enter line: ";
//	getline(cin, inputStr);
//
//	int currLoc = 0, counter = 0, currType;
//
//	cout << "substring input : type" << endl;
//	
//	// while input is not the "assignment defined EOL character '#' " or the real EOL \0
//	while (inputStr[currLoc] != '#' && inputStr[currLoc] != '\0') {
//
//		//check if need to break apart the string based on the type (tested char by char)
//		if (getType(inputStr[currLoc]) != getType(inputStr[currLoc + 1])) {
//
//			// if:
//			// the current char is type 2 (letter)
//			// AND
//			// the next char is type 1 (number)
//			// AND
//			// the location is 0 OR the previous char is NOT type 2 (not a letter)
//			if (
//				getType(inputStr[currLoc    ]) == 2 &&
//				getType(inputStr[currLoc + 1]) == 1 
//				) { 
//				 
//				cout << "found variable" << endl;
//				// substr():
//				// creates string from the input string based on the position and amnt of chars (pos, num of chars to copy)
//				tempStr1 = inputStr.substr((currLoc) - (counter), (counter + 2)); 
//
//				//reset counter
//				counter = 0;
//
//				//get the current type and print
//				currType = getType(inputStr[currLoc]);
//				cout.width(15);
//				cout << right << tempStr1 << " : " << currType << endl;
//				currLoc++;
//			}
//			// when inputs are different but not variables
//			else { 
//
//				tempStr1 = inputStr.substr(currLoc - counter, (counter + 1));
//
//				counter = 0;
//
//				currType = getType(inputStr[currLoc]);
//				cout.width(15);
//				cout << right << tempStr1 << " : " << currType << endl;
//			}
//		}
//		//increase counter, used for how long the substring will be
//		else {
//			counter++;
//		}
//		currLoc++;
//	}
//
//	return 0;
//}
//
//int getType(char c) {
//
//	int type = 0;
//
//	//numbers 1 to 9
//	if (int(c) >= 48 && int(c) <= 57) {
//		type = 1;
//	}
//	//lettters A to Z and a to z
//	else if ((int(c) >= 65 && int(c) <= 90) ||
//			 (int(c) >= 97 && int(c) <= 122)) {
//		type = 2;
//	}
//	// + - * /
//	else if (int(c) == 42 ||
//			 int(c) == 43 ||
//			 int(c) == 45 ||
//			 int(c) == 47) {
//		type = 3;
//	}
//	// . ( ) , :
//	else if (int(c) == 46 ||
//			 int(c) == 40 ||
//			 int(c) == 41 ||
//			 int(c) == 44 ||
//			 int(c) == 58) {
//		type = 4;
//	}
//	else if (int(c) == 35) {
//		type = 5;
//	}
//	// <space>
//	else if (int(c) == 32) {
//		type = 6;	
//	}
//	
//	return type;
//}