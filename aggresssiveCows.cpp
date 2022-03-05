#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<int> &arr,int c,int k){
    int count = 1;
    int last = 0;
    for(int i=1;i<arr.size();i++){
        if(arr[i] - arr[last] >=k){
            count++;
            last = i;
        }
    }
    return (count >= c);
}

int binarySearch(vector<int> &arr,int c){
    int n = arr.size();
    int l=1;
    int r=arr[n-1]-arr[0];
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(isValid(arr,c,mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        cout<<binarySearch(arr,c)<<endl;
       
    }
}