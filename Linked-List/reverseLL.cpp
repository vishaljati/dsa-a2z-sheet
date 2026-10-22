#include <iostream>
#include <vector>
using namespace std;
// REVERSE SINGLE LL
class Node
{
public:
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
        mover = mover->next;
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

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = nullptr;
    Node *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
int main()
{
    // Test case 1
    cout << "---Test Case 1---" << endl;
    vector<int> arr1 = {10, 20, 30, 40};
    Node *head1 = arr2LL(arr1);
    traversal(head1);
    Node *newHead1 = reverse(head1);
    traversal(newHead1);
    cout << "-----------------------------" << endl;

    // Test Case 2
    cout << "---Test Case 2---" << endl;
    vector<int> arr2 = {20};
    Node *head2 = arr2LL(arr2);
    traversal(head2);
    Node *newHead2 = reverse(head2);
    traversal(newHead2);
    cout << "-----------------------------" << endl;

    // Test Case 3
    cout << "---Test Case 3---" << endl;
    vector<int> arr3 = {};
    Node *head3 = arr2LL(arr3);
    traversal(head3);
    Node *newHead3 = reverse(head3);;
    traversal(newHead3);
    cout << "-----------------------------" << endl;
    return 0;
}