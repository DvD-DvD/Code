#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool flag = true;
        if(k == 0){
            cout<<"YES"<<endl;
            continue;
        }
        if(2*k + 1 > n){
            cout<<"NO"<<endl;
        }
        else{
            for(int i=0;i<k;i++){
                if(s[i] != s[n-i-1]){
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}