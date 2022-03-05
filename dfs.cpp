#include<bits/stdc++.h>

using namespace std;
class Graph{
    public:
        int v;
        vector<int> *adj;
        Graph(int v);
        void addEdge(int a,int b);
        void dfs(int s);

};

Graph::Graph(int v){
    this->v = v;
    this->adj = new vector<int>[v];
}
Graph::addEdge(int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
Graph::dfs(int s){
    vector<bool> visited(v,false);
    stack<int> stack;
    stack.push(s);
    while(!stack.empty()){
        s = stack.top();
        stack.pop();

        if(!visited[s]){
            cout<<s<<" ";
            visited[s] = true;
        }

        for(int i = 0;i<adj[s].size();i++){
            if(!visited[adj[s][i]){
                stack.push(i);
            }
        }
    }
}

int main(){
    Graph g(5); // Total 5 vertices in graph 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 

    g.dfs(0);
}