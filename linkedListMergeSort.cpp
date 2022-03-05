#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

Node* findMid(Node* head){
    if(head == NULL){
        return head;
    }
    Node* fast = head, *slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* head = NULL, *temp = NULL;

    while(head1 && head2){
        if(head1->val <= head2->val){
            if(head == NULL){
                head = head1;
                temp = head1;
                head1 = head1->next;
            }
            else{
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                temp = head2;
                head2 = head2->next;
            }
            else{
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }
    }
    if(head1){
        temp->next = head1;
    }
    if(head2){
        temp->next = head2;
    }
    return head;
}


Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = findMid(head);
    Node* right = mid->next;
    mid->next = NULL;
    Node* left = head;

    // cout<<mid->val<<endl;
    left = mergeSort(left);
    right = mergeSort(right);
    head = merge(left,right);
    return head;
}



void print(Node* head){
    while(head){
        cout<<head->val<<" ";
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
    // print(head);
    head = mergeSort(head);
    print(head);
}