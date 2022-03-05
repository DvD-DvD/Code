#include<iostream>
using namespace std;

int main(){
    int a,n;
    cin>>a>>n;
    long long int ans = 1;
    int x = a;
    while(n){
        int bit = 0;
        bit = n%2;
        n = n/2;
        
        if(bit == 1){
            ans = ans*x;
        }
        x = x*x;
    }
    cout<<ans<<endl;
}