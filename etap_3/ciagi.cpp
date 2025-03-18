#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){

    int c = gcd(a,b);

    return a * b / c;
}

int list_lcm(int lista_liczb[], int n){
    int result = lista_liczb[0];

    for(int i=1;i<n;i++){
        result = lcm(result, lista_liczb[i]);
    }

    return result;
}

int main(){

    int n;
    cin >> n;

    int wykladniki[n];
    int mianowniki[n];

    for(int i=0;i<n;i++){
        cin >> wykladniki[i] >> mianowniki[i];
    }

    int nww = list_lcm(mianowniki,n);

    vector<int> output;
    int num_of_absent = 0;

    int prev_element = (nww / mianowniki[0]) * wykladniki[0];
    for(int i=1;i<n;i++){
        int current_element = (nww / mianowniki[i]) * wykladniki[i];

        for(int j=prev_element+1; j<current_element; j++){
            num_of_absent += 1;
            output.push_back(j);
        }

        prev_element = current_element;
    }

    cout << num_of_absent << endl;
    for(int i=0;i<num_of_absent;i++){
        int nwd = gcd(output[i], nww);
        cout << output[i]/nwd << " " << nww/nwd << endl;
    }

    return 0;
}
