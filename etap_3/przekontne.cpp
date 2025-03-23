#include <bits/stdc++.h>
using namespace std;

long long tab[41][41];
int values[1612];

void go(int x, int y, int direction, int steps, int start_id){
    if (steps == 0) return;

    // cout << direction << " " << start_id << endl;

    if (direction == 0){
        for(int j=y-1; j>=y-steps;j--){
            tab[j][x] = values[++start_id];
        }
        go(x, y-steps, 1, steps, start_id);
    }

    if (direction == 1){
        for(int i=x+1; i<=x+steps;i++){
            tab[y][i] = values[++start_id];
        }
        go(x+steps, y, 2, steps-1, start_id);
    }

    if (direction == 2){
        for(int j=y+1; j<=y+steps;j++){
            tab[j][x] = values[++start_id];
        }
        go(x, y+steps, 3, steps, start_id);
    }

    if (direction == 3){
        for(int i=x-1; i>=x-steps;i--){
            tab[y][i] = values[++start_id];
        }
        go(x-steps, y, 0, steps-1, start_id);
    }
}

int main(){
    int n;
    cin >> n;

    int delay;
    cin >> delay;

    values[0] = 1;
    values[1] = 1;

    for(int i=2;i<n*n+delay;i++){
        values[i] = values[i-2] % 10 + values[i-1];
    }

    delay-=2;

    for(int i=0;i<n;i++){
        delay++;
        tab[0][i] = values[delay];
    }

    go(n-1, 0, 2, n-1, delay);

    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += tab[i][i];
    }
    for(int i=0;i<n;i++){
        sum += tab[i][n-i-1];
    }
    if(n%2!=0){
        int ii = (n-1)/2;
        sum -= tab[ii][ii];
    }

    cout << sum << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << tab[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}
