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

bool in(int *array, int count, int n)
{
    for (int i = 0; i < count; i++)
    {
        if (array[i] == n)
        {
            return true;
        }
    }
    return false;
}
void display_array(int *array, int count)
{

    for (int i = 0; i < count; i++)
    {
        cout << array[i]<<endl;
    }

}

int main()
{
    int *array;
    create_array(&array);
    int count = 0;
    int temp[capacity];
    // With three loops, deleting elements as we encounter duplicate ones
    // for (int i = 0; i < capacity; i++)
    // {
    //    for (int j = i+1; j < capacity; j++)
    //    {
    //         if (array[i] == array[j])
    //         {
    //             for (int k = j; k < capacity-1; k++)
    //             {
    //                 array[k] = array[k+1];
    //             }
    //             capacity--;
    //             j--;
    //         }
    //    }

    // }
    // display_array(array, capacity);
    // using 2 loops but an extra array
    for (int i = 0; i < capacity; i++)
    {
        if (!in (temp, count, array[i]))
        {
            temp[count] = array[i];
            count ++;
        }
    }
    array = temp;
    display_array(array, count);
}