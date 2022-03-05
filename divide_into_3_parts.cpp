#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    vector<int> pre(n,0), post(n,0);
    pre[0] = arr[0];

    for(int i=1;i<n;i++){
        pre[i] += pre[i-1] + arr[i];
    }

    post[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        post[i] = post[i+1] + arr[i];
    }    
    reverse(post.begin(),post.end());

    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(binary_search(post.begin(),post.begin()+(n-i-1),pre[i])){
            ans = max(ans,pre[i]);
        }
    }
    cout<<ans<<endl;


}