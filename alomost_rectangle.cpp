#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr[n][n];
        int pos[2][2];
        int itr = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                if(arr[i][j] == '*'){
                    pos[itr][0] = i;
                    pos[itr][1] = j;
                    itr++;
                }
            }
        }
        arr[pos[0][0]][pos[1][1]] = '*';
        arr[pos[1][0]][pos[0][1]] = '*';

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

         
    }
}