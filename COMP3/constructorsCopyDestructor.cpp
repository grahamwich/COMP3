////
////  lecture10_LinkedList.cpp
////  copy constructor, destructor
////
//
//#include <iostream>
//using namespace std;
//
///*
//struct ListNode {
//    int data;
//    ListNode *next;
//};
//
//struct LinkedList {
//    ListNode *head;
//};
//*/
//
//class ListNode {
//public:
//    ListNode();
//    ListNode(int iData, ListNode* iNext);
//    int getData(void) const;
//    ListNode* getNext(void) const;
//    void setData(int newData);
//    void setNext(ListNode* newNext);
//
//private:
//    int data;
//    ListNode* next;
//};
//
//class LinkedList {
//public:
//    LinkedList();
//    LinkedList(ListNode* iHead);
//    LinkedList(const int arr[], int arrSize);//create a list based on an array
//
//    LinkedList(const LinkedList& orgList);//copy constructor, create an object based on an exsiting object (same type)
//
//    //set/get for head
//    ListNode* getHead(void) const;
//    void setHead(ListNode* newHead);
//    void display(void);
//    //other member functions: remove a node, insert, reverse,etc
//    //destructor: deallocate memory
//    ~LinkedList();
//
//private:
//    ListNode* head;
//};
//
////int main(int argc, char* argv[])
////{
////    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////    LinkedList arrList(arr, sizeof(arr) / sizeof(int));
////    arrList.display();
////
////    LinkedList copyList(arrList);
////    copyList.display();
////
////    cout << endl;
////    arrList.getHead()->setData(-2);
////    arrList.display();
////    copyList.display();
////    return 0;
////}
//
//
//
////ListNode class
//ListNode::ListNode() {
//    data = 0;
//    next = nullptr;
//}
//ListNode::ListNode(int iData, ListNode* iNext) {
//    data = iData;
//    next = iNext;
//}
//
//
//int ListNode::getData(void) const {
//    return data;
//}
//ListNode* ListNode::getNext(void) const {
//    return next;
//}
//
//void ListNode::setData(int newData)
//{
//    data = newData;
//}
//
//void ListNode::setNext(ListNode* newNode) {
//    next = newNode;
//}
//
//
//
/////////// LinkedList class
//LinkedList::LinkedList()
//{
//    head = nullptr;
//}
//LinkedList::LinkedList(ListNode* iHead) {
//    head = iHead;
//}
//
//ListNode* LinkedList::getHead(void) const
//{
//    return head;
//}
//void LinkedList::setHead(ListNode* newHead) {
//    head = newHead;
//}
//
//LinkedList::LinkedList(const int arr[], int arrSize)
//{
//    //call the default constructor
//    head = nullptr;
//
//    for (int i = arrSize - 1; i >= 0; i--)
//    {
//        //for each element in the array arr[i], create a new node, link it to the linked list
//        //ToDo
//        ListNode* newNode;
//        newNode = new ListNode(arr[i], head);
//        head = newNode;
//    }
//}
//
//
//void LinkedList::display()
//{
//    ListNode* temp;
//    temp = head;
//    while (temp != nullptr)
//    {
//        cout << temp->getData();
//        cout << " ";
//        temp = temp->getNext();
//    }
//    cout << endl;
//}
//
//
//
////COPYCON AND DECON BELOW:
//
////copy:
//LinkedList::LinkedList(const LinkedList& orgList)
//{
//    cout << "in LinkedList copy constructor" << endl;
//
//    //linkedlist variable is "head", set to null
//    head = nullptr;
//    //create a new node "cursor" that POINTS TO the start of orgList (the input list)
//    ListNode* orgCursor = orgList.getHead(); //using getHead, defined in LinkedList, returns only the head node
//    //set the "cursor" or "pointer" (not data type, just a literal pointer) to start
//    ListNode* cursor = head;
//
//    //iterate thru list
//    while (orgCursor != nullptr)
//    {
//        //create new node using dynamic mem alloc, to create a node that uses the data of the current node (being pointed to by orgCursor), setting the "next" value to null.
//        ListNode* newNode = new ListNode(orgCursor->getData(), nullptr);
//
//        //move the head down the list
//        if (head == nullptr)
//        {
//            head = newNode;
//        }
//        //set the cursor to the new node
//        else
//        {
//            cursor->setNext(newNode);
//        }
//        cursor = newNode;
//        orgCursor = orgCursor->getNext();
//    }
//}
//
////destruct
//LinkedList::~LinkedList()
//{
//    cout << "in ~LinkedList()" << endl;
//    //create "pointer" (literal pointer to whichever node is being deleted)
//    ListNode * cursor;
//
//    while (head != nullptr)
//    {
//        cursor = head;
//        head = head->getNext();
//        cursor->setNext(nullptr);
//        cout << "free node: " << cursor->getData() << endl;
//        delete cursor;
//    }
//}
