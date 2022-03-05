#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<long long int > b(n+2);
    for(int i=0;i<n+2;i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    long long int sum = 0;
    for(int i=0;i<n;i++){
        sum += b[i];
    }
    long long int find = b[n+1] - sum;
    bool found = false;
    for(int i=0;i<n+1;i++){
        if(b[i] == find){
            found = true;
            for(int j=0;j<n+1;j++){
                if(j != i ){
                    cout<<b[j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    if(!found){
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}
}