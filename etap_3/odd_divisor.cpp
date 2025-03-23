#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long sum = 0;
    for(long long i=1;i<n+1;i++){
        long long l = i;
        while(l%2==0) l /= 2;
        sum += l;
    }

    cout << sum;

    return 0;
}
