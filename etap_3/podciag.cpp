#include <bits/stdc++.h>
using namespace std;

int n;
int tab[101];

int highest_first_num = -1;
string history = "";

int is_first(int num){
    if (num<2) return false;
    for(int i=2;i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}

int check(int add, int multiply, int id, string hist){

    if (is_first(add+multiply+tab[id]) && add+multiply+tab[id] > highest_first_num){
        highest_first_num = add+multiply+tab[id];
        history = hist + "+" + to_string(tab[id]);
        cout << "add: " << add << " multiply: " << multiply << " id: " << id << " tab[id]: " << tab[id] << endl;
    }
    if (is_first(add+(multiply*tab[id])) && add+(multiply*tab[id]) > highest_first_num){
        highest_first_num = add+(multiply*tab[id]);
        history = hist + "*" + to_string(tab[id]);
        cout << "add: " << add << " multiply: " << multiply << " id: " << id << " tab[id]: " << tab[id] << endl;
    }

    if (id < n-1){
        check(add+multiply, tab[id], id+1, hist + "+" + to_string(tab[id]));
        check(add, multiply * tab[id], id+1, hist + "*" + to_string(tab[id]));
        check(0, tab[id], id+1, to_string(tab[id]));
    }
}

int main(){
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> tab[i];
    }
    check(0, tab[0], 1, to_string(tab[0]));

    cout << highest_first_num << endl;
    cout << history << endl;

    return 0;
}
