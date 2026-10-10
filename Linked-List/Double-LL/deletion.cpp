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


Node* deletefromhead(Node* head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    temp->next = nullptr;

    delete temp;
    return head;
}

Node *deletefromtail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next=nullptr;
    temp->prev=nullptr;
    
    delete temp;

    return head;
}


Node* deleteKthNode(Node* head, int k)
{
    if (head == nullptr || k <= 0)
        return head;

    Node* curr = head;

    // Reach the k-th node (1-based indexing)
    for (int i = 1; i < k && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    // k is greater than the list length
    if (curr == nullptr)
        return head;

    // Update the previous node's next pointer
    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    else
        head = curr->next;  // Deleting the head

    // Update the next node's previous pointer
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;

    delete curr;

    return head;
}

Node* deleteNode(Node* head, int value)
{
    if (head == nullptr)
        return head;

    Node* curr = head;

    // Find the node containing the value
    while (curr != nullptr && curr->data != value)
    {
        curr = curr->next;
    }

    // Value not found
    if (curr == nullptr)
        return head;

    // Update previous node
    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    else
        head = curr->next;

    // Update next node
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;

    delete curr;

    return head;
}


int main()
{
    vector<int> arr = {1,2,3,4};
    cout << "---Double LL---" << endl;
    Node *head = arr2LL(arr);
    traversal(head);
    cout<<"---After Deletion---"<<endl;
    Node *newHead=deleteNode(head,3);
    traversal(newHead);

    return 0;
}