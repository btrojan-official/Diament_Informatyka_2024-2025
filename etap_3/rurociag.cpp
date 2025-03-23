#include <bits/stdc++.h>
using namespace std;

int getMinPipes(vector<int> pipes, int S){
    vector<int>dp(S+1, INT_MAX-1);

    dp[0] = 0;

    for(int pipe : pipes){
        for(int j=S; j>=pipe; j--){
            dp[j] = min(dp[j], dp[j-pipe]+1);
        }
    }

    // for(int i=0;i<S-1;i++){
       // cout << dp[i] << " ";
    //}

    return dp[S];
}

int main(){
    int n;
    cin >> n;

    vector<int> pipes(n);

    for(int i=0;i<n;i++){
        cin >> pipes[i];
    }

    int S;
    cin >> S;

    int result = getMinPipes(pipes, S);
    if(result == INT_MAX-1){
        cout << "BRAK";
        return 0;
    }
    cout << result;

    return 0;
}
