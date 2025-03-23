#include <bits/stdc++.h>
using namespace std;

string test(string s, int o, int p){
    string opt = "";
    opt += s[o];

    int prev_id = o;
    for(int i=1;i<s.length(); i++){
        prev_id += p;
        prev_id %= s.length();
        opt += s[prev_id];
    }

    return opt;
}

int main(){
    long long sum;
    cin >> sum;

    vector<long long> partials;

    long long prev = 1;
    for(int j=1;prev<=sum;j++){
        partials.push_back(prev);
        prev *= 10;
        prev++;
    }

    string opt = "";
    for(int i=partials.size()-1;i>=0;i--){
        int num = floor(sum / partials[i]);
        if(num>9){
            cout << -1;
            return 0;
        }else{
            opt += ('0' + num);
            sum %= partials[i];
        }
    }

    cout << opt;

    return 0;
}



