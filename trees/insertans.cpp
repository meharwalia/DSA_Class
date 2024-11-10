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

void inserted(node*& root, int key) {
    // Create a new Node containing the new element
    node* newnode = new node;
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    // Traverses downward path to search where the new node to be inserted
    node* x = root;
    node* y = NULL;
    
    while (x != NULL) {
        y = x;
        if (key < x->data)
            x = x->left;
        else if (key > x->data)
            x = x->right;
        else {
            // Key already exists, do not insert and return
            cout << "Node with key " << key << " already exists. Insertion not performed." << endl;
            delete newnode; // Avoid memory leak by deleting the unused node
            return;
        }
    }
    
    // If the root is NULL, new node is the root node
    if (y == NULL) {
        root = newnode;
        cout << "Node with key " << key << " inserted as the root." << endl;
    }
    else if (key < y->data) {
        y->left = newnode;
        cout << "Node with key " << key << " inserted to the left of " << y->data << "." << endl;
    }
    else {
        y->right = newnode;
        cout << "Node with key " << key << " inserted to the right of " << y->data << "." << endl;
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
    inserted(root, 12);
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