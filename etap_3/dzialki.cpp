#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int tab[n];
    for(int i=0;i<n;i++){
        cin >> tab[i];
    }

    int dp[n+1];
    dp[0] = 0;
    dp[1] = tab[0];
    dp[2] = max(tab[0],tab[1]);
    for(int i=3;i<n+;i++){
        dp[i] = max(dp[i-1], dp[i-2]+tab[i-1]);
    }

    for(int i=0;i<n+1;i++){
        cout << dp[i] << " ";
    }

    cout << endl<< dp[n];

    return 0;
}
