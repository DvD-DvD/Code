#include<bits/stdc++.h>
using namespace std;


void path(vector<pair<int,int> > &v,vector<vector<char> > &arr,int i,int j,int r,int d){
    int n = arr.size();
    int m = arr[0].size();
    if(i < 0 || j < 0 || i >= n || j>= m){
        return;
    }

    if(arr[i][j] == 'R'){
        r++;
    }
    if(arr[i][j] == '.'){
        d++;
    }

    if(i == n-1 && j == m-1){
        v.emplace_back(make_pair(r,d));
    }

    path(v,arr,i+1,j,r,d);
    path(v,arr,i,j+1,r,d);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > arr (n,vector<char> (m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<pair<int,int> > v;
    path(v,arr,0,0,0,0);
    cout<<"red "<<"dot\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<"  "<<v[i].second<<endl;
    }

}