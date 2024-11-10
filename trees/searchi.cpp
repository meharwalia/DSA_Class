#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *create()
{
    node *temp = new node;
    int x;
    cout << "Enter data for node(-1 for no new node): ";
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    temp->data = x;
    cout << "Enter left for " << x << " : ";
    temp->left = create();
    cout << "Enter right for " << x << " : ";
    temp->right = create();
    return temp;
}

bool search(node *root, int a)
{
    while (root != NULL && root->data != a)
    {
        if (a < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root = create();
    cout << "enter number to be searched for: ";
    int x;
    cin >> x;
    if (search(root, x))
    {
        cout << "Found!!\n";
        return 0;
    }
    cout << "Not found \n";
    return 1;
}