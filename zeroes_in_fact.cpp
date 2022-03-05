#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a = 5;
		int count  = 0;
		while(n/a > 0){
			count += n/a;
			a = a*5;
		}
		cout<<count<<endl;

	}
	return 0;
}