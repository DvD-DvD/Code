#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

void permutation(vector<int> &v,vector<int> &perm,vector<bool> &vis){
    int n = v.size();
    if(perm.size() == n){
        ans.push_back(perm);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            perm.push_back(v[i]);
            permutation(v,perm,vis);
            perm.pop_back();
            vis[i] = false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> perm;
    vector<bool> vis(n,false);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i] = x;
    }

    permutation(v,perm,vis);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}