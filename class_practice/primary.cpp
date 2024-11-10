#include <iostream>
using namespace std;

// int capacity = 10;

class Stack
{
    int stack[10];
    int top = 0;
    public:
        void pop()
        {
            if (top != 0)
            {
                top --;
            }
            else
            {
                cout << "Stack Already Empty, Underflow\n";
            }
            return;
        }
        void push(int number)
        {
            if (top != capacity)
            {
                stack[top] = number; 
            }
            else
            {
                cout << "Stack already full, Overflow\n";
            }
        }
};


int main()
{
    Stack s1;
    
    return 0;
}