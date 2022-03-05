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

    for(int i=0;i<n;i++){
        int mn = i,mx = i;
        for(int j=i;j<n;j++){
            if(arr[mn] > arr[j]){
                mn = j;
            }
            if(arr[mx] < arr[j]){
                mx = j;
            }
            if(arr[mx] - arr[mn] == j-i){
                ans = max(ans,j-i+1);
                cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
    }

    cout<<ans<<endl;
}


// 3 7 -2 10 8 11 9 15 6 4 5 -7 -6 