#include<bits/stdc++.h>
using namespace std;

void dfs(){



int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v[m];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

}