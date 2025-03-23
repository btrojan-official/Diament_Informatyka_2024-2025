#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int tab[n];

    for(int i=0; i<n;i++){
        cin >> tab[i];
    }

    int curr = 1;

    //cout << endl << endl;

    while(true){
        vector<int> dp(curr+1, 0);
        dp[0] = 1;

        for(int a : tab){
            for(int j=curr; j>=a;j--){
                dp[j] = max(dp[j], dp[j-a]);
            }
        }

        //for(int j=0; j<=curr;j++){
        //    cout << dp[j] << " ";
        //}

        if(dp[curr]==0){
            cout << curr;
            break;
        }else{
            //cout << endl << curr;
            curr = curr+1;
        }
    }

    return 0;
}



