#include<bits/stdc++.h>
using namespace std;


int findLast(unordered_map<int,vector<int> > &mp,unordered_map<int,bool> visited,int m){
    queue<int> q;
    visited[m] = true;
    q.push(m);
    set<int> s;
    bool flag = false;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            int curr = q.front();
            q.pop();
            s.insert(curr);
            for(int i=0;i<mp[curr].size();i++){
                if(!visited[mp[curr][i]]){
                    visited[mp[curr][i]] = true;
                    q.push(mp[curr][i]);
                    flag = true;
                }
            }    
        }
        if(flag == false){
            return *(--s.end());
        }
        else{
            s.clear();
            flag = false;    
        }
    }
    return -1;
}


int main(){
    int t;
    cin>>t;
    while (t--){
        unordered_map<int,bool> visited;
        unordered_map<int,vector<int> > mp;
        int m,n;
        cin>>n>>m;
        for(int i=0;i<n/2;i++){
            int x,y;
            cin>>x>>y;
            if(visited.find(x) == visited.end()){
                visited.insert({x,false});
                mp.insert(make_pair(x,vector<int>()));
            }
            mp[x].push_back(y);
        }
        cout<<findLast(mp,visited,m)<<endl;
    }
    return 0;       
}