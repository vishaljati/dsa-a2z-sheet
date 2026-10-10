#include <iostream>
#include <bits/stdc++.h>
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

Node *deletefromhead(Node *head)
{
    if (head == nullptr ||head->next ==nullptr )
    {
        return nullptr;
    }
    Node *temp = head;
    
    head = head->next;
    
    temp->next=nullptr;
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
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* deleteKthNode(Node* head, int k)
{
    if (head == nullptr || k <= 0)
        return head;

    // Delete the head node
    if (k == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = head;

    // Reach the (k-1)th node
    for (int i = 1; i < k - 1 && prev != nullptr; i++)
    {
        prev = prev->next;
    }

    // k is greater than the list length
    if (prev == nullptr || prev->next == nullptr)
        return head;

    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;

    return head;
}

Node *deletebyvalue(Node*head ,int value){
    if(head==nullptr) return head;
    Node *temp=head;
    Node *prev=nullptr;
    while(temp && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==nullptr) return head;
    if(temp->data==value){
        prev->next=temp->next;
        delete temp;
    }
    return head;
}

int main()
{
    cout << "---Linked List---" << endl;
    int k;
    vector<int> arr = {1};
    Node *head = array2LL(arr);
    traversal(head);

    cout << "---Deleting head Node---" << endl;

    Node* newHead = deletefromhead(head);
    traversal(newHead);

    return 0;
}