#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};

class DLL
{
    node *start;

public:
    DLL(); // constructor to initialize the start pointer

    void insertAtBeg(int);         // method to insert a node at the beginning
    void insertAtLast(int);        // method to insert a node at the last
    void insertAfter(node *, int); // method to insert a node after a specific node
    node *searchNode(int);         // method to search for a node

    void deleteFirst();          // method to delete the first node
    void deleteLast();           // method to delete the last node
    void deleteSpecific(node *); // method to delete a specific node

    void traverseList(); // method to traverse the list
    bool isEmpty();      // method to check whether the list is empty or not

    ~DLL(); // destructor to delete the whole list
};

// constructor -->
DLL::DLL()
{
    start = nullptr;
}

// insertAtBeg -->
void DLL::insertAtBeg(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = start;
    start = newNode;
}

// insertAtLast -->
void DLL::insertAtLast(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;

    node *t = start;
    if (!t)
        start = newNode;
    else
    {
        while (t->next)
            t = t->next;

        t->next = newNode;
    }
    newNode->prev = t;
}

// insertAfter -->
void DLL::insertAfter(node *ptr, int value)
{
    if (ptr)
    {
        node *newNode = new node;
        newNode->data = value;

        newNode->next = ptr->next;
        newNode->prev = ptr;
        if (ptr->next)
            ptr->next->prev = newNode;
        ptr->next = newNode;
    }
}

// search -->
node *DLL::searchNode(int value)
{
    node *t = start;
    while (t)
    {
        if (t->data == value)
            return t;
        t = t->next;
    }
    return t;
}

// deleteFirst -->
void DLL::deleteFirst()
{
    node *firstNode = start;
    if (start->next)
        start->next->prev = nullptr;
    start = start->next;
    delete firstNode;
}

// deleteLast -->
void DLL::deleteLast()
{
    node *t = start;

    while (t->next)
        t = t->next;

    if (t->prev)
        t->prev->next = nullptr;
    else
        start = nullptr;
    delete t;
}

// deleteSpecific -->
void DLL::deleteSpecific(node *ptr)
{
    if (ptr)
    {
        if (ptr == start)
            start = start->next;
        else
            ptr->prev->next = ptr->next;
        if (ptr->next)
            ptr->next->prev = ptr->prev;
        delete ptr;
    }
}

// traverseList -->
void DLL::traverseList()
{
    node *t = start;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

// isEmpty -->
bool DLL::isEmpty()
{
    return start == nullptr;
}

// destructor -->
DLL::~DLL()
{
    while (start)
        deleteFirst();
}

int main()
{
    DLL list;

    list.insertAtLast(12);
    list.insertAtLast(6);
    list.insertAtLast(90);

    list.traverseList();

    list.insertAtBeg(14);
    cout << endl;
    list.traverseList();

    list.insertAfter(list.searchNode(12), 89);
    cout << endl;
    list.traverseList();

    list.insertAfter(list.searchNode(90), 190);

    cout << endl;
    list.traverseList();

    list.~DLL();
    list.insertAtLast(10);

    cout << endl;
    list.traverseList();

    list.insertAfter(list.searchNode(10), 24);

    cout << endl;
    list.traverseList();

    list.deleteFirst();

    list.insertAfter(list.searchNode(24), 56);

    cout << endl;
    list.traverseList();

    list.deleteSpecific(list.searchNode(56));
    cout << endl;

    list.deleteSpecific(list.searchNode(24));
    if (!list.isEmpty())
        list.traverseList();
    else
        cout << "List is empty";

    return 0;
}