#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int,int> const &left, pair<int,int> const &right){
        return (left.first > right.first);
    }
};

int PrimMST(vector<vector<pair<int,int> > > &adj){
    int n = adj.size();
    vector<bool> MST(n,false);
    vector<int> key (n,INT_MAX);
    key[0] = 0;
    int cost = 0;

    for(int count=0;count<n;count++){
        int u=-1;
        for(int i=0;i<n;i++){
            if(MST[i] == false && (u==-1 || key[i] < key[u])){
                u=i;
            }
        }
        cost += key[u];
        MST[u] = true;
        for(int i=0;i<adj[u].size();i++){
            pair<int,int> p = adj[u][i];
            int v = p.first;
            int w = p.second;
            key[v] = min(key[v],w);
        }
    }
    return cost;
}



int PrimMST_heap(vector<vector<pair<int,int> > > &adj){
    int n = adj.size();
    vector<bool> vis (n,false);
    priority_queue< pair<int,int>, vector<pair<int,int> >, compare>pq;
    pq.push({0,0});
    int ans = 0;

    for(int count=0;count<n;count++){        
        while(!pq.empty() && vis[pq.top().second]){
            pq.pop();
        }

        pair<int,int> p = pq.top();
        pq.pop();
        ans += p.first;
        vis[p.second] = true;

        for(int i=0;i<adj[p.second].size();i++){
            pq.push({adj[p.second][i].second,adj[p.second][i].first});
        }

    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > adj(n);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    // cout<<PrimMST(adj)<<endl;
    cout<<PrimMST_heap(adj)<<endl;

}