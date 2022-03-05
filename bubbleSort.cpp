#include<bits/stdc++.h>
using namespace std;



void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j+1],arr[j]);
        }
    }
}


void insertionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=1;i<n;i++){
        int curr = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}


void selectionSort(vector<int> &ar){
    for(int i = 0; i < n-1; i++) {
        int minimumElement = ar[i], index = i;
        for(int j = i+1; j < n; j++) {
            if(minimumElement < ar[j]) {
                minimumElement = ar[j];
                index = j;
            }
        }
        swap(ar[i], ar[index]); // swapping ar[i] and ar[index]
    }
}




void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // bubbleSort(arr);
    insertionSort(arr);
    print(arr);
}