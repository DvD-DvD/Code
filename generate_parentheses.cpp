#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    void print(vector<string> &ans, string s, int ind, int n, int open, int close){
        // cout << n << endl;
        if(ind == 2*n){
            ans.push_back(s);
            cout<<s<<endl;
        }
        
        if(open < n){
            s[ind] = '(';
            print(ans,s,ind+1,n,open + 1,close);
        }
        
        if(open > close){
            s[ind] = ')';
            print(ans,s,ind+1,n,open,close+1);

        }           
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s(2*n,'x');
        print(ans,s,0,n,0,0);
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution ob;
    vector<string> ans = ob.generateParenthesis(n);
    for (int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }
}