#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the number of rows and columns: ";
    cin >> size;
    int array[size];
    cout << "Enter elements: \n";
    for (int i = 0;  i < size; i++)
    {
        cout << "Enter element : ";
        cin >> array[i];
    }
    for (int i = 0;  i < size; i++)
    {
        for (int j = 0;  j < size; j++)
        {
            if (i == j)
            {
                cout << array[i] << "   ";
            }
            else
            {
                cout << 0 << "  ";
            }
        }
        cout << endl;
    }


}