#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        string str;
        cin>>str;
        int n = str.size();
        bool flag = true;
        if(n == 1){
            if(str[0] == '?'){
                if(a){
                     str[0] = '0';
                     a--;
                }
                if(b){
                    str[0] = '1';
                    b--;
                }

            }
            else if(str[0] == '0'){
                a--;
            }
            else{
                b--;
            }
            if(a == 0 && b == 0){
                cout<<str<<endl;
            }
            else{
                cout<<"-1\n";
            }
            continue;
        }
        for(int i=0;i<n/2;i++){
            if(str[i] != '?' && str[n-i-1] != '?' &&  str[i] != str[n-i-1]){
                cout<<"-1\n";
                flag = false;
                break;
            }
        }
        if(!flag){
            continue;
        }
        for(int i=0;i<n;i++){
            if(str[i] == '0'){
                a--;
            }
            if(str[i] == '1'){
                b--;
            }
        }

        for(int i=0;i<n/2;i++){
            if(str[i] == '0'){
                if(str[n-i-1] == '?'){
                    str[n-i-1] = str[i];
                    a--;
                }
            }
            else if(str[i] == '1'){
                if(str[n-i-1] == '?'){
                    str[n-i-1] = str[i];
                    b--;
                }
            }
            else{
                if(str[n-i-1] != '?'){
                    str[i] = str[n-i-1];
                    if(str[i] == '0') a--;
                    else b--;
                }
    
            }
            
        }
        //cout<<str<<" "<<a<<" "<<b<<endl;
        if(a || b){
           
            for(int i=0;i<n/2;i++) {
                if(str[i] == '?' && str[n-i-1] == '?'){
                    if(a){
                        str[i] = '0';
                        str[n-i-1] = '0';
                        a--;
                        a--;
                    }
                    else if(b){
                        str[i] = '1';
                        str[n-i-1] = '1';
                        b--;
                        b--;    
                    }
                }
            }
            if(n%2 == 1){
                if(a){
                    str[n/2] = '0';
                    a--;
                }
                else if(b){
                    str[n/2] = '1';
                    b--;
                } 
            }   
        }

        if(a == 0 && b == 0 ){
            cout<<str<<endl;
        }
        else cout<<"-1\n";
        
         
    }
}