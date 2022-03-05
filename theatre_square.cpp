#include<bits/stdc++.h>
using namespace std;

int main(){
    double m,n,a;
    cin>>m>>n>>a;
    double x = m/a;
    long long int p = ceil(x);
    
    double y = n/a;
    long long int q = ceil(y);

    //cout<<x<<" "<<y<<endl;
    unsigned long long ans = (p*q);
    cout<<ans<<endl;
}