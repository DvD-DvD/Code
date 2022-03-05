#include<bits/stdc++.h>
using namespace std;

int main(){
    string c,a,b;
    cin>>c>>a>>b;
    int m = a.size();
    int n = b.size();
    vector<vector<bool> > dp(m+1,vector<bool> (n+1,false));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i==0 && b[j-1] == c[j-1]){
                dp[i][j] = dp[i][j-1];
            }
            else if(j==0 && a[i-1] == c[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]){
                dp[i][j] = dp[i][j-1];
            }
            else if(a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    cout<<dp[m][n]<<endl;

}