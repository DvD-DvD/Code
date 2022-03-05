#include <bits/stdc++.h>
using namespace std;

void sieve(int a,int n){
	bool prime[n+1];
	memset(prime,1,sizeof(prime));
	prime[1] = false;
	for(int p = 2; (p*p)<=n ;p++){
        //cout<<p<<endl;
        if(prime[p] == true){	
            for(int i = p*p ;i <=n;i += p){
				prime[i] = false;
                
			}
		}
	}

	for(int i=a;i<=n;i++){
		if(prime[i] == true){
			cout<<i<<endl;
		}
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		sieve(a,b);
		cout<<endl;
		
	}
	return 0;
}