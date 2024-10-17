#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int m;
	
	cin >> n >> m;
	
	int t1[n];
	int t2[m];
	int dp[n][m];
	dp[0][0] = 0;
	
	for(int i=0;i<n;i++){
		cin >> t1[i];
	} 
	for(int i=0;i<m;i++){
		cin >> t2[i];
	} 
	
	for(int i=0;i<n;i++){
		dp[i][0] = t1[i]*t2[0];
	}
	for(int i=0;i<m;i++){
		dp[0][i] = t1[0]*t2[i];
	}
	
	
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j] = max(max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (t1[i]*t2[j])),dp[i-1][j-1]);
		}
	}
	
	cout << dp[n-1][m-1];
	

	return 0;
}
