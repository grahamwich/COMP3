//6
#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray {
private:
    string* dynamicArray;
    int size;
public:
    DynamicStringArray() {
        dynamicArray = nullptr;
        size = 0;
    };
    DynamicStringArray(int iSize) {
        size = iSize;
        dynamicArray = new string[size];
    };

    DynamicStringArray(const DynamicStringArray& iArray) {
        size = iArray.size;
        dynamicArray = new string[size];

        // copy over elements

        for (int i = 0; i < size; i++) {
            dynamicArray[i] = iArray.dynamicArray[i];
        }
    }
    int getSize() {
        return size;
    };
    void addEntry(string iString);
    bool deleteEntry(const string& iString);
    string* getEntry(const int index);
    DynamicStringArray& operator=(const DynamicStringArray& iArray);
    ~DynamicStringArray();
};

int main(int argc, char* argv[]) {

    DynamicStringArray arr;
    arr.addEntry("ABCDE");
    arr.addEntry("fghij");
    arr.addEntry("KLMNO");

    arr.deleteEntry("fghij");


    return 0;
}

void DynamicStringArray::addEntry(string iString) {
    //adding an entry so the size increments by 1
    size++;
    string* tempArray = new string[size];

    for (int i = 0; i < (size - 1); i++) {
        tempArray[i] = dynamicArray[i];
    }
    tempArray[size - 1] = iString;
    delete[] dynamicArray;
    dynamicArray = tempArray;
};

bool DynamicStringArray::deleteEntry(const string& iString) {
    // find the string
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == iString) {
            foundIndex = i;
        }
    }
    // didn't find the string
    if (foundIndex == -1) {
        return false;
    }

    string* newDynamicArray = new string[size - 1];

    // copy over every element, skipping foundIndex
    for (int i = 0; i < size; i++) {
        if (i < foundIndex) {
            newDynamicArray[i] = dynamicArray[i];
        }
        else if (i == foundIndex) {
            continue;
        }
        else { // i > foundIndex
            newDynamicArray[i - 1] = dynamicArray[i];
        }
    }

    size--;
    delete[] dynamicArray;
    dynamicArray = newDynamicArray;

    return true;
}

string* DynamicStringArray::getEntry(const int index) {

    // check that index is in range and positive
    if (index < size && index > -1) {
        return &dynamicArray[index];
    }
    else {
        return nullptr;
    }
}

DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& iArray) {
    // self assignment
    if (&iArray == this) {
        return *this;
    }

    // alternatively
    // delete current array
    delete[] dynamicArray;
    // create new array of correct size
    dynamicArray = new string[iArray.size];
    // copy over size
    size = iArray.size;

    // copy over each element
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = iArray.dynamicArray[i];
    }
    // return self
    return *this;
}

DynamicStringArray::~DynamicStringArray() {
    delete[] dynamicArray;
}
