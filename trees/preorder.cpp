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
    node *new_node = new node;
    int x;
    cout << "Enter data (-1 for no new node): ";
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    new_node->data = x;
    cout << "Enter Left node of " << x << " : ";
    new_node->left = create();
    cout << "Enter Right node of " << x << " : ";
    new_node->right = create();
    return new_node;
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    cout << root->data << "     ";
    preorder(root->right);
}

int main()
{
    node *root = NULL;
    root = create();
    preorder(root);
    return 0;
}