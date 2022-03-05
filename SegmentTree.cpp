#include<bits/stdc++.h>
using namespace std;

int CST(int start, int end, int ind, int arr[], int tree[])
{
	if(start == end)
	{
		tree[ind] = arr[start];
		return tree[ind];
	}

	int mid = (start + end) / 2;

	tree[ind] = CST(start, mid, 2*ind + 1, arr, tree)  + CST(mid + 1, end, 2*ind + 2, arr, tree);

	return tree[ind];
}

int getSumRec(int l, int r, int start, int end, int ind, int tree[]){
	if(end < l || start > r)
		return 0;
	if(l <= start &&  r >= end)
		return tree[ind];

	int mid = (start + end) / 2;

	return getSumRec(l, r, start, mid, 2 * ind + 1, tree)
		   + getSumRec(l, r, mid + 1, se, 2 * ind + 2, tree);
}

int main(){

}