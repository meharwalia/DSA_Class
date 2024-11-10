#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter String from which vowels have to be removed: ";
    string s1;
    getline(cin,s1);

    for (int i = 0; i < s1.length(); i++)
    {
        char a = tolower(s1[i]);
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            s1.erase(i,i);
        }
    }
    cout << "After removing: " << s1 << endl;
}