#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter string to be reversed: ";
    string s1;
    cin >> s1;
    reverse(s1.begin(), s1.end());
    cout << "Reversed string: " << s1;
    return 0;
}