#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int arr[] = {0,0,1,1,0,1,0,1,1,1,0};
    int p1=0,p2= 10;
    while(p1<p2){
        while(arr[p1] == 0) p1++;
        while(arr[p2 ==  1]) p2--;
        swap(arr[p1],arr[p2]);
        p1++;
        p2--;
    }
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
}