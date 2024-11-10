#include <iostream>
using namespace std;

int size;

void create_array(int **array)
{
    cout << "Enter size of array: ";
    cin >> ::size;
    int *arr = (int *)new int[::size + 2];
    for (int i = 0; i < ::size; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }
    *array = arr;
}

void display(int *array)
{
    for (int i = 0; i < ::size; i++)
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
    cout << "enter the which element is to be deleted: ";
    int pos;
    cin >> pos;
    for (int i = 0; i < ::size; i++)
    {
        if (array[i] == pos)
        {
            for (int j = i; j < ::size - 1; j++)
            {
                array[j] = array[j + 1];
            }
            ::size--;
            display(array);
            return 0;
        }
    }
    cout << "Element not found\n";
    return 1;
}