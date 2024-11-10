#include <iostream>
using namespace std;

class Test
{
public:
    Test() { cout << "in constructo" << endl; }
    ~Test() { cout << "In destructor" << endl; }
};
int main()
{
    Test c;
    cout << "In main" << endl;
    ;
}
