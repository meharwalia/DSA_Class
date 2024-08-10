#include <cstdlib>
#include <iostream>
using namespace std;

int capacity;


void create_array(int **array);
void display_array(int *array);
void insert(int **array);
void delete_element(int *array);
void linear_search(int *array);

int main()
{
    bool cont = true;
    while(cont)
    {
        int option;
        cout << "\n1.Create Array\n2.Display\n3.Insert\n4.Delete\n5.Linear Search\n6.Exit\n";
        cout << "Enter Choice: ";
        cin >> option;
        int *array;
        switch (option)
        {
            case 1:
            {
                create_array(&array);
                break;
            }
            case 2:
            {
                display_array(array);
                break;
            }
            case 3:
            {
                insert(&array);
                break;
            }
            case 4:
            {
                delete_element(array);
                break;
            }
            case 5:
            {
                linear_search(array);
                break;
            }
            case 6:
            {
                cont = false;
                break;
            }
            default :
            {
                cout << "Invalid Option\n";
            }
        }
    }
}


void create_array(int **array)
{
    cout << "Enter number of elements in array: ";
    cin >> capacity;
    int * arr_temp = (int *)malloc(capacity*sizeof(int));
    if (arr_temp == NULL)
    {
        cout << "Cannot create array for given capacity";
        return;
    }
    for (int i = 0; i < capacity; i++)
    {
        cout << "Enter element "<< i+1 << ": ";
        cin >> arr_temp[i];
    }
    *array = arr_temp;
    cout << "Array Created Succesfully\n";
    return;
}

void display_array(int *array)
{

    for (int i = 0; i < capacity; i++)
    {
        cout << array[i]<<endl;
    }

}

void insert(int **array)
{
    int pos;
    cout << "Enter position at which element is to be inserted: ";
    cin >> pos;
    capacity++;
    // cout << capacity;
    // int *temp = (int *)malloc(capacity * sizeof(int));
    int temp[capacity];
    int j = 0;
    for (int i = 0; i < capacity; i++)
    {
        if (i != pos-1)
        {
            temp[i] = (*array)[j];
            // cout << j << "  " << i;
            j++;
        }
        else
        {
            cout << "Enter element: ";
            cin >> temp[i];           
            // cout << j<<"    "<<i;
        }
        // cout << "Hello\n";
    }
    // *array = temp;
    display_array(temp);
    cout << "Element Inserted!!\n";
    return ;
}

void delete_element(int *array)
{
    int index;
    cout << "Enter index from which element is to deleted: ";
    cin >> index;
    if (index >= capacity)
    {
        cout << "Error: index out of range\n";
        return;
    }
    for (int i = index; i < capacity-1; i++)
    {
        array[i] = array[i+1]; 
    }
    capacity--;
    return ;
}

void linear_search(int *array)
{
    int number;
    cout << "Enter number which we have to search: ";
    cin >> number;
    int flag = 0;
    for (int i = 0; i < capacity; i++)
    {
        if(array[i] == number)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "Found !!\n";
    }
    else
    {
        cout << "Not Found !!\n";
    }
    return;
    
}