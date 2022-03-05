#include <bits/stdc++.h>
using namespace std;


int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,1,-1,0,-1,1};

void solve(vector<vector<int> > &arr,int i, int j,int steps,int &ans,int di,int dj,vector<pair<int,int> > &path,vector<vector<pair<int,int> > > &sol){
    int n = arr.size();
    int m = arr[0].size();
    if(arr[i][j] == 0 ||  i < 0 || j < 0 || i >= n || j >= m){
        return;
    }
    if(i == di && j == dj){
        sol.push_back(path);
        ans = min(ans,steps);
        return;
    }
    
    for(int p=0;p<8;p++){
        path.push_back({i+dx[p],j+dy[p]});
        solve(arr,i + dx[p], j+ dy[p],steps+1,ans,di,dj,path,sol);
        path.pop_back();
    }
    
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,b;
        cin>>n>>m>>b;
        vector<vector<int> > arr(n,vector<int> (m,1));
        int si,sj,di,dj;
        cin>>si>>sj;
        cin>>di>>dj;
    
        while(b--){
            cout<<"in loop\n";
            int x,y;
            cin>>x>>y;
            arr[x][y] = 0;
        }
        cout<<"out\n";
        int ans = INT_MAX;
        vector<pair<int,int> > path;
        path.push_back({si,sj});
        
        vector<vector<pair<int,int> > > sol;
        
        solve(arr,si,sj,0,ans,di,dj,path,sol);
        cout<<ans<<"\n";
        sort(sol.begin(),sol.end());
    
        
        for(int i=0;i<sol.size();i++){
            if(sol[i].size() == ans + 1){
                for(int j=0;j<sol[i].size();j++){
                    cout<<sol[i][j].first<<","<<sol[i][j].second;
                    if(j != sol[i].size()){
                        cout<<" -> ";
                    }
                }
                
            }
        }
        cout<<"\n";
       
 
    }
    return 0;
}
