#include <bits/stdc++.h>
using namespace std;

int countDigits(long long n){
    if (n == 0) return 1;
    return log10(abs(n)) + 1;
}

string lambda(long long n, int len, long long tab[], string history, int idx){

    if(n==0 && len <=0){
        return history;
    }
    if(len <= 0){
        return "ERROR";
    }

    vector<string> opt;

    for(int i=idx; i>=0;i--){
        if(tab[i] <= n){
            opt.push_back(lambda(n - tab[i], len-1, tab, history+to_string(i), i));
        }
    }

    long long maxx = 0;
    for(int i=0;i<opt.size();i++){
        if(opt[i]!="ERROR" && maxx < stoll(opt[i])) maxx = stoll(opt[i]);
    }

    return to_string(maxx);
}

int main(){

    long long n;
    cin >> n;

    int len = countDigits(n);

    long long tab[10];

    for(int i=0; i<10;i++){
        tab[i] = pow(i, len);
    }

    cout << lambda(n, len, tab, "", 9);

    return 0;
}
