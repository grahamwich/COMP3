#include <iostream>

using namespace std;

char tab[80][80];

int main() {

	char inBuf[80];
	char outBuf[80];
	int found = 0;
	char key;
	int i = 0;
	int j = 0;

	cout << "Enter a new line:";
	cin.getline(inBuf, 80);

	while (i < 80) {
		key = inBuf[i];
		while ((found == 0) && (tab[j][0] != '\\')) {
			if (tab[j][0] == key) {
				found = 1;
			}
			j++;
		}
		outBuf[i] = tab[j][0];

		i++;
	}


	
	return 0;

}