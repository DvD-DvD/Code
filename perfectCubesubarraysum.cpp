#include<bits/stdc++.h> 
using namespace std;


map<int, int> PFhelper(map<int, int> pf,int f){
    if (pf.find(f) != pf.end()){
        pf[f]++;
    }
    else{
        pf[f] = 1;
    }
    return pf;
}
 

map<int, int> pfCheck (int n){
    map<int, int> pf;
    while (n % 2 == 0)    {
        pf = PFhelper(pf, 2);
        n /= 2;
    }
 
    for(int i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0)        {
            pf = PFhelper(pf, i);
            n /= i;
        }
    }
    if (n > 2)
        pf = PFhelper(pf, n);
 
    return pf;
}
 
bool perfectCube (int n){
    if(n==0) return false;
    map<int, int> pf;
    pf = pfCheck(n);
 
    for(auto i : pf)
    {
        if (i.second % 3 != 0)
            return false;
    }
    return true;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long> prefix(n);
    prefix[0] = v[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + v[i];
    }

    long sum;

    int len = INT_MAX;

    // if(perfectCube(prefix[0])) len = 1;

    for(int i=0;i<n;i++){
        if(perfectCube(prefix[i])) len = min(len,i+1);
        for(int j=i+1;j<n;j++){
            sum = prefix[j] - prefix[i];
            if(perfectCube(sum)){
                len = min(len,j-i);
            }    
        }
    }
    if(len == INT_MAX) cout<< -1<<endl;
    else cout<<len<<endl;
    return 0;
}