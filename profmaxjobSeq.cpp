#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

bool mycomp(const job &j1,const job &j2){
    
    if(j1.deadline == j2.deadline){
        return j1.profit > j2.profit;
    }
    else return j1.deadline < j2.deadline;
}

int main(){
    int n;
    cin>>n;
    vector<job> v;
    for(int i=0;i<n;i++){
        int j,d,p;
        cin>>j>>d>>p;
        job t;
        t.id = j;
        t.deadline = d;
        t.profit = p; 
        v.push_back(t);
    }
    sort(v.begin(),v.end(),mycomp);
    for(int i=0;i<n;i++){
        cout<<v[i].id<<" "<<v[i].deadline<<" "<<v[i].profit<<endl;
    }
    int t = 1;
    for(int i=0;i<n;i++){
        if(v[i].deadline >= t){
           cout<<v[i].id<<" ";
           t++; 
        }
        else{
            while(v[i].deadline < t){
                i++;
            }
            i--;
        }
        
    }
    return 0;

    
}