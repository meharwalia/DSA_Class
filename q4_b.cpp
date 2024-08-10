#include <cstdlib>
#include <iostream>
using namespace std;

int row1;
int column1;
int row2;
int column2;

void create_matrix(int ***matrix, int *rows, int *columns)
{
    cout << "Enter number of rows: ";
    cin >> *rows;
    cout << "Enter number of columns: ";
    cin >> *columns;

    int **matrix_temp = (int **)malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows; i++)
    {
        matrix_temp[i] = (int *)malloc(*columns * sizeof(int));
    }

    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *columns; j++)
        {
            cout << "Enter element of row " << i + 1 << " and column " << j + 1 << " : ";
            cin >> matrix_temp[i][j];
        }
    }
    *matrix = matrix_temp;
}

void display(int **matrix, int rows, int columns)
{

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void multiply(int **matrix1, int **matrix2, int row1, int column1, int row2, int column2, int ***multiplied_matrix)
{
    if (column1 != row2)
    {
        cout << "Multiplication not possible for the given matrices\n";
        return;
    }
    else
    {
        int **matrix_temp = (int **)malloc(row1 * sizeof(int *));
        for (int i = 0; i < row1; i++)
        {
            matrix_temp[i] = (int *)malloc(column2 * sizeof(int));
        }

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                matrix_temp[i][j] = 0;
            }
        }

        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                for (int k = 0; k < column1; k++)
                {
                    matrix_temp[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        *multiplied_matrix = matrix_temp;
    }
}

int main()
{
    int **matrix1;
    int **matrix2;
    int **multiply_matrix;
    cout << "Enter first Matrix: \n";
    create_matrix(&matrix1, &row1, &column1);
    cout << "Enter second Matrix: \n";
    create_matrix(&matrix2, &row2, &column2);
    cout << "matrix1: \n";
    display(matrix1, row1, column1);
    cout << "matrix2: \n";
    display(matrix2, row2, column2);
    cout << "Multiplied matrix: \n";
    multiply(matrix1, matrix2, row1, column1, row2, column2, &multiply_matrix);
    display(multiply_matrix, row1, column2);
}