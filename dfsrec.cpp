#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int > > adj,vector<bool> &visited,int s){
    visited[s] = true;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]] == false){
            dfs(adj,visited,adj[s][i]);
        }
    }
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int > > adj(v+1);
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v2);
    }
    vector<bool> visited(v+1,false);
    dfs(adj,visited,1);
    return 0;
}