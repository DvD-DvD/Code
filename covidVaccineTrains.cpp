#include<bits/stdc++.h>
using namespace std;

vector<int> getKmax(vector<int> &arr, int n, int k){
    deque<int> q(k);
    vector<int> ans;
    int i;
    for (i = 0; i < k; ++i){
     
        while ((!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
 
        q.push_back(i);
    }
 
    for (; i < n; ++i){
        ans.push_back(q.front());
        while ((!q.empty()) && q.front() <= i - k)
            q.pop_front();
 
        while (!(q.empty()) && arr[i] >=  arr[q.back()])
            q.pop_back();
 
        q.push_back(i);
    }
    ans.push_back(q.front());
    return ans;
}

int solve(vector<int> &arr, int n, int k){
    vector<int> values = getKmax(arr,n,k);
    int count = 0;
    for(int i=1;i<values.size();i++){
        if(arr[i-1] > values[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k);
}