#include <iostream>
#include <utility> 
#include <map>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string currStr;
//?? map of <string, array> where array is all the ratings, use "new"? array size = number of reviews, can average the array (how to incremement?)
	int n, currRat, temp = 0;
	map<string, int> m;
	map<string, pair<int, int>> m1;

	ifstream myfile("ratings.txt");
	if (!(myfile.is_open())) {
		cout << "Unable to open file." << endl;
	}
	myfile >> n;
	cout << n << endl;

	//while (getline(myfile, currStr)) {
	//	cout << "new line" << currStr << endl;
	//	m[currStr] = m[currStr] + 1;
	//}

	getline(myfile, currStr);
	while (getline(myfile, currStr) && currStr != "/n") {
		cout << "currstr: " << currStr;
		myfile >> currRat;
		cout << " currrat: " << currRat << endl;

		//?? make_pair(numInstances, myfile >> currRat (the next line)

		m[currStr] = make_pair(temp++, currRat);//can use += to get the sum of the ratings
		getline(myfile, currStr);
	}

	cout << "words || amount" << endl;
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	myfile.close();
	return 0;
}