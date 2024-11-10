#include <iostream>
using namespace std;

int main()
{
    int array[3][3] = {{0,1,2}, {0,0,5}, {0,3,0}};
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j ++)
        {
            if (array[i][j] != 0)
            {
                count ++;
            }
        }
    }
    // cout << count;
    int sparse[count][3];
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0 ; j < 3; j++)
        {
            if (array[i][j]!=0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = array[i][j];
                cout << array[i][j] << endl;
                k++;
            }
        }
    }
    int check = 0;
    for (int i= 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i ==  sparse[check][0] && j == sparse[check][1])
            {
                cout << sparse[check][2] << "   ";
                check++;
            }
            else
            {
                cout << 0 << "  ";
            }
        }
        cout << endl;
        // check++;
    }
    // for (int i = 0 ; i < count; i ++)
    // {
    //     // for (int j = 0; j < 3; j++)
        
    //         cout << sparse[i][0]<<" "<<sparse[i][1]<<"  "<<sparse[i][2]<<endl;
        
    // }
}