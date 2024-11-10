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
    int pos;
    cout << "enter position at which element is to be inserted: ";
    cin >> pos;
    cout << "enter element to be inserted: ";
    int temp;
    cin >> temp;
    for (int i = ::size; i >=pos; i--)
    {
        array[i] = array[i-1];
    }
    array[pos-1] = temp;
    ::size++;
    display(array);
}