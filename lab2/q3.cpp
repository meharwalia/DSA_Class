#include <iostream>
using namespace std;

int size;

void create_array(int **array)
{
    cout << "Enter size of array: ";
    cin >> ::size;
    int *arr = (int *)new int[::size];
    cout << "Enter elements:\n";
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

bool in(int *array, int num)
{
    int start = 0;
    int end = ::size -1;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (array[mid] == num)
        {
            return true;
        }
        else
        {
            if (array[mid] > num)
            {
                end =mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
    }
    return false;
}

int main()
{
    int *array;
    create_array(&array);
    display(array);
    sort(array);
    cout << "After Sorting: \n";
    display(array);
    cout << "Missing Numbers: \n";
    for(int i = array[0]; i < array[::size-1]; i++)
    {
        if (!in(array, i))
        {
            cout << i << endl;
        }
    }
}