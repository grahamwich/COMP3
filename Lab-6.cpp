//#undef debug
//
//#include <iostream>
//#include <string>
//#include <list>
//#include <map>
//
//using namespace std;
//
//
//template<typename T>
//class BSTNode {
//
//public:
//    // Constructors, etc.
//    BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
//    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
//    BSTNode(BSTNode&); // copy constructor
//    ~BSTNode(); // destructor
//    BSTNode& operator=(BSTNode&); // copy assignment operator
//
//    // ***** Your group will define/implement the insert function
//    // ***** at about line 89 below...
//    void insert(const T& data);
//
//    // Accessor and mutator functions
//    BSTNode<T>* getLeft() const { return _left; }
//
//    BSTNode<T>* getRight() const { return _right; }
//
//    T& getData() const { return _data; }
//
//    void setData(const T& data) { _data = data; }
//
//    // Display functions used by operator<<.
//    // ***** Your group will define/implement the pre & post display functions
//    // ***** at about lines 114 & 127 below...
//    void inOrderDisplay(ostream&) const;
//    void preOrderDisplay(ostream&) const;
//    void postOrderDisplay(ostream&) const;
//
//    void listify(list<T>&) const;
//
//    // The insertion operator below uses in-order display.
//    // ***** Change the implementation of this insertion operator
//    // ***** in order to switch to pre- or post-order display
//    friend ostream& operator<<(ostream& out, const BSTNode<T>& b) {
//        b.postOrderDisplay(out);
//        return out;
//    }
//
//
//
//private:
//    T _data;
//    BSTNode<T>* _left;
//    BSTNode<T>* _right;
//
//    // private "helper" functions
//    void addLeft(const T& data) { _left = new BSTNode(data); }
//
//    void addRight(const T& data) { _right = new BSTNode(data); }
//};
//
//
//template<typename T>
//BSTNode<T>::BSTNode(BSTNode& b) {
//#ifdef debug
//    cout << "BSTNode copy constructor called, _data == " << _data << endl;
//#endif
//    _data = b._data;
//    _left = _right = nullptr;
//    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
//    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
//}
//
//
//template<typename T>
//BSTNode<T>::~BSTNode() {
//#ifdef debug
//    cout << "BSTNode destructor called, _data == " << _data << endl;
//#endif
//    delete _left;
//    delete _right;
//}
//
//
//template<typename T>
//BSTNode<T>& BSTNode<T>::operator=(BSTNode& b) {
//#ifdef debug
//    cout << "BSTNode copy assignment operator: ";
//#endif
//    _data = b._data;
//    _left = _right = nullptr;
//    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
//    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
//    return *this;
//}
//
//
//template<typename T>
//void BSTNode<T>::insert(const T& data) {
//    // comment out the next line when you've completed this function!
//    //cout << "BSTNode<T>::insert called with data == " << data << endl;
//
//    // if the given data is less than the current node, recur for the left subtree
//    if (data < _data) {
//        if (_left == nullptr) {
//            _left = new BSTNode<T>(data);
//            return;
//        }
//        else {
//            _left->insert(data);
//            return;
//        }
//    }
//    else {
//        if (_right == nullptr) {
//            _right = new BSTNode<T>(data);
//            return;
//        }
//        else {
//            _right->insert(data);
//            return;
//        }
//    }
//
//}
//
//
//template<typename T>
//void BSTNode<T>::inOrderDisplay(ostream& out) const {
//    if (_left != nullptr) {
//        _left->inOrderDisplay(out);
//        out << ", ";
//    }
//    out << _data;
//    if (_right != nullptr) {
//        out << ", ";
//        _right->inOrderDisplay(out);
//    }
//}
///**
// *  ***** Complete preOrderDisplay and postOrderDisplay below *****
// */
//template<typename T>
//void BSTNode<T>::preOrderDisplay(ostream& out) const {
//    // comment out the next line when you've completed this function!
//    //cout << "BSTNode<T>::preOrderDisplay called\n";
//
//    out << _data;
//
//    if (_left != nullptr) {
//        out << ", ";
//        _left->preOrderDisplay(out);
//    }
//    if (_right != nullptr) {
//        out << ", ";
//        _right->preOrderDisplay(out);
//    }
//}
//
//template<typename T>
//void BSTNode<T>::postOrderDisplay(ostream& out) const {
//    // comment out the next line when you've completed this function!
//    //cout << "BSTNode<T>::postOrderDisplay called\n";
//
//    if (_left != nullptr) {
//        _left->postOrderDisplay(out);
//        out << ", ";
//    }
//    if (_right != nullptr) {
//        _right->postOrderDisplay(out);
//        out << ", ";
//    }
//    out << _data;
//}
//
//template<typename T>
//void BSTNode<T>::listify(list<T>& inList) const {
//    if (_left != nullptr) {
//        _left->listify(inList);
//    }
//    inList.push_back(_data);
//    if (_right != nullptr) {
//        _right->listify(inList);
//    }
//}
//
//int main(void) {
//    BSTNode<int> iroot(100);
//    iroot.insert(10);
//    iroot.insert(20);
//    iroot.insert(200);
//    iroot.insert(300);
//    cout << "iroot == " << iroot << endl;
//
//    BSTNode<string> sroot("Sunday");
//    sroot.insert("Monday");
//    sroot.insert("Tuesday");
//    sroot.insert("Wednesday");
//    sroot.insert("Thursday");
//    sroot.insert("Friday");
//    sroot.insert("Saturday");
//    cout << "sroot == " << sroot << endl;
//
//
//    // ...insert data into iroot...
//    list<int> irootList;
//    iroot.listify(irootList);
//
//    cout << "Creating irootList via iroot.listify" << endl;
//    cout << "irootList (forward iterator) == ";
//    list<int>::iterator i1;
//    for (i1 = irootList.begin(); i1 != irootList.end(); i1++) {
//        cout << *i1;
//    }
//
//    cout << "irootList (reverse iterator) == ";
//    for (list<int>::reverse_iterator i2 = irootList.rbegin(); i2 != irootList.rend(); i2++) {
//        cout << *i2;
//    }
//
//    cout << "irootList (ranged for loop) == ";
//    for (auto& each : irootList) {
//        cout << each;
//    }
//    ///
//    list<string> srootList;
//    sroot.listify(srootList);
//
//    cout << "Creating srootList via sroot.listify" << endl;
//    cout << "srootList (forward iterator) == ";
//    list<string>::iterator sI1;
//    for (sI1 = srootList.begin(); sI1 != srootList.end(); sI1++) {
//        cout << *sI1;
//    }
//
//
//    cout << "srootList (reverse iterator) == ";
//    for (list<string>::reverse_iterator i2 = srootList.rbegin(); i2 != srootList.rend(); i2++) {
//        cout << *i2;
//    }
//
//    cout << "srootList (ranged for loop) == ";
//    for (auto& each : srootList) {
//        cout << each;
//    }
//
//    BSTNode<int> iroot4(100);
//    iroot.insert(1000);
//    iroot.insert(2000);
//    iroot.insert(3000);
//    iroot.insert(4000);
//    iroot.insert(5000);
//    cout << "iroot == " << iroot << endl;
//    list<int> irootList4;
//    iroot4.listify(irootList4);
//    map<string, list<int>> mi;
//
//    for (auto eachPair : mi) {
//        cout << eachPair.first;
//        for (auto& each : eachPair.second) {
//            cout << each;
//        }
//    }
//
//    map < string, list<int>> ::iterator p = mi.begin();
//    for (; p != mi.end(); p++)
//    {
//        cout << (*p).first;
//        for (auto& each : (*p).second) {
//            cout << each;
//        }
//    }
//
//#ifdef debug
//    BSTNode<int> iroot2(iroot); // use copy constructor
//    cout << "\nAfter copy constructor:\n";
//    cout << "iroot2 == " << iroot2 << endl;
//
//    BSTNode<int> iroot3;
//    iroot3 = iroot2; // use copy assignment operator
//    cout << "\nAfter copy assignment operator:\n";
//    cout << "iroot3 == " << iroot3 << endl << endl;
//#endif
//
//    return 0;
//}
