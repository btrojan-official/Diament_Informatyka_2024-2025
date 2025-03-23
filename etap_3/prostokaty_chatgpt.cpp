#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int a, b, h, w, index;
    int area() const { return (b - a) * h; }
};

bool compareByEnd(const Rectangle &r1, const Rectangle &r2) {
    return r1.b < r2.b;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Rectangle> rectangles(N);

    for (int i = 0; i < N; i++) {
        cin >> rectangles[i].a >> rectangles[i].b >> rectangles[i].h >> rectangles[i].w;
        rectangles[i].index = i;
    }

    sort(rectangles.begin(), rectangles.end(), compareByEnd);

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    vector<vector<bool>> chosen(N + 1, vector<bool>(K + 1, false));

    for (int i = 1; i <= N; i++) {
        int cost = rectangles[i - 1].w;
        int area = rectangles[i - 1].area();
        int lastCompatible = -1;

        for (int j = i - 1; j >= 1; j--) {
            if (rectangles[j - 1].b <= rectangles[i - 1].a) {
                lastCompatible = j;
                break;
            }
        }

        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= cost) {
                int newArea = area + (lastCompatible != -1 ? dp[lastCompatible][j - cost] : 0);
                if (newArea > dp[i][j]) {
                    dp[i][j] = newArea;
                    chosen[i][j] = true;
                }
            }
        }
    }

    vector<int> result;
    int j = K;
    for (int i = N; i >= 1; i--) {
        if (chosen[i][j]) {
            result.push_back(rectangles[i - 1].index);
            j -= rectangles[i - 1].w;
            while (i > 1 && rectangles[i - 2].b > rectangles[i - 1].a) i--;
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int idx : result) {
        cout << idx << "\n";
    }

    return 0;
}

