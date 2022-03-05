#include<bits/stdc++.h> 
using namespace std;
bool rounding(double a, double b){
	int A = a*1000;
	int B = b*1000;
	return A==B;
}
bool is_equal(vector<double> a, vector<double> b){
	int n = a.size();
	for(int i=0;i<n;i++){
		if(!rounding(a[i], b[i]))
			return false;
	}
	return true;
}
void printVariables(vector<double> A){
	int n = A.size();
	for(int i=0;i<n;i++){
		cout<<"x"<<i<<" = ";
		cout << fixed << setprecision(3) <<A[i]<<"\t";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter n : ";
	cin>>n;
	vector<vector<double> > coefficients(n, vector<double> (n));
	cout<<"Enter the coefficients row wise"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>coefficients[i][j];
		}
	}
	vector<double> constants(n);
	cout<<"Enter the right hand side constants : ";
	for(int i=0;i<n;i++){
		cin>>constants[i];
	}
	vector<double> answers(n,0);
	vector<double> answers_prev(n,-1);
	cout<<"iteration 0"<<endl;
	printVariables(answers);
	int iter = 1;
	while(!is_equal(answers, answers_prev)){
		answers_prev = answers;
		for(int i=0;i<n;i++){
			answers[i] = constants[i];
			for(int j=0;j<n;j++){
				answers[i] -= coefficients[i][j]*answers_prev[j];
			} 
			answers[i]+= coefficients[i][i]*answers_prev[i];
			answers[i] = answers[i]/coefficients[i][i];
		}
		cout<<"iteration "<<iter<<endl;
		printVariables(answers);
		iter++;
	}
	cout<<"Solution to the system of equations"<<endl;
	printVariables(answers);
	return 0;
}