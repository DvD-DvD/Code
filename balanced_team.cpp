#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int up = upper_bound(arr.begin(),arr.end(),arr[i]+5) - (arr.begin() + i);
        ans = max(ans,up);
    }
    cout<<ans<<endl;
}