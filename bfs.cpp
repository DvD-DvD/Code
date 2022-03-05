#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int > > adj,int s){
    vector<bool> visited(adj.size(),false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int j = q.front();
        
        cout<<j<<" ";
        q.pop();
        for(int i=0;i<adj[j].size();i++){
            if(!visited[adj[j][i]]){
                q.push(adj[j][i]);
                visited[adj[j][i]] = true;
            }
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
    bfs(adj,1);
    return 0;
}