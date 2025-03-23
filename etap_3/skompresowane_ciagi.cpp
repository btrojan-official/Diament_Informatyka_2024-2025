#include <bits/stdc++.h>
using namespace std;

string decomp(string b){
    int num = b[1] - '0';
    string opt = "";
    string sub = b.substr(2, b.length()-3);
    for(int i=0;i<num;i++){
        opt += sub;
    }

    return opt;
}

int main(){

    string c;
    cin >> c;

    int start = -1;

    for(int i=0;i<c.length();i++){
        if(c[i] == '[') start = i;
        else if(c[i] == ']'){
            c = c.substr(0, start) + decomp(c.substr(start, i - start + 1)) + c.substr(i+1, c.length() - i - 1);
            i = -1;
        }
    }

    cout << c;

    return 0;
}
