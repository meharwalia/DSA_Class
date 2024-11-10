#include <iostream>
using namespace std;

int size;

void create_array(int **array)
{
    cout << "Enter size of array: ";
    cin >> ::size;
    int *arr = (int *)new int[::size];
    cout << "Enter elements in sorted order:\n";
    for(int i = 0; i < ::size; i++)
    {
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];

    }
    *array = arr;
}

void display(int *array)
{
    for(int i = 0; i < ::size; i++)
    {
        cout << array[i] << endl;
    }
}
void sort(int *array)
{
    for (int i = 0; i < ::size; i++)
    {
        for (int j = 0;  j < ::size-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int *array;
    create_array(&array);
    sort(array);
    int distinct = 1;
    for (int i = 0 ; i < ::size-1; i++)
    {
        if (array[i]!=array[i+1])
        {
            distinct++;
        }
    }
    cout << "Count of Distinct elements: " << distinct;
}