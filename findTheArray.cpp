#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        int x = sqrt(s);
        if(x*x == s) cout<<x<<endl;
        else cout<<x+1<<endl;
    }
}