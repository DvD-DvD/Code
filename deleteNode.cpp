#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool deleteThis(Node* root){
    if(root->data == 0){
        return true;
    }
    return false;
}

vector<Node*> forest;



void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node* f = q.front();
            q.pop();
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
        cout<<endl;
    }
}


Node* deleteNode(Node* root){
    if(root == NULL){
        return root;
    }
    root->left = deleteNode(root->left);
    root->right = deleteNode(root->right);
    if(deleteThis(root)){
        if(root->left)
            forest.push_back(root->left);
        if(root->right)
            forest.push_back(root->right);
        return NULL;
    }
    return root;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(0);
    root->left->left = new Node(0);
    root->left->right = new Node(2);
    root->left->right->left = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(0);
    root->right->right->right = new Node(0);
    root->right->right->right->left = new Node(7);
    root->right->right->right->right = new Node(8);
    // levelOrder(root);
    deleteNode(root);
    if(!deleteThis(root)){
        forest.push_back(root);
    }
    for(int i=0;i<forest.size();i++){
        cout<<"Chettu\n";
        levelOrder(forest[i]);
        cout<<endl;
    }

}
