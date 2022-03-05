#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool isInterleave(string A, string B, string C) {
        int n = A.size();
        int m = B.size();
        int dp[n+1][m+1];
        if(m+n != C.size()){
            return false;
        }
        if(n==0){
            return B==C;
        }
        if(m==0){
            return A==C;
        }
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            if(A[i-1]==C[i-1])
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = 0;
        }
        
        for(int j=1;j<=m;j++){
            if(A[j-1]==C[j-1])
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(C[i+j-1] == A[i-1] && C[i+j-1] == B[j-1])
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if(C[i+j-1] == A[i-1])
                    dp[i][j] = dp[i-1][j];
                else if(C[i+j-1] == B[j-1])
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    Solution ob = new Solution();
    cout << ob.isInterleave(a, b, c) << endl;
}