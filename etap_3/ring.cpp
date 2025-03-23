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
    string s;
    cin >> s;

    vector<string> solutions;

    for(int i=0;i<s.length();i++){
        for(int j=1;j<s.length();j++){
            solutions.push_back(test(s, i, j));
        }
    }
    sort(solutions.begin(), solutions.end());
    cout << solutions[0];

    return 0;
}


