#include<bits/stdc++.h>
using namespace std;

bool contains(int n,int p){
    int x = n;
    while(x){
        int m = x%10;
        if(m == p){
          //  cout<<n<<"has "<<p<<endl;
            return true;
        }
        x /= 10;
    }
    
    return false;
}

int fact(int n) { 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

int ways(int size){
    return fact(size) / (fact(3) * fact(size - 3)); 
}

int main(){
   int n;
   cin>>n;
   vector<int> v;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       v.push_back(t);
   } 

   vector<vector<int > > sizes(8);
   for(int i=0;i<n;i++){
       if(contains(v[i],2)){
           sizes[2].push_back(v[i]);      
       }
       if(contains(v[i],3)){
           sizes[3].push_back(v[i]); 
       }
       if(contains(v[i],5)){
           sizes[5].push_back(v[i]); 
       }
       if(contains(v[i],5)){
           sizes[5].push_back(v[i]); 
       }
       if(contains(v[i],7)){
           sizes[7].push_back(v[i]); 
       } 
   }
   int ans = 0;

   if(sizes[2].size() > 2){

       ans += ways(sizes[2].size());
   }
   if(sizes[3].size() > 2){

       ans += ways(sizes[3].size());
   }
   if(sizes[5].size() > 2){

       ans += ways(sizes[5].size());
   }
   if(sizes[7].size() > 2){

       ans += ways(sizes[7].size());
   }
   cout<<ans;

   return 0;

}