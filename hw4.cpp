///***********************************************
//Author: Graham Stelzer
//Date: 2/10/22
//Purpose: Give me a headache. Also use classes for a lot of different things.
//Sources of Help: Used a lot of stack overflow and CPP syntax website. I didnt know substr() was a valid function in string until like 3 hours in
//Time Spent: 5 hours or so
//***********************************************/
//
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
//Date: 2/10/22
//Name: Graham Stelzer
//*/
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class ZipCode {
//public:
//    ZipCode(int zipCodeIn);
//    ZipCode(string barCodeIn);
//
//    int getZipCode();
//    string getBarCode();
//
//private:
//    int convertToZipCode(string barCodeIn);
//    string convertToBarCode(int zipCodeIn);
//
//    void reverseStr(string& str);
//    int zipCode;
//};
//
////included in here because ease of reading
//int main(int argc, char * argv[]) {
//    ZipCode zip(99504), zip2("100101010011100001100110001"), zip3(12345), zip4(67890); 
//    
//    cout << zip.getZipCode() << "'s bar code is '"
//    << zip.getBarCode() << "'" << endl;
//    cout << zip2.getZipCode() << "'s bar code is '"
//    << zip2.getBarCode() << "'" << endl; 
//    cout << zip3.getZipCode() << "'s bar code is '"
//    << zip3.getBarCode() << "'" << endl;
//    cout << zip4.getZipCode() << "'s bar code is '"
//    << zip4.getBarCode() << "'" << endl;
//    
//    cout << endl;
//    
//    // Test a range of values by first constructing a zip code
//    // with an integer, then retrieving the bar code and using
//    // that to construct another ZipCode.
//    int zip_int = 0;
//    for (int i = 0; i < 25; i++)
//    {
//        // Make an aribrary 5-digit zip code integer, and use it
//        // to construct a ZipCode
//        int five_digit_zip = (zip_int * zip_int) % 100000;
//        ZipCode z1(five_digit_zip);
//        
//        // Construct a second ZipCode from the first's bar code
//        string z1_barcode = z1.getBarCode();
//        ZipCode z2(z1_barcode);
//        
//        cout.width(3);
//        cout << (i + 1) << ": ";
//        cout.width(5);
//        cout << z2.getZipCode() << " has code '"
//        << z1_barcode << "'";
//        
//        if ((z1_barcode == z2.getBarCode()) &&
//            (z1.getZipCode() == z2.getZipCode()) &&
//            (z2.getZipCode() == five_digit_zip))
//        {
//            cout << " [OK]" << endl;
//        }
//        else
//        {
//            cout << " [ERR]" << endl;
//        }
//        
//        // Increment the test value arbitrarily
//        zip_int += (233 + zip_int % 7);
//    }
//    cout << endl;
//    
//    // Test some error conditions. This test assumes that
//    // ZipCode will simply set its value to a flag that indicates
//    // an error, and will not exit the program.
//    int BAD_ZIP_COUNT = 2;
//    string bad_zips[][2] = {
//        { "100101010011100001100110000", "bad start/end character" },
//        { "100101010011100001100110021", "bad digit" },
//    };
//    for (int i = 0; i < BAD_ZIP_COUNT; i++)
//    {
//        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
//        ZipCode test(bad_zips[i][0]);
//        cout << endl;
//    }
//    
//    cout << "Enter a character to quit." << endl;
//    char c;
//    cin >> c;
//    return 0;
//}
//
////if user creates a zip with a zip
//ZipCode::ZipCode(int zipCodeIn) {
//    zipCode = zipCodeIn;
//}
//
////if user creates a zip with a barcode string
////check if first and last values are correct, check if all values inside are correct, break if not
////
////addition note: for some reason temp was needed for the .length()
//ZipCode::ZipCode(string barCodeIn) {
//
//    int temp = barCodeIn.length();
//
//    if (barCodeIn[0] == '1' && barCodeIn[temp - 1] == '1') {
//        for (int i = 0; i < temp; i++) {
//            if (barCodeIn[i] != '1' && barCodeIn[i] != '0') {
//                cout << "Barcodes can only be '1's or '0's." << endl;
//                break;
//            }
//        }
//
//        zipCode = convertToZipCode(barCodeIn);
//    }
//    else {
//        cout << "Wrong start or end character." << endl;
//    } 
//}
//
////reverses the string, needed for generating a barcode since multiple strings needed to be flipped
//void ZipCode::reverseStr(string& str) {
//    int n = str.length();
//
//    for (int i = 0; i < n / 2; i++)
//        swap(str[i], str[n - i - 1]);
//}
//
////converts a zipcode to a barcode
////
////additional notes: honestly, when making these next two functions I could barely breathe due to a sinus thing. 
////I'm not entirely sure the logic for it but it seems to work. I think it works similiar to if you were converting binary numbers to decimal.
//string ZipCode::convertToBarCode(int zipCodeIn) {
//
//    int tempZip = zipCodeIn;
//    int newNum, digit, temp;
//
//    string tempBar = ("1");
//    string tempStr;
//
//    for (int k = 0; k < 5; k++) {
//
//        tempStr = ("");
//
//        digit = tempZip % 10;
//        tempZip /= 10;
//
//        //7
//        if ((digit - 7) >= 0) {
//            tempStr += '1';
//            digit -= 7;
//        }
//        else {
//            tempStr += '0';
//        }
//
//        //4
//        if ((digit - 4) >= 0) {
//            tempStr += '1';
//            digit -= 4;
//        }
//        else {
//            tempStr += '0';
//        }
//
//        //2
//        if ((digit - 2) >= 0) {
//            tempStr += '1';
//            digit -= 2;
//        }
//        else {
//            tempStr += '0';
//
//        }
//
//        //1
//        if ((digit - 1) >= 0) {
//            tempStr += '1';
//            digit -= 1;
//        }
//        else {
//            tempStr += '0';
//        }
//
//        //0
//        if ((digit - 0) >= 0) {
//            tempStr += '1';
//            digit -= 0;
//        }
//
//        reverseStr(tempStr);
//
//        for (int j = 0; j < tempStr.length(); j++) {
//            tempBar += tempStr[j];
//        }
//    }
//
//    tempBar += '1';
//    reverseStr(tempBar);
//
//    //cout << "final tempBar: " << tempBar << endl;
//    return tempBar;
//}
//
////converts a given barcode string to a zip
//int ZipCode::convertToZipCode(string barCodeIn) {
//
//    int inCodeLength = barCodeIn.length();
//    int tempZipCode = 0;
//
//    int newNum, temp;
//    int digit, placeCounter;
//    string tempStr;
//
//
//    for (int j = 1; j < inCodeLength - 1; j += 5) {
//
//        placeCounter = 5;
//        newNum = 0;
//
//        tempStr = barCodeIn.substr(j, 5); //(pos, len)
//        temp = stoi(tempStr) + 900000;
//
//        while (temp != 9) {
//
//            digit = temp % 10;
//            temp /= 10;
//
//            if (placeCounter == 5 && digit == 1) {
//                newNum += 0;
//            }
//            if (placeCounter == 4 && digit == 1) {
//                newNum += 1;
//            }
//            if (placeCounter == 3 && digit == 1) {
//                newNum += 2;
//            }
//            if (placeCounter == 2 && digit == 1) {
//                newNum += 4;
//            }
//            if (placeCounter == 1 && digit == 1) {
//                newNum += 7;
//            }
//
//            placeCounter--;
//
//        }
//
//        //cout << "newnum: " << newNum << endl;
//
//        if (newNum != 11) {
//            for (int i = 1; i < (inCodeLength - j - 1) / 5; i++) {
//                newNum *= 10;
//                //cout << "newnum: " << newNum << endl;
//            }
//            tempZipCode += newNum;
//        }
//
//        //cout << "zipcode: " << tempZipCode << endl;
//    }
//    return tempZipCode;
//}
//
////accessor functions
//int ZipCode::getZipCode() {
//    return zipCode;
//}
//string ZipCode::getBarCode() {
//    return convertToBarCode(zipCode);
//}