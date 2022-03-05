#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &v,int total,int sum,int i){
    
    if(sum == total - sum){
        return true;
    }
    if(i == v.size()){
        return false;
    }
    return check(v,total,sum+v[i],i+1) || check(v,total,sum,i+1);
}


int main(){
    int n;
    int sum = 0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        
    }
    cout<<check(arr,sum,0,0);
}