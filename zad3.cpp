#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int m;
	
	cin >> n >> m;
	
	int t1[n];
	int t2[m];
	int dp[n+1][m+1];
	dp[0][0] = 0;
	
	for(int i=0;i<n;i++){
		cin >> t1[i];
	} 
	for(int i=0;i<m;i++){
		cin >> t2[i];
	} 
	
	for(int i=0;i<n+1;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<m+1;i++){
		dp[0][i] = 0;
	}
	
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(t1[i-1] == t2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	cout << dp[n][m];
	

	return 0;
}
