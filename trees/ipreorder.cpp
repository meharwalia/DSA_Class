#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

node *create()
{
    node *root = new node;
    int x;
    cout << "Enter data(-1 for no new node): ";
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    root->data = x;
    cout << "Enter left node for " << x << " : ";
    root->left = create();
    cout << "Enter right node for " << x << " : ";
    root->right = create();
    return root;
}

void preorder(node *root)
{
    stack<node *> temp;
    if (root == NULL)
    {
        return;
    }
    temp.push(root);
    while(!temp.empty())
    {
        node *y = temp.top();
        temp.pop();
        cout << y->data << "    ";
        if (y->right != NULL)
        {
            temp.push(y->right);
        }
        if (y->left != NULL)
        {
            temp.push(y->left);
        }
    }
}

int main()
{
    node *root = create();
    preorder(root);
}