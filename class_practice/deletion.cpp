#include <iostream>
using namespace std;

int size;

void create_array(int **array)
{
    cout << "Enter size of array: ";
    cin >> ::size;
    int *arr = (int *)new int[::size+2];
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
        cout << array[i] << "   ";
    }
    cout << endl;
}

int main()
{
    int *array;
    create_array(&array);
    display(array);
    cout << "enter the position from which element is to be deleted: ";
    int pos;
    cin >> pos;
    for (int i = pos-1; i < ::size-1; i++)
    {
        array[i] = array[i+1];
    }
    ::size--;
    display(array);
    return 0;
}