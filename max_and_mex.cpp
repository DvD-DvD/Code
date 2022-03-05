#include<bits/stdc++.h>
using namespace std;

int mexer(vector<int> &v){
    sort(v.begin(),v.end());
       //int mex_pos = -1;
       int mex = v.size();
       for(int i=0;i<v.size();i++){
           if(v[i] != i){
               mex = i;
            //  cout<<"mex is "<<mex<<endl;
               return mex;
           }
       }

       // cout<<"mex is "<<mex<<endl;
        return mex;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       vector<int> v;
       int temp;
       for(int i=0;i<n;i++){
           cin>>temp;
           v.push_back(temp);
       }
       int mex = mexer(v);
      // cout<<"loop started "<<endl;

       while(k--){
            double sum = ((double)v[n-1]  + (double)mex)/2;
            int element = ceil(sum);
            //cout<<"max is "<<v[n-1]<<endl;
           // cout<<"element is "<<element<<endl;
            v.push_back(element);
            n++;
            mex = mexer(v);
       }
       int count = 0;
       for(int i=0;i<v.size();i++){
         // cout<<v[i]<<" ";
           if(v[i] != v[i+1]){
               count++;
           }
       }
      // cout<<endl;
       cout<<count<<endl;
    }
}

