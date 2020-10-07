#include<bits/stdc++.h>
using namespace std;

// Using memoization

int matrixChainMultiplication_Memo(int *arr, int i, int j)  {

	int dp[100][100];
	for(int i=0;i<100;i++) {
		for(int j=0;j<100;j++) {
			dp[i][j] = -1;
		}
	}
	
	if(i >= j) {
		return 0;
	}
	
	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	
	int min = INT_MAX;
	for(int k=i;k<j;k++) {
		int temp = matrixChainMultiplication_Memo(arr, i, k) + matrixChainMultiplication_Memo(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
	if(temp < min) {
		min = temp;
		dp[i][j] = min;
	}
	}
	return min;
}

// Using recursion

int matrixChainMultiplication(int *arr, int i, int j) {
	if(i >= j) {
		return 0;
	}
	int min = INT_MAX;
	for(int k=i;k<j;k++) {
		int temp = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		if(temp < min) {
			min = temp;
		}
	}
	return min;
}

int main() {
	int arr[100], n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int ans = matrixChainMultiplication_Memo(arr, 1, n-1);
	cout<<"Minimum cost using Memoization will be: "<<ans<<endl;
	int ans1 = matrixChainMultiplication(arr, 1, n-1);
	cout<<"Minimum cost using Recursion will be: "<<ans1<<endl;
	return 0;
}
