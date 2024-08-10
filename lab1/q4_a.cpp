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
        cout << array[i]<<endl;
    }

}

int main()
{
    int *array;
    create_array(&array);
    for (int i = 0; i < capacity / 2; i++)
    {
        int temp = array[i];
        array[i] = array[capacity - i - 1];
        array[capacity - i - 1] = temp;
    }
    display_array(array, capacity);
}