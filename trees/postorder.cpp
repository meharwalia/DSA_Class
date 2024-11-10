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

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "   ";
}

int main()
{
    node *root = NULL; 
    root = create();
    postorder(root);
    return 0;
}