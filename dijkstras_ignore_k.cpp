#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int> > &adj,int start,int end){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > pq;
    vector
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}