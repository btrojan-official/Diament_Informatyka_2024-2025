#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pipes(n);
    for(int i=0;i<n;i++){
        cin >> pipes[i];
    }

    int s;
    cin >> s;

    vector<int> dp(s+1, INT_MAX-2);
    dp[0] = 0;

    for(int pipe : pipes){
        for(int j=s; j>=pipe; j--){
            dp[j] = min(dp[j], dp[j-pipe] + 1);
        }
    }

    cout << dp[s];

    return 0;
}

