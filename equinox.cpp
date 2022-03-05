#include <iostream>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--){
	    int n,a,b;
	    cin>>n>>a>>b;
	    int ssum = 0;
	    int asum = 0;
	    cout<<"henlo";
	    while(n--){
	        string s;
	        cin>>s;
	        if(s[0] == 'E' || s[0] == 'Q' || s[0] == 'U' || s[0] == 'I' || s[0] == 'N' || s[0] == 'O' || s[0] == 'X'){
	            ssum += a;    
	        }
	        else{
	            asum += b;
	        }
	    }
	    
	    if(asum > ssum){
	        cout<<"ANURADHA\n";
	    }
	    else if(asum < ssum){
	        cout<<"SARTHAK\n";
	    }
	    else cout<<"DRAW\n";
	}
	return 0;
}
