#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};


class IterativePreOrder{
    public:
    stack<Node*> st;
    IterativePreOrder(Node* root){
        stack<Node*> st;
        if(root)
            st.push(root);
    }

    bool hasNext(){
        return st.size() != 0;
    }

    Node* getNext(){
        Node* top = st.top();
        st.pop();
        st.push(top->right);
        st.push(top->left);
        return top;
    }
};

Node* insert(Node* root, int k){
    if(root == NULL) 
        return new Node(k);
    if(k <= root->data)
        root->left = insert(root->left,k);
    else
        root->right = insert(root->right,k);
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    while(n--){
        int x;
        cin>>x;
        root = insert(root,x);
    }
    IterativePreOrder *ip = new IterativePreOrder(root);
    while(ip.hasNext()){
        Node* nextNode = ip.getNext();
        cout<<nextNode->data<<" ";
    }
    delete ip;
}
