// Language : C++
// Time Complexity : O(1)
// Auxiliary Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    vector<int> groups(5,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        groups[x]++;
    }

    groups[1] = groups[1] - groups[3];
    int sum = groups[4];
    sum += groups[2]/2 + groups[3];

    if(groups[2]%2 == 1){
        groups[1] -= 2;
        sum++;
    }
    if(groups[1] > 0){
        sum += (groups[1] + 3)/4;
    }
    cout<<sum<<"\n";
}