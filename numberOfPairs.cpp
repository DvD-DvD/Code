#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr,int i, int k){
    int ind = -1;
    int l = i;
    int r = arr.size()-1;

    while(l<=r){
        int mid = l + (r - l) / 2;
        if(arr[mid] >= k){
            ind = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ind;
}



int findCeil(vector<int> &arr,int i, int k){
    int ind = -1;
    int l = i;
    int r = arr.size()-1;

    while(l<=r){
        int mid = l + (r - l) / 2;
        if(arr[mid] <= k){
            ind = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ind;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        long long int count = 0;
        for(int i = 0; i < n-1;i++){
            int x = findFloor(arr, i + 1, l - arr[i]);
            int y = findCeil(arr, i + 1, r - arr[i]);

            if(x != -1 && y != -1){
                count += y - x + 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}