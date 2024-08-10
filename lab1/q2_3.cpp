#include <iostream>
using namespace std;

int capacity;

void create_array(int **array)
{
    cout << "Enter number of elements in array: ";
    cin >> capacity;
    int *arr_temp = (int *)malloc(capacity * sizeof(int));
    if (arr_temp == NULL)
    {
        cout << "Cannot create array for given capacity";
        return;
    }
    for (int i = 0; i < capacity; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr_temp[i];
    }
    *array = arr_temp;
    cout << "Array Created Succesfully\n";
    return;
}
void display_array(int *array, int count)
{

    for (int i = 0; i < count; i++)
    {
        cout << array[i] << endl;
    }
}

int main()
{
    int *array;
    create_array(&array);
    // int j = 0;
    for (int i = 0; i < capacity - 1; i++)
    {
        int swaps = 0;
        for (int j = 0; j < capacity - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
        {
            break;
        }
    }
    int j = 1;
    for (int i = 0; i < capacity-1; i++)
    {
        if (array[i]!=array[i+1])
        {
            array[j] = array[i+1];
            j++;
        }
    }
    // j--;
    display_array(array, j);
}