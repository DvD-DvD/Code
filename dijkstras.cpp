class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(n,INT_MAX);
        dist[S] = 0;
        priority_queue<pi,vector<pi>,greater<pi> > pq;
        
        pq.push({0,S});
        while(!pq.empty()){
            pi p = pq.top();
            pq.pop();
            int u = p.second;
            int w = p.first;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i][0];
                if(dist[v] > w + adj[u][i][1]){
                    dist[v] = w + adj[u][i][1];
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
        
        
    }
};