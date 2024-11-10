#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows and columns: ";
    cin >> n;
    int array[n];
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += n-i;
    }
    count = n*n -count;
    for (int i = 0;  i < count; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }
    int p = 0;
    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <=j)
            {
                cout << array[p] << "   ";
                p++;
            }
            else
            {
                cout << 0 << "  ";
            }
        }
        cout << endl;
    }
}