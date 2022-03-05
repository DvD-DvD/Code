#include<bits/stdc++.h>
using namespace std;

bool range(long int a, long int b, long int x){
    if(x >= a && x <= b){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        long int l,r;
        cin>>l>>r;
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                long int num = 1;
                if(num <= r){
                    if(range(l,r,num)){
                        count++;
                    }
                    for(int j=i+1;j<min(i+32,n);j++){
                        num = num << 1;
                        if(s[j] == '1'){
                            num += 1;
                        }
                        if(range(l,r,num)){
                            count++;
                        }
                        else if(num > r){
                            break;
                        }
                    }
                }       
            }    
        }

        cout<<count<<"\n";
    }
}
