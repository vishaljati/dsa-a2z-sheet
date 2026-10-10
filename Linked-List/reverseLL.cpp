#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node(int val, Node *nxt){
        data = val;
        next = nxt;
    
    }
};

Node *arr2LL(vector<int>& arr){
    if (arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node *newNode = new Node(arr[i]);
        mover->next = newNode;
        mover = mover->next;
    }

    return head;
}

void traversal(Node *head){
    Node *temp=head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node *reverse(Node *head){
    Node *prev=nullptr;
    Node *curr=head;

    while(curr!=nullptr){
        Node *nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    cout<<"---Double LL---"<<endl;
    Node *head=arr2LL(arr);
    traversal(head);

    Node *newHead=reverse(head);
    traversal(newHead);
    
    
    return 0;
}