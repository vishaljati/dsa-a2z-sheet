#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    ListNode dummy(0);
    ListNode *ansHead = &dummy;
    ListNode *temp = head;

    int index = 1;
    while (temp != nullptr)
    {
        if (index % 2 != 0)
        {
            ansHead->next = new ListNode(temp->val);
        }
        index++;
    }
    index = 1;
    while (temp != nullptr)
    {
        if (index % 2 == 0)
        {
            ansHead->next = new ListNode(temp->val);
        }
        ansHead = ansHead->next;
        temp = temp->next;
        index++;
    }
    return dummy.next;
}
ListNode *arr2LL(vector<int>& arr){
    if (arr.empty()) return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;

    for (int i = 1; i < arr.size(); i++){
        ListNode *newNode = new ListNode(arr[i]);
        mover->next = newNode;
        mover = mover->next;
    }

    return head;
}

void traversal(ListNode *head){
    ListNode *temp=head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    cout<<"---Double LL---"<<endl;
    ListNode *head=arr2LL(arr);
    traversal(head);

    ListNode *newHead=oddEvenList(head);
    traversal(newHead);
    
    
    return 0;
}