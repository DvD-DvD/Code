#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;

        if(b>=0){
            cout<<((a+b)*n)<<"\n";
        }
        else{
            int x=0,y=0;
            if(s[0] == '0') x++;
            else y++;

            for(int i=1;i<n;i++){
                if(s[i] != s[i-1]){
                    if(s[i] == '0') x++;
                    else y++;
                }
            }
            cout<<(a*n) + b*(min(x,y)+1)<<"\n";
        }
    }
}