#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> v1,v2,v;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            // v1.push_back(temp);
            // cin>>temp;
            // v2.push_back(temp);
            v.push_back(temp);

        }
        int x = n,y = n;
        int min1 = INT_MAX, min2 = INT_MAX;
        int prevmin1 = min1, prevmin2 = min2;
        int non_minsum1 = v[0],non_minsum2 = v[1];
        int sum1 = 0,sum2 = 0;
        int mincost1 = INT_MAX, mincost2 = INT_MAX;
        for(int i=0;i<n;i++){
            if(x == n && y == n){
                cout<<(mincost1 + mincost2)<<endl;
            }
            if(i == 0){
                cout<<"a "<<mincost1<<endl;
                min1 = v[i];
                sum1 = v[i]*n;
                non_minsum1 = 0;
                prevmin1 = 0;
                x++;
            }
            if(i == 1){
                cout<<"b "<<mincost2<<endl;
                min2 = v[i];
                sum2 = v[i]*n;  
                non_minsum2 = 0;
                prevmin2 = 0;
                y++;
            }
            if(i%2 == 0){
                cout<<"a "<<mincost1<<endl;
                if(prevmin1 != 0)
                    prevmin1 = min1;
                min1 = min(min1,v[i]);
                if(min1 != v[i]){  //min didnt change
                    non_minsum1 += v[i];
                    sum1 = non_minsum1*(i+1) + min1*(n-i-1); 
                }
                else{
                    non_minsum1 -=  prevmin1;
                    sum1 = non_minsum1*(i+1) + v[i]*(n-i-1); 
                }
                mincost1 = min(mincost1,sum1);
                x++;
            }
            else{
                cout<<"b "<<mincost2<<endl;
                if(prevmin2 != 0)
                    prevmin2 = min2;
                min2 = min(min2,v[i]);
                if(min2 != v[i]){  //min didnt change
                    non_minsum2 += v[i];
                    sum2 = non_minsum2*(i+1) + min2*(n-i-1); 
                }
                else{
                    non_minsum2 -=  prevmin2;
                    sum2 = non_minsum2*(i+1) + v[i]*(n-i-1); 
                }
                mincost2 = min(mincost2,sum2);
                y++;
            }
        }
    }
}