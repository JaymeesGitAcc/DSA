// Implementation of Stack data-structure using singly linked list approach

struct node
{
    int data;
    node *next;
};

class Stack_LL
{
private:
    node *top;
    node *head;

public:
    Stack_LL();                      // constructor to initialize the instance variables
    bool isEmpty();                  // method to check stack is empty or not
    void push(int);                  // method to push a value into the stack
    void pop();                      // method to pop a value from the stack
    int peak();                      // method to see the top value
    Stack_LL &operator=(Stack_LL &); // method to make a new copy of the existing stack
    void reverse();                  // method to reverse the stack
    ~Stack_LL();                     // destructor to release the memory of stack
};

// Stack_LL (constructor) -->
Stack_LL::Stack_LL()
{
    top = head = nullptr;
}

// isEmpty -->
bool Stack_LL::isEmpty()
{
    return head == nullptr && top == nullptr;
}

// push -->
void Stack_LL::push(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty())
    {
        top = head = newNode;
    }
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

// pop -->
void Stack_LL::pop()
{
    if (!isEmpty())
    {
        if (top == head)
        {
            delete top;
            top = head = nullptr;
        }
        else
        {
            node *t = head;
            while (t->next != top)
            {
                t = t->next;
            }
            t->next = nullptr;
            delete top;
            top = t;
        }
    }
}

// peak -->
int Stack_LL::peak()
{
    if (!isEmpty())
        return top->data;
    return -404;
}

// operator= -->
Stack_LL &Stack_LL::operator=(Stack_LL &existingStack)
{
    // existing = 2(h)->5->4->10(t)
    Stack_LL newStack;
    node *t = existingStack.head;
    while (t)
    {
        newStack.push(t->data);
        t = t->next;
    }
    return newStack;
}

// reverse -->
void Stack_LL::reverse()
{
    // existing = 2(h)->5->4->10(t)
    // reverse = 10(h)->4->5->2(t)
    if (!isEmpty())
    {
    }
}

// ~Stack_LL -->
Stack_LL::~Stack_LL()
{
    while (!isEmpty())
        pop();
}
