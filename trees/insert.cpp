#include <iostream>
#include <vector>
#include <queue>
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

void inserted(node *&root, int k)
{
    node * temp = new node;
    temp->data = k;
    temp->left = NULL;
    temp->right = NULL;
    node *previous = NULL;
    node *curr = root;
    while(curr!=NULL && curr->data != k)
    {
        previous = curr;
        if (curr->data > k)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (curr != previous && curr->data != k)
    {
        if (k > previous->data)
        {
            previous->right = temp;
            cout << "Node inserted\n";
        }
        else if (k < previous->data)
        {
            previous->left = temp;
            cout << "Node inserted\n";
        }
    }
    else
    {
        if (curr == previous)
        {
            root = temp;
        }
        else
        {
            cout << "Node already present\n";
            delete temp;
        }
    }

}

vector <vector <int>> bfs(node *root)
{
    queue <node *> inter;
    vector <vector <int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    inter.push(root);
    while (!inter.empty())
    {
        vector <int> temp;
        int x = inter.size();
        for (int i = 0; i < x; i++)
        {
            node *y = NULL;
            y = inter.front();
            inter.pop();
            temp.push_back(y->data);
            if (y->left != NULL)
            {
                inter.push(y->left);
            }
            if (y->right != NULL)
            {
                inter.push(y->right);
            }

        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    node * root = NULL;
    root = create(); 
    vector <vector <int>> ans = bfs(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "     ";
        }
        cout << endl;
    }
    inserted(root, 8);
    cout << "After insertion\n";
    ans = bfs(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "     ";
        }
        cout << endl;
    }
}