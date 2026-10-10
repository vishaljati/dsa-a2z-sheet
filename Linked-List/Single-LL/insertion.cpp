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

void traversal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            cout << temp->data << endl;
        }
        else
        {
            cout << temp->data << " -> ";
        }

        temp = temp->next;
    }
}

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

int len(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node *insertionfromhead(Node *head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;

    return head;
}

Node *insertfromtail(Node *head, int val)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
}

Node *insertfromKthPosition(Node *head, int val, int k)
{
    int length = len(head);
    if (k > length + 1)
    {
        return nullptr;
    }

    Node *temp = head;

    // k=1 :head
    if (k == 1)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    for (int i = 2; i < k; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node *insertbeforeX(Node *head, int x, int val)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
        return head;
    Node *newNode = new Node(val, temp);
    prev->next = newNode;

    return head;
}

int main()
{
    cout << "---Linked List---" << endl;
    vector<int> arr = {1, 2, 3};
    Node *head = array2LL(arr);
    Node *newHead = insertbeforeX(head, 7, 5);
    traversal(newHead);

    return 0;
}