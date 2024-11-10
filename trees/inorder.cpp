#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
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

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
        inorder(root->left);
        cout << root->data << "   ";
        inorder(root->right);
}

int main()
{
    node *root = NULL; 
    root = create();
    inorder(root);
    return 0;
}