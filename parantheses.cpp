#include<bits/stdc++.h>
using namespace std;

void generateParentheses(int n,int idx,int open,int close,string &s){
    if(idx == n){
        cout<<s<<endl;
    }
    if(open < n/2){
        s.push_back('(');
        generateParentheses(n,idx+1,open+1,close,s);
        s.pop_back();
    }
    if(close < open){
        s.push_back(')');
        generateParentheses(n,idx+1,open,close+1,s);
        s.pop_back();
    }
}


int main(){
    int n = 6;
    string s;
    generateParentheses(n,0,0,0,s);
    
}