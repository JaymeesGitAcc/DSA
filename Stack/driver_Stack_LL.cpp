#include "Stack_LL.cpp"
#include <iostream>
using namespace std;

int main()
{
    Stack_LL stack1;
    stack1.push(10);
    stack1.push(45);
    stack1.push(67);

    stack1.pop();

    // Stack_LL stack2;
    // stack2 = stack1;
    cout << "Peak value " << stack1.peak();
    return 0;
}