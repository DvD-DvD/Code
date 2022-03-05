#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(true){
        cin>>n;
        if(n == -1) return 0;
        int sum = 0;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum%n == 0){
            int diff = 0;
            int k = sum/n;
            for(int i=0;i<n;i++){
                diff += abs(arr[i] - k);
              // cout<<abs(arr[i] - k)<<endl;
            }
            cout<<diff/2<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }

    }
   
    return 0;
}