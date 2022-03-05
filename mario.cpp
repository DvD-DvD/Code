#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,d;
    cin>>n;
    cin>>m;
    cin>>d;
    int arr[m];
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        arr[i] = x-1;
    }
    int pos = -1;
    int steps = 0;
    int flag = 0;
    for(int i=0;i<m;i++){
        if(pos == n){
            break;
        }
        else if(pos+d >=n){
            steps++;
            break;
        }
        else if(pos+d < arr[i] ){
            if(flag == 0){    
                cout<<"-1"<<endl;
                return 0;
            }
            else{
                i--;
                pos = arr[i];
                steps++;
                flag = 0;
            }    
        }
        else if(pos + d == arr[i]){
            pos = arr[i];
            steps++;
        }
        else if(pos+d > arr[i]){
            flag = 1;
            continue;
        }
       
    }
    cout<<steps<<endl;
    return 0;
}