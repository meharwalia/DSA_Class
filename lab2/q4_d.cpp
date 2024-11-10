#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string s1;
    getline(cin, s1);
    sort(s1.begin(), s1.end());
    cout << "After Sorting: " << s1;
}