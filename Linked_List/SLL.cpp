#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class SLL
{
    node *start;

public:
    SLL(); // constructor method to initialize the start pointer

    void insertAtFirst(int);       // method to insert a value in the list at the beginning
    void insertAtLast(int);        // method to insert a value in the list at the last
    node *search(int);             // method to search a node
    void insertAfter(node *, int); // method to insert a value after a specified node

    void traverseList(); // method to traverse the list
    bool isEmpty();      // method to check whether the list is empty or not

    void deleteFirst();          // method to delete the first node
    void deleteLast();           // method to delete the last node
    void deleteSpecific(node *); // method to delete a specific node

    ~SLL(); // destructor method to delete the whole list
};

// constructor -->
SLL::SLL()
{
    start = nullptr;
}

// insertAtFirst -->
void SLL::insertAtFirst(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = start;
    start = newNode;
}

// insertAtLast -->
void SLL::insertAtLast(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!start)
        start = newNode;
    else
    {
        node *t = start;
        while (t->next)
            t = t->next;
        t->next = newNode;
    }
}

// search -->
node *SLL::search(int value)
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

// insertAfter -->
void SLL::insertAfter(node *ptr, int value)
{
    if (ptr)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// traverseList-->
void SLL::traverseList()
{
    node *t = start;
    if (!start)
        cout << "\nList is Empty";
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

// deleteFirst -->
void SLL::deleteFirst()
{
    if (start)
    {
        node *toDelete = start;
        start = start->next;
        delete toDelete;
    }
}

// deleteLast -->
void SLL::deleteLast()
{
    if (start)
    {
        node *t = start;

        if (!t->next)
        {
            start = nullptr;
            delete t;
        }
        else
        {
            while (t->next->next)
                t = t->next;
            delete t->next;
            t->next = nullptr;
        }
    }
}

// deleteSpecific -->
void SLL::deleteSpecific(node *ptr)
{

    if (ptr)
    {
        if (ptr == start)
            start = start->next;
        else
        {
            node *t = start;
            while (t->next != ptr)
                t = t->next;

            t->next = ptr->next;
        }
        delete ptr;
    }
}

// isEmpty -->
bool SLL::isEmpty()
{
    return start == nullptr;
}

// destructor -->
SLL::~SLL()
{
    while (start)
        deleteFirst();
}

int main()
{
    SLL obj;

    obj.insertAtLast(90);
    obj.insertAtLast(100);
    // obj.insertAtLast(110);
    obj.deleteSpecific(obj.search(100));
    obj.traverseList();
    return 0;
}