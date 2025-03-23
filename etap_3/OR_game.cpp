#include <bits/stdc++.h>
using namespace std;

int main(){
    int g, t;
    cin >> g >> t;

    int tab[g];

    for(int i=0;i<g;i++){
        cin >> tab[i];
    }

    for(int i=0;i<32;i++){
        if(0==(t & (1 << i))){
            for(int j=0;j<g;j++){
                if(0!=(tab[j] & (1 << i))) tab[j] = 0;
            }
        }
    }

    vector<int> counts(32, INT_MAX);
    for(int i=0;i<32;i++){
        if(0!=(t & (1 << i))){
            for(int j=0;j<g;j++){
                if(0!=(tab[j] & (1 << i))){
                    if(counts[i]==INT_MAX){
                        counts[i] = 0;
                    }counts[i]++;
                }
            }
        }
    }

    int minn = *min_element(counts.begin(), counts.end());

    cout << minn;
}
