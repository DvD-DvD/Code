#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int lb, int ub) {

    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);  // swap pivot from lower bound to end 
    return end;
}


void quicksort (int arr[], int lb, int ub) {
    if(lb > ub) return;
    int pivot = partition(arr,lb,ub);
    quicksort(arr,lb,pivot-1);
    quicksort(arr,pivot+1,ub);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}