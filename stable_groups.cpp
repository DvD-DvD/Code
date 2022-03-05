#include<bits/stdc++.h>
using namespace std;

#define int long long


int32_t main(){
    int n,k,x;
    cin>>n>>k>>x;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i] - arr[i-1] <= x){
            continue;
        }
        else if(k && arr[i] - arr[i-1] <= 2*x){
            k--;
        }
        else count++;
    }
    cout<<count<<endl;

}