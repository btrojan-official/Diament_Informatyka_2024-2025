#include <bits/stdc++.h>
using namespace std;

set<int> get_dzielniki(int a){
    set<int> dzielniki;

    a = abs(a);

    for(int i=1; i<=a;i++){
        if(a%i==0){
            dzielniki.insert(i);
        }
    }

    return dzielniki;
}


int main(){
    int n;
    cin >> n;

    vector<int> wsp(n);

    for(int i=0;i<n;i++){
        cin >> wsp[i];
    }

    set<int> dzielniki = get_dzielniki(wsp[n-1]);
    vector<int> opt;

    for(int dziel : dzielniki){

        int current = wsp[0];
        for(int i=1;i<n;i++){
            current = dziel * current + wsp[i];
        }
        if(current == 0){
            opt.push_back(dziel);
        }
    }

    for(int dziel : dzielniki){
        int current = wsp[0];
        for(int i=1;i<n;i++){
            current = (-dziel) * current + wsp[i];
        }
        if(current == 0){
            opt.push_back(-dziel);
        }
    }

    cout << opt.size() << endl;
    for(int i=0;i<opt.size();i++) cout << opt[i] << " ";

    return 0;
}
