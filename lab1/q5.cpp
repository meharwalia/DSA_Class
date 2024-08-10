#include <cstdlib>
#include <iostream>
using namespace std;

int row;
int column;
// int **array means a pointer to a memory location which stores address of an integer
void create_array(int ***array)
{
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    int ** arr_temp = (int **)malloc(row*sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        arr_temp[i] = (int *)malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column ; j++)
        {
            cout << "Enter element of " << i+1 << " row and "<< j+1<<" column: ";
            cin >> arr_temp[i][j];
        }
        
    }

    *array = arr_temp;
}

void display(int **array)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column ; j++)
        {
            cout << array[i][j] << "    ";
        }
        cout << endl;
    }
}

void sum_rows(int **array)
{
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < column; j++)
        {
            count += array[i][j];
        }
        cout << "Sum of row " << i+1 << " : " << count << endl;
    }
}

void sum_column(int **array)
{
    for (int i = 0; i < column; i++)
    {
        int count = 0;
        for (int j = 0;  j < row; j++)
        {
            count += array[j][i];
        }
        cout << "Sum of column "<< i+1 << " : "<< count << endl;
    }
}

int main()
{
    int **array;
    create_array(&array);
    display(array);
    sum_rows(array);
    sum_column(array);
    return 0;
}