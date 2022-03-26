//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class ComplexNumber {
//public:
//    ComplexNumber() {
//        real = 0; imaginary = 0;
//    };
//
//    ComplexNumber(double inReal, double inImaginary) {
//        real = inReal;
//        imaginary = inImaginary;
//    };
//    void setReal(double inReal) {
//        real = inReal;
//    };
//    void setImaginary(double inImaginary) {
//        imaginary = inImaginary;
//    };
//    double getImaginary() const {
//        return imaginary;
//    };
//    double getReal() const {
//        return this->real;
//    };
//    const ComplexNumber operator+(const ComplexNumber& n) const;
//    const ComplexNumber operator-(const ComplexNumber& n) const;
//    const ComplexNumber operator/(const ComplexNumber& n) const;
//
//    const ComplexNumber operator*(const ComplexNumber& n) const;
//
//    const ComplexNumber operator!();
//    friend ostream& operator<<(ostream& outStream, const ComplexNumber& n)
//    {
//
//        string plusSymbol;
//        // only use plus symbol if imaginary component is positive
//        if (n.imaginary >= 0) {
//            plusSymbol = "+";
//        }
//        outStream << n.real << plusSymbol << n.imaginary << "i";
//
//
//        return outStream;
//    }
//private:
//    double real;
//    double imaginary;
//};
//
//int main() {
//    ComplexNumber c1;
//    ComplexNumber c2(1, 2);
//    ComplexNumber c3(3, 4);
//    cout << "Value of c1 (default constructor):" << endl;
//    cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImaginary() << endl;
//    cout << "Value of c2 (value constructor):" << endl;
//    cout << "c2.Re() == " << c2.getReal() << ", c2.Im() == " << c2.getImaginary() << endl;
//    cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << c2 + c3 << endl;
//    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << c2 - c3 << endl;
//    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << c2 * c3 << endl;
//    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << c2 / c3 << endl;
//    cout << "(c2/c3) + (c2*c3) == " << (c2 / c3) + (c2 * c3) << endl;
//    cout << "Conjugate of c2 (" << c2 << ") == " << !c2 << endl;
//
//    vector<ComplexNumber> v;
//    for (int i = 0; i < 10; i++)
//    {
//        v.push_back(ComplexNumber(i, 2.0 * i));
//    }
//    cout << "Vector output using indexed for-loop: " << endl;
//    for (int j = 0; j < v.size(); j++)
//    {
//        cout << v[j] << endl;
//    }
//    cout << "Vector output using an iterator in for-loop: " << endl;
//    vector<ComplexNumber>::iterator p;
//    for (p = v.begin(); p != v.end(); p++)
//    {
//        cout << *p << endl;
//    }
//
//    return 0;
//}
//
//const ComplexNumber ComplexNumber::operator!() {
//    this->imaginary = -this->imaginary;
//    return *this;
//};
//
//const ComplexNumber ComplexNumber::operator*(const ComplexNumber& n) const {
//    double newReal = real * n.getReal() + imaginary + n.getImaginary();
//    double newImaginary = real * n.getImaginary() + imaginary * n.getReal();
//
//    const ComplexNumber multiplied(newReal, newImaginary);
//    return multiplied;
//}
//
//
//
//const ComplexNumber ComplexNumber::operator+(const ComplexNumber& n) const {
//    double newReal = this->real + n.getReal();
//    double newImaginary = this->imaginary + n.getImaginary();
//    ComplexNumber tempComplex(newReal, newImaginary);
//    return tempComplex;
//}
//const ComplexNumber ComplexNumber::operator-(const ComplexNumber& n) const {
//    double newReal = this->real - n.getReal();
//    double newImaginary = this->imaginary - n.imaginary;
//    return ComplexNumber(newReal, newImaginary);
//}
//
//const ComplexNumber ComplexNumber::operator/(const ComplexNumber& n) const {
//    double newReal =
//        ((this->real * n.getReal() + this->imaginary * n.getImaginary())) /
//        ((n.getImaginary() * n.getReal()) + (n.getImaginary() * n.getImaginary()));
//
//    double newImaginary =
//        ((this->imaginary * n.getReal()) - (this->real * n.getImaginary())) /
//        ((n.imaginary * n.getReal()) + (n.getImaginary() * n.getImaginary()));
//
//    ComplexNumber tempNum(newReal, newImaginary);
//    return tempNum;
//}
