#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        int n,c;
        cin>>n>>c;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1; 
        }
        if()
        for(int i=0;i<c;i++){
            next_permutation(v.begin(),v.end());
        }
        for(int i=0;i<n;i++){
            cout<<v[i]; 
        }
        cout<<endl;
        
    }
}