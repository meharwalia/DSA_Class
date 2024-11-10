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



int main()
{
    int *array;
    create_array(&array);
    display(array);
    int count = 0;
    for (int i = 0; i < ::size; i++)
    {
        for (int j = i+1; j < ::size; j++)
        {
            if (array[i] > array[j])
            {
                count ++;
            }
        }
    }    
    cout << "Count: " << count << endl;
    return 0;
}