#include<bits/stdc++.h>
using namespace std;  

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int> v;
        long long int i = 2;
        long long int prev = 1;
                
        while(i <= sqrt(n) && n > 2 && i%prev == 0){
            if(n%i == 0 && (n/i)%i == 0){
                v.push_back(min(i,n/i));
                n = max(i,n/i);
                prev = v[v.size()-1];
            }
            else{
                i++;
            }
        }
    
        v.push_back(n);
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}