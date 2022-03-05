#include<bits/stdc++.h>
using namespace std;


int di[4] = {-1,0,0,1};
int dj[4] = {0,-1,1,0};

bool valid(int i,int j,int m,int n){
    return (i>0 && i<m && j>0 && j<n);
}

bool dfs(vector<vector<char> > &mat,int i,int j,int x,int y,int k,int count){
    // cout<<i<<" "<<j<<" "<<count<<endl;
    if(i==x && j==y && count>=k){
        return true;
    }

    bool found = false;
    int m = mat.size(), n = mat[0].size();

    for(int p=0;p<4;p++){
        int I = i+di[p];
        int J = j+dj[p];

        if(valid(I,J,m,n) && mat[I][J] == '.'){
            mat[I][J] = '*';
            found = dfs(mat,I,J,x,y,k,count+1);
            mat[I][J] = '.';
            if(found) return true;
        }
    }
    return found;


}


int main(){
    int m,n;
    cin>>m>>n;
    int k;
    cin>>k;
    int i,j;
    cin>>i>>j;
    vector<vector<char> > mat(m+1,vector<char> (n+1));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            mat[i][j] = c;
        }
    }
    
    cout<<dfs(mat,i,j,i,j,k,0);

}