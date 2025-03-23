#include <bits/stdc++.h>
using namespace std;

int tab[1000001];

bool is_primary(int n){
    if(n==0 || n==1) return false;
    if(n==2) return true;

    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int leng(char look_for, long long n){
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n;i++){
        cin >> tab[i];
    }

    vector<int> dp(n, INT_MAX-1);
    dp[0] = 0;

    vector<int> primary;
    int p;
    for(int p;p<=1000000;p++){
        if(is_primary(p)){
            primary.push_back(p);
        }
    }

    for(int i=0;i<n;i++){
        for(int p: primary){
            if(tab[i]%p == 0 && i+p<n){
                dp[i+p] = min(dp[i+p], dp[i]+1);
            }
        }
    }

    cout << dp[n-1];

    return 0;
}

