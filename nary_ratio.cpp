#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    vector<Node*> children;
    Node(int d){
        data = d;
    }
};

pair<int,int> printRatio(Node* root){
    if(root->children.size() == 0){
        cout<<root->val<<1<<endl;
        return {1,0};    
    }
    int child = 0, levels = 0;
    for(int i=0;i<root->children.size();i++){
        pair<int,int> p = printRatio(root->children[i]);
        child += p.second;
        levels = max(levels,p.first);
    }
    return {1+levels,child};
}


int main(){

}