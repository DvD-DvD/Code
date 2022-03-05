#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int p = 1;
    while (t--){
        string str;
        cin>>str;
        vector<int> v1;
        vector<int> v2;
        int incr = 0;
        for(int i=0;i<str.size();i++){
            if(str.substr(i,4) == "KICK"){
                v1.push_back(i);
            }
            else if(str.substr(i,5) == "START"){
                v2.push_back(i);
            }
        }
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]<v2[j]){
                    incr++;
                }
            }
        }
        cout<<"Case #"<<p<<": "<<incr<<endl;
        p++;
    }
    return 0;
}