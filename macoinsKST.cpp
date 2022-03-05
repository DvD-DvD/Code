#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int p = 1;
    while(t--){
        int n;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }

        }
        int maxm  = -1;
        for(int i=0;i<n;i++){
            int x = i;
            int temp = 0;
            for(int j=0;j<n && x<n;j++){
                temp += arr[x][j]; 
                //cout<<x<<" "<<j<<endl; 
                x++;
            }
            maxm = max(maxm,temp);
        }
        for(int j=1;j<n;j++){
            int x = j;
            int temp = 0;
            for(int i=0;i<n && x<n;i++){
                temp += arr[i][x];
                //cout<<i<<" "<<x<<endl;
                x++;
            }
            maxm = max(maxm,temp);
        }

        cout<<"Case #"<<p<<": "<<maxm<<endl;
        p++;
    }
    return 0;
}