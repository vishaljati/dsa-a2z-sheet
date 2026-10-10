#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }

    Node(int val, Node *nxt, Node *prv){
        data = val;
        next = nxt;
        prev = prv;
    }
};

Node *arr2LL(vector<int>& arr){
    if (arr.empty()) return nullptr;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++){
        Node *newNode = new Node(arr[i]);
        mover->next = newNode;
        newNode->prev = mover;
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

bool search(Node *head , int val){
    Node *temp=head;
    while(temp){
        if(temp->data==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    cout<<"---Double LL---"<<endl;
    Node *head=arr2LL(arr);
    traversal(head);
    bool isPresent=search(head,6);
    if (isPresent)
    {
        cout<<"Present";
    }
    else{
        cout<<"Absent";
    }
    
    return 0;
}