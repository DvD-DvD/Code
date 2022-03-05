#include<bits/stdc++.h>
using namespace std;

int counter = 0;

void fillpool(vector<vector<int> > &adj, vector<int> &vis,unordered_set<char> &pool,int u,string s){
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(vis[v] == 0){
            vis[v] = 1;
            fillpool(adj,vis,pool,v,s);
        }
    }
    if(pool.find(s[u-1]) == pool.end()){
        cout<<u<<endl;
        counter++;
    }
    pool.insert(s[u-1]);
}

int main(){
    int n;
    string s;
    int m;
    cin>>n>>m>>s;

    vector<vector<int> > adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    vis[1] = 1;
    unordered_set<char> pool;
    fillpool(adj,vis,pool,1,s);
    cout<<"ans "<< counter<<endl;
}