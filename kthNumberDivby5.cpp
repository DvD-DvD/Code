#include<bits/stdc++.h>
using namespace std;
int digSum(int n){
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n = n/10;
    }
    if(sum%5 == 0){
        return 1;
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int off;
    for(int i=n+1;i<n+10;i++){
        if(digSum(i) == 1){
            off = i;
            break;
        }
    }
    if(k == 1){
        cout<<off<<endl;
        return 0;
    }
    k--;
    int ans = off;
    if(digSum(off + 4) == 1){
        if(k%2 == 0){
            ans += (k/2)*9;
        }
        else{
            ans += ((k-1)/2)*9;
            ans += 4;
        }
        cout<<ans<<endl;
    }
    else if(digSum(off + 5) == 1){
         if(k%2 == 0){
            ans += (k/2)*9;
        }
        else{
            ans += ((k-1)/2)*9;
            ans += 5;
        }
        cout<<ans<<endl;
    }
    return 0;
}