#include <iostream>

using namespace std;

class Mass {
public:

	//convert from input type to drams
	void setMassAvoirdupoisPounds(double a);
	void setMassTroyPounds(double a);
	void setMassMetricGrams(double a);
private:
	double drams;
	
	double convertToAvoir(double b);
	double convertToTroy(double b);
	double convertToGrams(double b);
};


double Mass::convertToTroy(double b) {
	return (b * (1.0 / 96.0));
}
double Mass::convertToGrams(double b) {
	return (b * 1.7718451953125);
}
double Mass::convertToAvoir(double b) {
	return (b * (1.0 / 256.0));
}

void Mass::setMassAvoirdupoisPounds(double a) {
	drams = a * 256.0;
	cout << "converted " << a << " avoirpounds to " << drams << " drams." << endl;
	cout << a << " avoir pounds is " << convertToTroy(drams) << " in troy" << endl;
	cout << a << " avoir pounds is " << convertToGrams(drams) << " in grams" << endl;
}
void Mass::setMassTroyPounds(double a) {
	drams = a * (1.0 / 1.7718451953125);
	cout << "converted " << a << " troypounds to " << drams << " drams." << endl;
	cout << a << " troy pounds is " << convertToAvoir(drams) << " in avoir pounds" << endl;
	cout << a << " troy pounds is " << convertToGrams(drams) << " in grams" << endl;
}
void Mass::setMassMetricGrams(double a) {
	drams = a * 96.0;
	cout << "converted " << a << " metricgrams to " << drams << " drams." << endl;
	cout << a << " grams is " << convertToAvoir(drams) << " in avoir pounds" << endl;
	cout << a << " grams is " << convertToTroy(drams) << " in troy" << endl;
}


int main(int argc, char* argv[]) {

	int massType;
	double input;
	Mass inputMass;
	cout << "enter type of mass, 1 avoir, 2 troy, 3 gram, 0 exit: ";
	cin >> massType;


	switch (massType) {
		case 1:
			cout << "enter mass: ";
			cin >> input;
			cout << "entered " << input << " avoir" << endl;
			inputMass.setMassAvoirdupoisPounds(input);
			break;
		case 2:
			cout << "enter mass: ";
			cin >> input;
			cout << "entered " << input << " troy" << endl;
			inputMass.setMassTroyPounds(input);
			break;
		case 3:
			cout << "enter mass: ";
			cin >> input;
			cout << "entered " << input << " gram" << endl;
			inputMass.setMassMetricGrams(input);
			break;
		default:
			cout << "invalid input" << endl;
	}

}