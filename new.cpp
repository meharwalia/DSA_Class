#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

int main()
{
    node *l1 = NULL;
    node *l2 = NULL;
    for (int i = 0; i < 6; i += 2)
    {
        node *temp = new node;
        temp->value = i;
        temp->next = NULL;
        node *temp2 = l1;
        if (l1 == NULL)
        {
            l1 = temp;
        }
        else
        {
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }
    for (int i = 1; i < 10; i += 2)
    {
        node *temp = new node;
        temp->value = i;
        temp->next = NULL;
        node *temp2 = l2;
        if (l2 == NULL)
        {
            l2 = temp;
        }
        else
        {
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }

    node *temp2 = l1;
    cout << "L1\n";
    while (temp2 != NULL)
    {
        cout << temp2->value << endl;
        temp2 = temp2->next;
    }
    temp2 = l2;
    cout << "L2\n";
    while (temp2 != NULL)
    {
        cout << temp2->value << endl;
        temp2 = temp2->next;
    }

    node *current1 = l2;
    node *current2 = l1;
    node *prev = current1;
    while (current2!=NULL)
    {
        if (current2->value > current1->value)
        {
            prev = current1;
            current1 = current1->next;
        }
        else
        {
            if (prev == current1)
            {
                node *temp = current2;
                current2 = current2->next;
                temp->next = current1;
                l2 = temp;
                prev = temp;
            }
            else
            {
                node *temp = current2;
                current2 = current2->next;
                temp->next = current1;
                prev->next = temp;
                prev = temp;
            }
        }
    }
    temp2 = l2;
    cout << "Merged L2\n";
    while (temp2 != NULL)
    {
        cout << temp2->value << endl;
        temp2 = temp2->next;
    }


}