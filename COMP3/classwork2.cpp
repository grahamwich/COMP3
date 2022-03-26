////#include <iostream>
////using namespace std;
////
////class A {
////public:
////	A() { ptr = new int(0); }
////	A(int val) { ptr = new int(val); }
////	A(const A& bObj);
////	~A();
////	A& operator=(const A& rOp);
////	int getData(void) const { return *ptr; };
////private:
////	int* ptr;
////
////};
////
////ostream& operator<<(ostream& out, const A& obj);
////
////int main() {
////
////	A obj1(1);
////	obj1 = A(10);
////	A obj2(obj1);
////	A obj3;
////	cout << "3: " << obj3 << endl;
////
////
////	return 0;
////}
////
////ostream& operator<<(ostream& out, const A& obj) {
////	out << obj.getData();
////	return out;
////}
////
////A::~A() {
////	delete ptr;
////}
////
////A::A(const A& bObj) {
////	ptr = new int;
////	*ptr = *bObj.ptr;
////}
////
////A& A::operator=(const A& rOp) {
////	if (this == &rOp) return *this;
////	delete ptr;
////	ptr = new int(rOp.getData());
////	return *this;
////}
//
//
//
//Courses Archive
//Home / Expert Answers / Other / one - problem - dynamic - arrays - array - created - using - new - operator-size - cannot - changed - example - mi
//(Solved) : One Problem Dynamic Arrays Array Created Using New Operator Size Cannot Changed Example Mi ...
//
//One problem with dynamic arrays is that once the array iscreated using the new operator the size cannot be changed.Forexample, you might want to add or delete entries from the arraysimilar to the behavior of a vector.This project asks you tocreate a class called DynamicStringArray that includes memberfunctions that allow it to emulate the behavior of a vector ofstrings.The class should have : ? A private member variable calleddynamicArray that references a dynamic array of type string. ? Aprivate member variable called size that holds the number ofentries in the array. ? A default constructor that sets the dynamicarray to NULLand sets size to 0. ? A function that returns size. ? A function named addEntry that takes a string as input.Thefunction should create a new dynamic array one element larger thandynamicArray, copy all elements from dynamicArray into the newarray, add the new string onto the end of the new array, incrementsize, delete the old dynamicArray, and then set dynamicArray to thenew array. ? A function named deleteEntry that takes a string asinput.The function should search dynamicArray for the string.Ifnot found, return false.If found, create a new dynamic array oneelement smaller than dynamicArray.Copy all elements except theinput string into the new array, delete dynamicArray, decrementsize, and return true. ? A function named getEntry that takes aninteger as input and returns the string at that index indynamicArray.Return NULL if the index is out of dynamicArray’sbounds. ? A copy constructor that makes a copy of the inputobject’s dynamic array. ? Overload the assignment operator so thatthe dynamic array is properly copied to the target object.
//? A destructor that frees up the memory allocated to the dynamicarray.
//Embed your class in a suitable test program.
//
//We are providing you with the main function(in p4main.cpp).Whenit is executed(after writing your class declaration anddefinition, it outputs the following :
//
//List of names : Frank Wiggum Nahasapeemapetilon QuimbyFlanders
//
//After adding a name : Frank Wiggum Nahasapeemapetilon QuimbyFlanders Spuckler
//
//After removing a name : Frank Wiggum Quimby Flanders Spuckler
//
//After removing a name that isn't on the list: Frank Wiggum QuimbyFlanders Spuckler
//
//After adding another name : Frank Wiggum Quimby Flanders SpucklerMuntz
//
//After removing all of the names :
//
//After adding a name : Burns
//
//Testing copy constructor Copied names : Burns
//
//Testing assignment Copied names : Burns
//
//Enter a character to exit.
//
//.
//.
//.
//.
//.
//.
//.
//
//
//p4main.cpp is below
//
//#include <string>
//#include <cstdlib>
//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//    DynamicStringArray names;
//
//    // List of names
//    names.addEntry("Frank");
//    names.addEntry("Wiggum");
//    names.addEntry("Nahasapeemapetilon");
//    names.addEntry("Quimby");
//    names.addEntry("Flanders");
//
//    // Output list
//    cout << "List of names:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    // Add and remove some names
//    names.addEntry("Spuckler");
//    cout << "After adding a name:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    names.deleteEntry("Nahasapeemapetilon");
//    cout << "After removing a name:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    names.deleteEntry("Skinner");
//    cout << "After removing a name that isn't on the list:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    names.addEntry("Muntz");
//    cout << "After adding another name:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    // Remove all of the names by repeatedly deleting the lastone
//    while (names.getSize() > 0) {
//        names.deleteEntry(names.getEntry(names.getSize() - 1));
//    }
//
//    cout << "After removing all of the names:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    names.addEntry("Burns");
//    cout << "After adding a name:" << endl;
//    for (int i = 0; i < names.getSize(); i++)
//        cout << names.getEntry(i) << endl;
//    cout << endl;
//
//    cout << "Testing copy constructor" << endl;
//    DynamicStringArray names2(names);
//    // Remove Burns from names
//    names.deleteEntry("Burns");
//    cout << "Copied names:" << endl;
//    for (int i = 0; i < names2.getSize(); i++)
//        cout << names2.getEntry(i) << endl;
//    cout << endl;
//
//    cout << "Testing assignment" << endl;
//    DynamicStringArray names3 = names2;
//    // Remove Burns from names2
//    names2.deleteEntry("Burns");
//    cout << "Copied names:" << endl;
//    for (int i = 0; i < names3.getSize(); i++)
//        cout << names3.getEntry(i) << endl;
//    cout << endl;
//
//    cout << "Enter a character to exit." << endl;
//    char wait;
//    cin >> wait;
//    return 0;
//}
//
//
//
//WE HAVE AN ANSWER FROM EXPERT
//EXPERT ANSWER
//Answer :
//
//DynamicStringArray.h
//
//#include <string>
//
//using namespace std;
//
//class DynamicStringArray {
//private:
//    string* dynamicArray;
//    int size;
//    int count;
//    void doubleSize();
//public:
//    DynamicStringArray();
//    DynamicStringArray(DynamicStringArray& arr);
//    ~DynamicStringArray();
//    int getSize();
//    void addEntry(string str);
//    bool deleteEntry(string str);
//    string getEntry(int index);
//    void operator=(DynamicStringArray& arr);
//};
//
//DynamicStringArray::DynamicStringArray() {
//    size = 10;
//    count = 0;
//    dynamicArray = new string[size];
//}
//
//DynamicStringArray::DynamicStringArray(DynamicStringArray & arr) {
//    size = arr.size;
//    count = arr.count;
//    for (int i = 0; i < count; ++i) {
//        dynamicArray[i] = arr.dynamicArray[i];
//    }
//}
//
//DynamicStringArray::~DynamicStringArray() {
//    delete[] dynamicArray;
//}
//
//int DynamicStringArray::getSize() {
//    return count;
//}
//
//void DynamicStringArray::doubleSize() {
//    string* newarr = new string[2 * size];
//    for (int i = 0; i < count; ++i) {
//        newarr[i] = dynamicArray[i];
//    }
//    dynamicArray = newarr;
//    size *= 2;
//}
//
//void DynamicStringArray::addEntry(string str) {
//    if (count == size) {
//        doubleSize();
//    }
//    dynamicArray[count++] = str;
//}
//
//bool DynamicStringArray::deleteEntry(string str) {
//    int ind = -1;
//    for (int i = 0; i < count; ++i) {
//        if (dynamicArray[i] == str) {
//            ind = i;
//            break;
//        }
//    }
//    if (ind != -1) {
//        for (int i = ind + 1; i < count; ++i) {
//            dynamicArray[i - 1] = dynamicArray[i];
//        }
//        count--;
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//string DynamicStringArray::getEntry(int index) {
//    if (index < count) {
//        return dynamicArray[index];
//    }
//    else {
//        return "";
//    }
//}
//
//void DynamicStringArray::operator=(DynamicStringArray & arr) {
//    size = arr.size;
//    count = arr.count;
//    for (int i = 0; i < count; ++i) {
//        dynamicArray[i] = arr.dynamicArray[i];
//    }
//}
//
//_____________________________________________________________________________________
//
//DynamicStringArrayTest.cpp
//
//#include <iostream>
//#include "DynamicStringArray.h"
//
//using namespace std;
//
//int main() {
//    DynamicStringArray Arr;
//    int option;
//    string str;
//    int ind;
//    while (true) {
//        cout << "1. add a string" << endl;
//        cout << "2. delete a string" << endl;
//        cout << "3. size of thearray" << endl;
//        cout << "4. To get a stringat an index" << endl;
//        cout << "5. exit" << endl;
//        cout << "Please choose anoption: ";
//        cin >> option;
//        switch (option) {
//        case 1:
//            cout << "Enter a string to add to array: ";
//            cin >> str;
//            Arr.addEntry(str);
//            break;
//        case 2:
//            cout << "Enter a string to delete: ";
//            cin >> str;
//            Arr.deleteEntry(str);
//            break;
//        case 3:
//            cout << "Size of the array is " << Arr.getSize() << endl;
//            break;
//        case 4:
//            cout << "Enter index: ";
//            cin >> ind;
//            str = Arr.getEntry(ind);
//            if (str != "") {
//                cout << "String at index " << ind << " is " << str << endl;
//            }
//            else {
//                cout << "Index out of Bounds!" << endl;
//            }
//        case 5:
//            return 0;
//        default:
//            cout << "Please choose a valid option!" << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}

