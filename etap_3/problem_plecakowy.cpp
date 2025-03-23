#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    vector<int> nag(n);
    vector<int> wag(n);

    for(int i=0;i<n;i++){
        cin >> nag[i] >> wag[i];
    }

    vector<int> dp(k+1, 0);

    for(int i=0;i<n;i++){
        int nagroda = nag[i];
        int waga = wag[i];

        for(int j=k;j>=waga;j--){
            dp[j] = max(dp[j - waga] + nagroda, dp[j]);
        }
    }

    // for(int j=0;j<k+1;j++){
    //     cout << dp[j] << " ";
    // }

    cout << dp[k];

    return 0;
}
