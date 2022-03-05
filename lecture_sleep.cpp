#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),sleeps(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>sleeps[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i]*sleeps[i];
    }
    int tot  = 0,max_tot = 0;
    for(int i=0;i<k;i++){
        tot += arr[i] * (1-sleeps[i]);
    }
    max_tot = tot;
    int start = 0,end = k-1;
    while(end < n-1){
        end++;
        tot = tot - arr[start]*(1-sleeps[start]) + arr[end]*(1-sleeps[end]);
        max_tot = max(max_tot,tot);
        start++;
    }
    cout<<sum+max_tot<<endl;


}