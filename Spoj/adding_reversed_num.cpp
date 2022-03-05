#include<iostream>
using namespace std;

int reverser(int a){
    int rev = 0;
    while(a){
        int rem = a%10;
        rev = rev*10 + rem;
        a = a/10;
    }
    return rev;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        a = reverser(a);
        b = reverser(b);
        cout<<reverser(a+b)<<endl;

    }
    return 0;
        
}
