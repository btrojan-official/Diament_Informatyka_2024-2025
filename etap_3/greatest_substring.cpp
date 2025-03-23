#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin >> n;

    vector<char> best;
    best.push_back(n[0]);

    for(int i=1;i<n.length();i++){
        while(true){
            int j=best.size()-1;
            if(j==-1 || best[j]>=n[i]){
                best.push_back(n[i]);
                break;
            }else{
                best.pop_back();
            }
        }
    }

    for(int i=0;i<best.size();i++){
        cout << best[i];
    }

    return 0;
}

