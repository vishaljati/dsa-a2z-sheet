#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }

    Node(int val, Node *nxt, Node *prv)
    {
        data = val;
        next = nxt;
        prev = prv;
    }
};

Node *arr2LL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        mover->next = newNode;
        newNode->prev = mover;
        mover = mover->next;
    }

    return head;
}

void traversal(Node *head)
{
    Node *temp = head;
    cout << "NULL <-> ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *insertAtHead(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }
    Node *temp = head;
    head = new Node(val, temp, nullptr);
    temp->prev = head;

    return head;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }
    if (head->next == nullptr)
    {
        Node *temp = head;
        Node *newNode = new Node(val, temp, nullptr);
        temp->prev = newNode;
        head = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}

Node *insertBeforeKthNode(Node *head, int k, int val)
{
    if (head == nullptr || k <= 0)
    {
        return head;
    }
    if (k == 1)
    {
        Node *newNode = new Node(val, head, nullptr);
        head->prev = newNode;
        return newNode;
    }
    Node *curr = head;
    for (int i = 1; i < k - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    if (curr == nullptr || curr->next == nullptr)
    {
        return head;
    }

    Node *newNode = new Node(val, curr->next, curr);
    curr->next->prev = newNode;
    curr->next = newNode;

    return head;
}


Node* insertBeforeNode(Node* head, int node, int val)
{
    if (head == nullptr) {
        return head;
    }

    if (head->data == node) {
        Node* newNode = new Node(val, head, nullptr);
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != node) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return head;
    }

    Node* newNode = new Node(val, temp, temp->prev);
    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}


int main()
{
    // Test case 1
    cout << "---Test Case 1---" << endl;
    vector<int> arr1 = {10, 20, 30, 40};
    Node *head1 = arr2LL(arr1);
    traversal(head1);
    Node *newHead1 = insertBeforeNode(head1, 30, 99);
    traversal(newHead1);
    cout << "-----------------------------" << endl;

    // Test Case 2
    cout << "---Test Case 2---" << endl;
    vector<int> arr2 = {20};
    Node *head2 = arr2LL(arr2);
    traversal(head2);
    Node *newHead2 = insertBeforeNode(head2, 20 , 99);
    traversal(newHead2);
    cout << "-----------------------------" << endl;

    // Test Case 3
    cout << "---Test Case 3---" << endl;
    vector<int> arr3 = {10,20};
    Node *head3 = arr2LL(arr3);
    traversal(head3);
    Node *newHead3 = insertBeforeNode(head3, 10 , 99);
    traversal(newHead3);
    cout << "-----------------------------" << endl;
    return 0;
}