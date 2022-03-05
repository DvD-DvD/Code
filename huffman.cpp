#include<bits/stdc++.h>
using namespace std;

struct Node{
	int freq;
	char ch;
	Node* left;
	Node* right;
	
    Node(int f,int c){
        freq = f;
        ch = c;
        left = NULL;
        right = NULL;
        
    }
};

struct compare{
    bool operator()(struct Node* left, struct Node* right){
        return (left->freq > right->freq);
		
    }
};

class Solution{
    public:
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    
		    priority_queue<struct Node*,vector<struct Node*>,compare> heap;
	        for(int i=0;i<n;i++){
	            heap.push(new Node(f[i],s[i]));
	        }
	        
	        while(heap.size() != 1){
	            struct Node* left = heap.top();
	            heap.pop();
	            struct Node* right = heap.top();
	            heap.pop();
	            
	            struct Node* parent = new Node(left->freq + right->freq,'$');
	            parent->left = left;
	            parent->right = right;
	            heap.push(parent);
	        }
	        
	        struct Node* root = heap.top();
	        unordered_map<char,string> mp;

	        fillValues(root,"",mp);
	        
	        vector<string> ans;
	        for(int i=0;i<n;i++){
				cout << s[i] << " " << mp[s[i]] << endl;
				ans.push_back(mp[s[i]]);
	        }
	        return ans;
	        
		}
		
		void fillValues(struct Node* root,string str,unordered_map<char,string> &mp){
		    if(root == NULL){
				return;
		    }
			// cout << "f is " << root->freq << " ";
			if(root->ch != '$'){
		        mp.insert({root->ch,str});
		    }
		    
			fillValues(root->left, str + "0", mp);
			fillValues(root->right, str + "1", mp);
			
		}
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> f(n);
        for (int i = 0; i < n;i++){
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(s, f, n);
        for(auto i: ans){
            cout << i << "\n";
        }
        cout << endl;
    }
}