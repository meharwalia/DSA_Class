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
}