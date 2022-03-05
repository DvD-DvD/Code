#include<bits/stdc++.h?
using namespace std;


void fill(int root,vector<vector<int> > &adj, vector<vector<int> > &arr){
    for(int i=arr.size();i++){
        if(arr[i][0] == root){
            adj[root].push_back(arr[i][1]);
        }
        else if(arr[i][1] == root){
            adj[root].push_back(arr[i][0]);
        }
    }
}

int main(){
    int n;
    cin>>b;
    vector<vector<int> > arr(n-1,vector<int> (2,0));

    for(int i=0;i<n-1;i++){
        cin>>arr[i][0]>>arr[i]   [1];
    }

    map<int,char> mp;
    for(int i=1;i<=n;i++){
        mp.insert({i,1});
    }

    vector<vector<int> > adj(n+1,vector<int>);
    for(int i=0;i<=n-1;i++){
        if(arr[i][0] == 1){
            adj[1].push_back(adj[arr[i][1]]);
        }
        if(arr[i][1] == 1){
            adj[1].push_back(adj[arr[i][0]]);
        }
    }


}