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

int main()
{
    int *array;
    create_array(&array);
    display(array);
    cout << "enter number to be searched: ";
    int find;
    cin >> find;
    int start = 0;
    int end = ::size;
    while (start <= end)
    {
        int mid = (start+end)/2;
        if (array[mid] == find)
        {
            cout << "Found!\n";
            return 0;
        }
        else
        {
            if (array[mid]>find)
            {
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }    
    }
    cout << "Not Found!\n";
    return 1;
}