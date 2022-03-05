    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
        string s;
        cin>>s;
        int n = s.size(); 
        vector<int> pre(n),suf(n);
        if(s[0] == 'Q') pre[0] = 1;
        
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1];
            if(s[i] == 'Q') pre[i]++;
            
        }
        
        if(s[n-1] == 'Q'){
            suf[n-1] = 1;
        }
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1];
            if(s[i] == 'Q') suf[i]++;
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(s[i] == 'A'){
                ans += suf[i]*pre[i];
            }
        }
        cout<<ans<<endl;
    }