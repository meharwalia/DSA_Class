#include <iostream>
using namespace std;

int row;
int column;



void create_array(int ***array)
{
    cout << "Enter number of rows in array: ";
    cin >> row;
    cout << "Enter number of columns in array: ";
    cin >> column;
    int **arr_temp = (int **)malloc(row*sizeof(int *));
    if (arr_temp == NULL)
    {
        cout << "Cannot create array for given capacity";
        return;
    }
    for (int i = 0; i < row; i++)
    {
        arr_temp[i] = (int *)malloc(column*sizeof(int));
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Enter element " << i + 1 << " row and " << j + 1 << " column : ";
            cin >> arr_temp[i][j];
        }
    }

    cout << "Array Created Succesfully\n";
    *array = arr_temp;
    return;
}

void display_array(int **array, int row, int column)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
}
// int ** array means give address of an array in which each element stores address of an integer(address of an integer means another array, and this array in our case is the array of all coulmns)
int **transpose (int **array, int rows, int columns)
{
    int **arr_temp = (int **)malloc(columns*sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        arr_temp[i] = (int *)malloc(rows*sizeof(int));
    }
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            arr_temp[i][j] = array[j][i];
            // cout << array[i][j] << "  ";
        }
        // cout << endl;
    }
    return arr_temp;
}

int main()
{
    int **array;
    create_array(&array);
    cout << "Input Array: \n";
    display_array(array, row, column);
    // transpose(array, row, column);
    int **arr_trans;
    arr_trans = transpose(array, row, column);
    cout << "Transposed Array: \n";    
    display_array(arr_trans, column, row);
}