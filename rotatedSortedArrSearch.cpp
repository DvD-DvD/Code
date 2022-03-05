// 7 8 9 1 2 5 6  size=7  high=6  low =0  mid=3  
// 0 1 2 3 4 5 6
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        int k;
        cin>>k;
        int h = n-1;
        int l = 0;
        int m;
        while(l<=h){
            m = l + (h-l)/2;
            if(v[m] == k){
                break;
            }
            else if(v[l] <= v[m]){         //left part is sorted 
                if(v[l] <= k && k <= v[m]){
                    h = m -1;
                }
                else{
                    l = m + 1;
                }
            
            }
            else{
                if(v[m] <= k && k <= v[h]){
                    l = m + 1;
                }
                else{
                    h = m - 1;
                }
            }
        }
        if(l <= h){
            cout<<m<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}