#include <iostream>
#include <stack>
using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

Node* findInOrderSuccessor( Node *inputNode,Node* root){ 
  stack<Node*> s;
  Node* currNode = root; 
  Node* prev = NULL;
  while(currNode != NULL || !s.empty()){    
    while(currNode != NULL){
       s.push(currNode);
       currNode = currNode->left;
    }
    currNode = s.top();
    s.pop();
    if(prev && prev == inputNode) return currNode;
    prev = currNode;
    currNode = currNode->right;
  }
}

void InOrderSuccessor(bool* found,Node* root,Node* inp,Node** ans){
    if(root == NULL){
        return;
    }
    
    if(root == inp){
        *found = true;
        return;
    }
    InOrderSuccessor(found,root->left,inp,ans);
    if(found){
        *ans = root;
        return;
    }
    InOrderSuccessor(found,root->right,inp,ans);


}

int main() {
  
  //cin>>n;
  Node* root = NULL;
  Node* check = NULL;
  int arr[7] = {20,9,5,12,11,14,25};
  for(int i=0;i<7;i++){
    int x = arr[i];
    root = insert(root,x);
  }
  check = getNodeByKey(root,12);
//   Node* ans = findInOrderSuccessor(check,root);
Node* ans = NULL;
bool flag = false;
InOrderSuccessor(flag,root,check,*ans);
cout<<ans->key;
  
  return 0;
}
