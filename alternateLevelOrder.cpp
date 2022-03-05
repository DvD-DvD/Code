#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right; 
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelInsert(Node* root,vector<int> &vals){
    int it = 1;
    int n = vals.size();
    queue<Node*> q;
    q.push(root);
    while(it<n & !q.empty()){
        int n = q.size();
        while(n--){
            Node* curr = q.front();
            q.pop();
            if(curr->left == NULL){
                curr->left = new Node(vals[it++]);
            }
            q.push(curr->left);
            if(curr->right == NULL){
                curr->right = new Node(vals[it++]);
            }
            q.push(curr->right);
        }
    }

}

void getOddLevelInorder(vector<int> &in, Node* root,int level){
    if(root == NULL){
        return;
    }
    getOddLevelInorder(in,root->left,level+1);
    if(level%2 == 1){
        in.push_back(root->val);
    }
    getOddLevelInorder(in,root->right,level+1);
}

int itr = 0;
void reverseAlternateLevel(Node* root,vector<int> &in,int level){
    if(root == NULL) return;
    reverseAlternateLevel(root->left,in,level+1);
    if(level%2 == 1){
        root->val = in[itr++];
    }
    reverseAlternateLevel(root->right,in,level+1);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<(root->val)<<" ";
    inorder(root->right);
}

int main(){
    int n;
    cin>>n;
    vector<int> vals(n);
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    Node* root = new Node(vals[0]);
    levelInsert(root,vals);
    vector<int> in;
    getOddLevelInorder(in,root,0);
    reverse(in.begin(),in.end());

    reverseAlternateLevel(root,in,0);
    inorder(root);
    
}