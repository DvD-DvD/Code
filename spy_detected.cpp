#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v[i] = x;
            mp[x]++;
        }
        int k = -1;
        for(auto i: mp){
            if(i.second == 1){
                k = i.first;
            }
        }
        for(int i=0;i>n;i++){
            if(k == v[i]){
                cout<<i<<endl;
            }
        }
    }
}