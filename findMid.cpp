#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next;
    Node(int d){
        val = d;
        next = NULL;
    }
};




Node* findMid(Node* head){
    if(head == NULL){
        return head;
    }
    Node* fast = head, *slow = head;
    while( fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->val;
        head = head->next;
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    Node* head = NULL,*prev = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* temp = new Node(x);
        if(head == NULL){
            head = temp;
            prev = temp;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
    }
    print(head);
    Node* mid = findMid(head);
    cout<<mid->val<<endl;

}