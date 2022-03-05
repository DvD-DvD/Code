#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int q;
    cin>>q;
    
    while(q--){
        int a,b;
        cin>>a>>b;
        vector<int>::iterator left,right,next_right;
        left = lower_bound(arr.begin(),arr.end(),a);
        right = upper_bound(arr.begin(),arr.end(),b);
        right--;
        cout<<(right - left + 1)<<"\n";
    }
    return 0;
}