#include <bits/stdc++.h>
using namespace std;

string tab[1000001];

long long leng(char look_for, long long n){
    long long countt = 0;
    long long max_count = 0;
    bool good = false;

    for(long long i=0;i<n;i++){
        for(long long j=0;j<tab[i].length();j++){
            if(tab[i][j] == look_for){
                countt += 1;
                if(max_count < countt) max_count = countt;
                good = true;
                break;
            }
        }
        if(!good) countt = 0;
        good = false;
    }

    return max_count;
}

int main(){

    long long n;
    cin >> n;

    for(int i=0; i<n;i++){
        cin >> tab[i];
    }

    long long maxx = 0;
    for(int i=0;i<10;i++){
        long long l = leng('0' + i, n);
        if(l > maxx){
            maxx = l;
        }
    }

    cout << maxx;

    return 0;
}

