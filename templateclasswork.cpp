////
////  C3_Lecture19
//// class templates
//
//#include <iostream>
//using namespace std;
//
//template <class T>
//class Pair {
//public:
//    //constructor
//    Pair();
//    Pair(T val1, T val2) :first(val1), second(val2) {}
//    //accessors and mutators
//    T getFirst(void) const;
//    T getSecond(void) const;
//
//    void setFirst(T val);
//    void setSecond(T val);
//
//private:
//    T first;
//    T second;
//};
////pre-condition: (1) the pair should store values
////         (2) the two objects should be addable (additional operator should work)
////post-condition: (1) return the total of first and second (2) aPair shouldn't be changed
//template <class T>
//T addUp(const Pair<T>& aPair)
//{
//    return aPair.getFirst() + aPair.getSecond();
//}
//
//int main(int argc, const char* argv[]) {
//    Pair<int> intPair(3, 4);
//    Pair<int> intPair2(33, 44);
//
//    Pair<char> charPair('A', 'B');
//
//    Pair<void*> pointerPair(&intPair, &intPair2);
//
//    cout << addUp(pointerPair) << endl;
//
//
//    return 0;
//}
//
//template <class T>
//T Pair<T>::getFirst(void) const
//{
//    return first;
//}
//template <class T>
//T Pair<T>::getSecond(void) const
//{
//    return second;
//}
//
//template <class T>
//void Pair<T>::setFirst(T val)
//{
//    first = val;
//}
//
//template <class T>
//void Pair<T>::setSecond(T val)
//{
//    second = val;
//}