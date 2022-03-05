#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n;i++){
            cin >> arr[i];
        }
        int min_ind = 0;
        int max_ind = 0;
    
        for (int i = 1; i < n;i++){
            if(arr[i] > arr[max_ind]){
                max_ind = i;
            }
             if(arr[i] < arr[min_ind]){
                min_ind = i;
            }
        }

        int a = max(max_ind, min_ind) + 1;
        int b = n - min(max_ind, min_ind);
        int c = min(min_ind, max_ind) + 1 + n - max(min_ind, max_ind);
        cout << min(a, min(b, c))<<endl;
    }
}