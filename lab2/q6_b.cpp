#include <iostream>
using namespace std;

int main()
{
    cout << "enter number of rows: ";
    int rows;
    cin >> rows;
    cout << "enter number of columns: ";
    int cols;
    cin >> cols;

    int a1[rows][cols];
    cout << "Matrix 1\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "enter element of row " << i+1 << " and  column " << j+1 <<" : ";
            cin >> a1[i][j];
        }
    }
    int a2[rows][cols];
    cout << "Matrix 2\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "enter element of row " << i+1 << " and  column " << j+1 <<" : ";
            cin >> a2[i][j];
        }
    }
    int c1 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a1[i][j]!=0)
            {
                c1++;
            }
        }
    }
    int c2 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a2[i][j]!=0)
            {
                c2++;
            }
        }
    }
    int s1[c1][3];
    int s2[c2][3];
    int check1 = 0;
    for (int i = 0;  i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(a1[i][j]!=0)
            {
                s1[check1][0] = i;
                s1[check1][1] = j;
                s1[check1][2] = a1[i][j];
                check1++;
            }
        }
    }
    int check2 = 0;
    for (int i = 0;  i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(a2[i][j]!=0)
            {
                s2[check2][0] = i;
                s2[check2][1] = j;
                s2[check2][2] = a2[i][j];
                check2++;
            }
        }
    }
    cout << "Sparse matrix1:\n";
    for (int i = 0;  i < c1; i++)
    {
        cout << s1[i][0] << "   " << s1[i][1] << "  "<<s1[i][2]<<endl;
    }
    cout << "Sparse matrix2:\n";
    for (int i = 0;  i < c2; i++)
    {
        cout << s2[i][0] << "   " << s2[i][1] << "  "<<s2[i][2]<<endl;
    }
    int sum[c1+c2][3];
    int sum_count = 0;
    int s2count = 0;
    for (int i = 0;  i < c1; i++)
    {
        if (s1[i][0] == s2[s2count][0])
        {
            if (s1[i][1] == s2[s2count][1])
            {
                sum[sum_count][0] = s1[i][0];
                sum[sum_count][1] = s1[i][1];
                sum[sum_count][2] = s1[i][2] + s2[s2count][2];
                sum_count++;
                s2count++;
            }
            else
            {

            }
        }
        else
        {
            sum[sum_count][0] = s1[i][0];
            sum[sum_count][1] = s1[i][1];
            sum[sum_count][2] = s1[i][2];
            sum_count++;
            s2count++;
        }
    }
    int sum_count2 = 0;
    for (int i = 0; i < c2; i++)
    {
        if (s2[i][0]==sum[sum_count2][0])
        {
            if(s2[i][1]==sum[sum_count2][1])
            {
                sum_count2++;
            }
            else
            {
                sum_count++;
                sum[sum_count][0] = s2[i][0];
                sum[sum_count][1] = s2[i][1];
                sum[sum_count][2] = s2[i][2];
                sum_count2++;
            }
        }
        {
            
        }
    }
    cout << "Sum of 2 matrices: \n";
    for (int i = 0;  i < sum_count; i++)
    {
        cout << sum[i][0] << "   " << sum[i][1] << "  "<<sum[i][2]<<endl;
    }

}