#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int knapsack(int i,int w,const vector<int> &wt,const vector<int> &v){
    if(w == 0){
        return 0;
    }
    if(i <= 0){
        return INT_MAX;
    }
    
    if(dp[i][w] != INT_MAX){
        return dp[i][w];
    }
    
    dp[i][w] = knapsack(i-1,w,wt,v);
    
    if(w >= wt[i-1]){
        dp[i][w] = min(dp[i][w], knapsack(i,w-wt[i-1],wt,v) + v[i-1]);
    }
    return dp[i][w];

}




int init(const vector<int> &cap,const vector<int> &w,const vector<int> &v){
    int W = INT_MIN;
    for(int i=0;i<cap.size();i++){
        W = max(W,cap[i]);
    }
    int n = w.size();
    vector<int> dp(W+1,0);
    
    for(int i=0;i<=W;i++){
        for(int j=0;j<n;j++){
            if(w[j] <= i){
                if(dp[i] == 0){
                    dp[i] = dp[i - w[j]] + v[j];
                }
                else{
                    dp[i] = min(dp[i], dp[i - w[j]] + v[j]);
                }
            }
        }
    }
    
    int cost = 0;
    // for(int i=0;i<=W;i++){
     
    // }
    for(int i=0;i<cap.size();i++){
        cost += dp[cap[i]];
    }
    return cost;
}

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    return init(A,B,C);
    // int cost = 0;
    // for (int i = 0; i < A.size();i++){
    //     cost += knapsack(B.size(), A[i], B, C);
    // }
    // for (int i = 0; i < 10;i++){
    //     for (int j = 0; j < 10;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return cost;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> A, B, C;
    for (int i = 0; i < m;i++){
        int x;
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        B.push_back(x);
    }

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        C.push_back(x);
    }

    cout<<solve(A,B,C);

}