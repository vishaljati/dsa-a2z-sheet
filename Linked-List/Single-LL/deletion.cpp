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
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
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
Node *deleteKthNode(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    int len = 0;

    Node *mover = head;
    while (mover)
    {
        len++;
        mover = mover->next;
    }
    // invalid node
    if (k > len)
        return nullptr;
    // delete head
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // delete tail
    if (k == len)
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

        return head;
    }

    Node* prev = head;
    Node* temp=head->next;
    int l=2;
    while(temp && l!=k){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
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
    vector<int> arr = {1,2,3,4,5};
    Node *head = array2LL(arr);
    traversal(head);

    cout << "---Deleting Kth Node---" << endl;

    Node* newHead = deletebyvalue(head, 5);
    traversal(newHead);

    return 0;
}