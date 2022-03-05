#include<bits/stdc++.h>
using namespace std;

int main(){
    int  n;
    cin>>n;
    int even_count = 0;
    int odd_count = 0;
    priority_queue<int,vector<int>,greater<int> > even,odd;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2 == 0){
            even_count++;
            even.push(x);
        }
        else{
            odd_count++;
            odd.push(x);
        } 
    }

    if(abs(even_count - odd_count) <= 1){
        cout<<0<<"\n";
    }
    else{
        long long int sum = 0;
        if(even_count > odd_count){  
            int k = even_count - odd_count - 1;
            while(!even.empty() && k--){
                sum += even.top();
                even.pop();
            }
        }
        else{
            int k = odd_count - even_count - 1;
            while(!odd.empty() && k--){
                sum += odd.top();
                odd.pop();
            }
        }
        cout<<sum<<"\n";
    }        
}