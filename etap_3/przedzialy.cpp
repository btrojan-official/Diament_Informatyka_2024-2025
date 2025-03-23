#include <bits/stdc++.h>
using namespace std;

struct Przedzial{
    int a;
    int b;
};

bool compare(const Przedzial& a, const Przedzial& b){
    if (a.a != b.a) return a.a < b.a;   // Sort by `a` ascending
    return a.b > b.b;                   // Sort by `b` descending if `a` values are equal
}


int main(){
    int x, y;
    cin >> x >> y;

    vector<Przedzial> all(x);

    unsigned int p=6;
    int a,b;
    for(int i=0;i<x;i++){
        do{
            p = (p*134775813+1) % 4294967296;
            a = p % y;
            p = (p*134775813+1) % 4294967296;
            b = p % y;
        } while (b<=a);
        Przedzial prz;
        prz.a = a;
        prz.b = b;
        all[i] = prz;
        cout << a << " " << b << endl;
    }

    sort(all.begin(), all.end(), compare);
    vector<int> opened_ends;

    int current = 0;
    int maxx = 0;

    for(int i=0;i<all.size();i++){
        sort(opened_ends.begin(), opened_ends.end(), greater<int>());

        while(opened_ends.size()>0 && opened_ends[opened_ends.size()-1] < all[i].a){
            opened_ends.pop_back();
        }
        current = opened_ends.size();
        if(current > maxx) maxx = current;

        opened_ends.push_back(all[i].b);
    }

    cout << maxx;


    return 0;
}
