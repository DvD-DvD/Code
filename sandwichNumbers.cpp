#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (int i = 0; i < n;i++){
        cin >> v[i][0];
    }
    for (int i = 0; i < n;i++){
        cin >> v[i][1];
    }

    sort(v.begin(), v.end());

    int l = v[0][0];
    int r = v[0][1];

    for (int i = 1; i < n;i++){
        if(v[i][0] > r || v[i][1] < l){
            cout << 0 << endl;
            return 0;
        }
        else{
            l = max(l, v[i][0]);
            r = min(r, v[i][1]);
        }
    }
    cout << (r - l + 1) << endl;
    return 0;
}