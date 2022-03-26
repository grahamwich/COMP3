//
//  Lecture06, C++ Class
//

#include <iostream>
using namespace std;

void calAvg(double* arr);

int main(int argc, char* argv[]) {

    double arr[3];
    arr[0] = 5;
    arr[1] = 5;
    arr[2] = 7;

    calAvg(arr);
    

    return 0;
}

void calAvg(double* arr) {
    int sizeOfArray = sizeof(double);
    double sum = 0.0, average = 0.0;
    for (int i = 0; i < sizeOfArray; i++) {
        sum += arr[i];
    }
    average = sum / static_cast<double>(sizeOfArray);
    cout << average;
}
