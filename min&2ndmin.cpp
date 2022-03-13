#include<iostream>
using namespace std;


int _stoi(char c){
    return c - '0';
}

int main(){
    for(int tc=1;tc<=1;tc++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s += "+";
        int sum = 0,pro = 0;
        

        for(int i=0;i<n+1;i++){
            cout<<s[i]<<" "<<sum<<" "<<pro<<endl;
            if(s[i] == '+'){
                if(pro == 0){
                    sum += _stoi(s[i-1]);
                }
                else{
                    sum += pro;
                    pro = 0;
                }
            }
            else if(s[i] == '*'){
                if(pro == 0){
                    pro = _stoi(s[i-1]) * _stoi(s[i+1]);
                }
                else{
                    pro = pro* _stoi(s[i+1]);
                }
            }
        }

        cout<<sum<<endl;
    }
    

    
}