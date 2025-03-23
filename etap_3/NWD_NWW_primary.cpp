#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_primary(ll a){

    for(int i=2;i*i<a;i++){
        if(a % i == 0) return false;
    }

    return true;
}

set<ll> dzielniki(ll a){

    set<ll> dziel_primary;

    for(int i=2;i*i<a;i++){
        while(a % i == 0) {
            dziel_primary.insert(i);
            a /= i;
        }
    }

    if(a!=1) dziel_primary.insert(a);

    return dziel_primary;
}

ll nwd(ll a, ll b){
    while(b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll nww(ll a, ll b){
    return a*b/nwd(a,b);
}

int main(){

    ll n, m;
    cin >> n >> m;

    cout << "NWD: " << nwd(n,m) << ", NWW: " << nww(n,m) << endl;
    cout << "Is prmiary: " << is_primary(n) << ", " << is_primary(m) << endl;

    set<ll> n_dzielniki = dzielniki(n);
    set<ll> m_dzielniki = dzielniki(m);

    cout << "Dzielniki n: ";
    for(ll val : n_dzielniki) cout << val << " ";

    cout << endl << "Dzielniki m: ";
    for(ll val : m_dzielniki) cout << val << " ";

    return 0;
}
