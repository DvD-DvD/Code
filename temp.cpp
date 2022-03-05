#include <bits/stdc++.h>
using namespace std;

int main() {
    int mat[1001][1001];
    memset(mat, 0, sizeof(mat));
    mat[1][1] = 1;
    int d = 2;
    for(int i=1;i<1001;i++){
        mat[i][0] = mat[i-1][0] + d;
        d++;
    }
    
    for(int i=1;i<1001;i++){
        int d = i;
        for(int j=2;j<1001;j++){
            mat[i][j] = mat[i][j-1] + d;
        }
    }
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
	int t;
// 	cin>>t;
	// while(t--){
	    
	// }
	return 0;
}
