#include <bits/stdc++.h>
using namespace std;

class Minheap{
    public:
        vector<int> mh;
        Minheap(){
            vector<int> mh;
        }
        
        int size(){
            return mh.size();
        }
    
        int getMin(){
            return mh[0];
        }
    
        int getParent(int i){
            return (i-1)/2;
        }
        
        int getLeft(int i){
            return 2*i+1;
        }
    
        int getRight(int i){
            return 2*i+2;
        }

        void insert(int x){
            mh.push_back(x);
            int idx = size()-1;
            while(idx != 0 && mh[getParent(idx)] > mh[idx]){
                swap(mh[getParent(idx)], mh[idx]);
                idx = getParent(idx);
            }   
        }
    
        void delMin(){
            if(mh.size() == 0){
                return;
            }
            int idx = 0;
            mh[idx] = mh[size()-1];
            mh.pop_back();
            
            while(idx < size()){
                int min_idx = idx;
                int left = getLeft(idx), right = getRight(idx);
                
                if(left < size() && mh[left] < mh[min_idx]){
                    min_idx = left;
                }
                if(right < size() && mh[right] < mh[min_idx]){
                    min_idx = right;
                }
                if(min_idx == idx){
                    break;
                }
                swap(mh[idx],mh[min_idx]);
                idx = min_idx;
            }
            
           
        }
            
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    Minheap hp;
    while(t--){
        string s;
        cin>>s;
        if(s == "insert"){
            int x;
            cin>>x;
            hp.insert(x);
        }
        if(s == "getMin"){
            if(hp.size() == 0){
                cout<<"Empty\n";
            }
            else cout<<hp.getMin()<<"\n";
        }
        
        if(s == "delMin"){
            if(hp.size() != 0){
                hp.delMin();
            }
        }
    }
    return 0;
}
