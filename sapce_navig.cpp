#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int u = 0,d = 0,l = 0,r = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'L'){
                l++;
            }    
            if(s[i] == 'R'){
                r++; 
            }    
            if(s[i] == 'U'){
                u++;
            }    
            if(s[i] == 'D'){
                d++;        
            }       
        }
       // cout<<r<<" "<<l<<" "<<d<<" "<<u<<" "<<endl;
        if(x > 0 && y > 0){
            if(r >= x && u >= y){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else if(x < 0 && y > 0){
            if(l >= abs(x) && u >= y){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else if(x > 0 && y < 0){
            if(r >= x && d >= abs(y)){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else if(x < 0 && y < 0){
            if(l >= abs(x) && d >= abs(y)){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}