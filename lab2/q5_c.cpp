#include<iostream>
using namespace std;
// Lower triangular matrix
int main()
{
    int size;
    cout << "Enter the number of rows and columns: ";
    cin >> size;
    cout <<  "enter elements: ";
    int array[size];
    int count  = 0;
    for (int i = 1;  i <= size; i++)
    {
        count += size-i;
    }
    // count  = size-count;
    // cout << count << endl;
    for (int i = 0; i < (size*size-count); i++)
    {
        cout << "Element: ";
        cin >> array[i];
    }
    int n = 0;
    for (int i = 0;  i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((i >= j))
            {
                cout << array[n] << "   ";
                n++;
            }
            else
            {
                cout << 0 << "  ";
            }
        }
        cout << endl;
    }

}