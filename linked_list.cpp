#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

Node* reverse_itr(Node* head){
    Node* prev = NULL;
    while(head != NULL){
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}
       
1 2 3 4 5

Node* reverse_recur(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    Node* temp = reverse_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}


void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    Node* head = NULL,*prev = NULL;;
    while(n--){
        int d;
        cin>>d;
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            prev = head;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
    }
    // print(head);
    // head = reverse_itr(head);
    head = reverse_recur(head);
    print(head);
}