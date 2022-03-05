#include<bits/stdc++.h>
using namespace std;

void islands(vector<vector<int > > v,vector<vector<int> > &arr,int i,int j){
    arr[i][j] = 1;
    int m = v.size();
    int n = v[0].size();
    int a1[8] = {0,0,1,1,1,-1,-1,-1};
    int a2[8] = {1,-1,0,1,-1,1,0,-1};
    for(int k=0;k<8;k++){    
        int x1 = i + a1[k];
        int y1 = j + a2[k];
        if(x1<m && x1>=0 && y1<n && y1>=0){
            if(arr[x1][y1] == 0 && v[x1][y1] == 1){
                islands(v,arr,x1,y1);
            }
        }
    }    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<int > > v(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              cin>>v[i][j];
            }
        }

        vector<vector<int> > arr(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == 0 && v[i][j] == 1){

                    ans++;

                    islands(v,arr,i,j);
                }

            }
        }
        cout<<ans<<endl;
    }
}