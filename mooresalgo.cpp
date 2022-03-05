#include<bits/stdc++.h>
using namespace std;

int getMajorCand(int arr[],int n){
    int maj_ind = 0;
    int count = 1;
    for(int i=0;i<n;i++){
        if(arr[maj_ind] == arr[i]){
            count++;
        }
        else 
            count--;
        if(count == 0){
            maj_ind = i;
            count = 1;
        }    
    }
    return arr[maj_ind];
}

int checkIfMajor(int arr[],int n,int a){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == a){
            count++;
        }
    }
    if(count > n/2){
        return 1;
    }
    return 0;

}

int boothe(int arr[],int n){
    int cand = getMajorCand(arr,n);
    if(checkIfMajor(arr,n,cand)){
        return cand;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j = 0;j < n ;j++){
            cin>>arr[j];
        }
        cout<<boothe(arr,n)<<endl;
    }
    return 0;
}