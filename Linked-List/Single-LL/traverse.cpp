
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int val, Node *nxt)
    {
        data = val;
        next = nxt;
    }
};

Node *array2LL(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void traversal(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    cout << "---Linked List---" << endl;

    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = array2LL(arr);
    traversal(head);

    return 0;
}