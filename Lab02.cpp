//#include <iostream>
//#include <cstdlib> 
//#include <ctime>
//
//using namespace std;
//
//void takeInput(int &pounds, double &ounces);
//void convertInput(int pounds, double ounces, int& kilograms, double& grams);
//void displayConversion(int pounds, double ounces, int kilograms, double grams);
//	
//int main(int argc, char* argv[]) {
//
//	int pounds, kilograms;
//	double ounces, grams;
//
//	cout.setf(ios::fixed);
//	cout.setf(ios::showpoint);
//	cout.precision(8);
//
//	takeInput(pounds, ounces);
//	convertInput(pounds, ounces, kilograms, grams);
//	displayConversion(pounds, ounces, kilograms, grams);
//
//	return 0;
//}
//
//void takeInput(int& pounds, double& ounces) {
//	
//	while ((cout << "enter pounds: ") && (!(cin >> pounds) || (pounds < 1) /*|| (pounds > 200)*/)) {
//		std::cout << "invalid input, cannot have a negative amount of pounds ";
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
//
//	while ((cout << "enter ounces: ") && (!(cin >> ounces) || (ounces < 1) || (ounces > 16))) {
//		std::cout << "invalid input, can be between 1 and 16 ";
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	}
//	return;
//}
//
//void convertInput(int pounds, double ounces, int& kilograms, double& grams) {
//	double combinedPounds, combinedKilograms;
//
//	combinedPounds = (pounds + (ounces / 16));
//	combinedKilograms = (combinedPounds * 0.45359237);
//
//	kilograms = static_cast<int>(floor(combinedKilograms));
//	grams = static_cast<double>((combinedKilograms - kilograms) * 1000);
//	return;
//}
//
//void displayConversion(int pounds, double ounces, int kilograms, double grams) {
//	
//	cout << pounds << " pounds and " << ounces << " ounces " << "converts to "
//		<< kilograms << " kilograms and " << grams << " grams" << endl;
//	return;
//}