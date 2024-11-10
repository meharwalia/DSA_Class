#include <iostream>
using namespace std;

void display(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << "   ";
    }
    cout << "\n";
}

int main()
{
    int array[7] = {64, 34, 25, 12, 22, 11, 90};
    display(array, 7);
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0;  j < 7-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    cout << "After Sorting: \n";
    display(array, 7);
    
    return 0;
}