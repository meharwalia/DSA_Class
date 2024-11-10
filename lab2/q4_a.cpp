#include <iostream>
using namespace std;

int main()
{
    cout << "Enter string 1: ";
    string s1;
    cin >> s1;
    
    cout << "Enter string 1: ";
    string s2;
    cin >> s2;

    s1 = s1+s2;
    cout << "Concatenated string: " << s1;

}