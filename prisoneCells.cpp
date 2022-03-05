// Language : C++
// Time Complexity : O(1)
// Auxiliary Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;
#define int long long int

int findCell(int x,int y){
    int origin = x + y-1;
    return (origin*(origin+1))/2 - y + 1;  
}

int32_t main(){
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        cout<<findCell(x,y)<<" ";
    }
}