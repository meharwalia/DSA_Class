#include <iostream>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string s1;
    getline(cin, s1);
    for (int i = 0 ; i < s1.length(); i++)
    {
        s1[i]=tolower(s1[i]);
    }
    cout << "After converting: " << s1;
    return 0;


}