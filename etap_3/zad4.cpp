#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2;
    cin >> n1 >> n2;

    vector<long long> vec1(n1);
    vector<long long> vec2(n2);

    vector<vector<long long>>dp (n1+1, vector<long long>(n2+1, -INT_MAX));

    // for(int i=0;i<n1;i++) dp[i][0] = 0;
    // for(int i=0;i<n2;i++) dp[0][i] = 0;

    // for(int i=0;i<n2;i++) dp[0][i] = 0;

    for(int i=0;i<n1;i++) cin >> vec1[i];
    for(int i=0;i<n2;i++) cin >> vec2[i];

    dp[1][1] = vec1[0]*vec2[0];

    for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
            dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], max(dp[i-1][j-1] + (vec1[i-1]*vec2[j-1]),max(dp[i-1][j-1], dp[i][j]))));
        }
    }

    for(int i=0;i<n1+1;i++){
        for(int j=0;j<n2+1;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n1][n2];

    return 0;
}
