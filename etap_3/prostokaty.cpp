#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int a;
    int b;
    int h;
    int cost;
    int index;
    int area() {
        return (b-a)*h;
    }
};

bool compare(const Rect& a, const Rect& b){
    return a.b < b.b;
}

void findBest(vector<Rect> all_r, int k){
    vector<vector<int>> dp(all_r.size()+1, vector<int>(k+1, 0));
    vector<vector<bool>> chosen(all_r.size()+1, vector<bool>(k+1, false));

    for(int i=1;i<all_r.size()+1; i++){
        int cost = all_r[i-1].cost;
        int area = all_r[i-1].area();

        int lastCompatibile = -1;

        for(int j= i-1; j >= 0; j--){
            if(all_r[j-1].b <= all_r[i-1].a){
                lastCompatibile = j;
                break;
            }
        }

        for(int j=0; j<=k; j++){
            dp[i][j] = dp[i-1][j];

            if(j>= cost){
                int newArea = area + (lastCompatibile != -1 ? dp[lastCompatibile][j-cost]:0);
                if(newArea > dp[i][j]){
                    dp[i][j] = newArea;
                    chosen[i][j] = true;
                }
            }
        }
    }

    vector<int> result;
    int j = k;
    for (int i = all_r.size(); i >= 1; i--) {
        if (chosen[i][j]) {
            result.push_back(all_r[i - 1].index);
            j -= all_r[i - 1].cost;
            int z=i;
            while (i > 1 && all_r[i - 2].b > all_r[z - 1].a) i--;
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int idx : result) {
        cout << idx << "\n";
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<Rect> all_r(n);

    for(int i=0;i<n;i++){
        Rect r;
        cin >> r.a >> r.b >> r.h >> r.cost;
        r.index = i;
        all_r[i] = r;
    }

    sort(all_r.begin(), all_r.end(), compare);

    findBest(all_r, k);

    return 0;
}
