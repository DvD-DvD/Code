#include<iostream>
using namespace std;

void insertionSort(int n,int arr[]){
    int i,j,key;
    for(int i = 1;i < n;i++){
        j = i-1;
        key = arr[j];
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(n,arr);
}