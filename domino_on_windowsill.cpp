#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k1,k2;
        cin>>n>>k1>>k2;
        int w,b;
        cin>>w>>b;
        int W = 0, B = 0;
        if(w == 0 && b == 0){
            cout<<"YES"<<endl;
            continue;
        }
        W = abs(k1-k2)/2 + min(k1,k2);
        B = abs(k1-k2)/2 + min(n-k1,n-k2);
        if(w <= W && b <= B){
            cout<<"YES"<<endl;
            continue;
        }
        else cout<<"NO"<<endl;

    }
}