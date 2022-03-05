#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> arr(26,0);
    for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
    }
    int sum = 0;
    for(int i=0;i<26;i++){
        sum += arr[i] * (n - arr[i]);
    }
    cout<<sum/2+1<<"\n";
}
