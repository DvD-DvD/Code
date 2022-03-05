#include<bits/stdc++.h>
using namespace std;

int maxSubarray(int arr[], int n, int k) 
{ 

    map<int, int> Map; 
    int l = 0; 
  
  
    for (int i = 0; i < n; i++) { 
        l++; 
        Map[arr[i]]++; 
        if (l == k) { 
  
            auto itMax = Map.end(); 
            itMax--; 
            auto itMin = Map.begin(); 
            cout << itMin->first<<" "; 

            Map[arr[i - k + 1]]--; 
            if (Map[arr[i - k + 1]] == 0) { 
                Map.erase(arr[i - k + 1]); 
            } 
  
            l--; 
        } 
    } 
    return 0; 
} 

int main(){
    int n,k;
    cin>>n;
    cin>>k
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxSubarray(arr,n,k);
    cout<<endl; // idhi pettalo ledho chusko vaadu qstn lo last lo new line undhi ani ichadu
    return 0;
}