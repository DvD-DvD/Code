// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
 
 
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         long long int  a,n,ans=1,m=1e9+7;
//         cin>>a>>n;
//         long long int x=a;
//         while(n>0)
//         {
//             if((n&1)==1){
//                 ans=(ans*x)%m;
//             }
//             x*=x;   
//             n=n>>1;
//         }
//             cout<<ans%m<<"\n";
//     }
//     return 0;
// }

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {
    long long int  a,n,ans=1,m=1e9+7;
       cin>>a>>n;
       long long int x=a;
   while(n>0)
   {
      if((n&1)==1){
     ans=(ans)*x;
    }
    x*=x;   
       n=n>>1;
   }
        cout<<ans%m<<"\n";
    }
    return 0;
}