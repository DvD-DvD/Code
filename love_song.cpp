#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<vector<int> > freq(n+1,vector<int> (26,0));
    freq[1][s[0] - 'a'] ++;

    for(int i=1;i<n;i++){
        freq[i+1] = freq[i];
        freq[i+1][s[i] - 'a'] = freq[i][s[i] - 'a'] + 1;
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<26;j++){
    //         if(freq[i][j]){
    //             cout<<(char)('a' + j) <<" "<<freq[i][j]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    while(q--){
        int l,r;
        cin>>l>>r;
        int count = 0;
        for(int i=0;i<26;i++){
            count += (freq[r][i] - freq[l-1][i])*(i+1);
        }
        cout<<count<<endl;  
    }
}
