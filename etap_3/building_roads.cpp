#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> explored;
set<int> unexplored;

void DFS(int start) {
    stack<int> s;
    s.push(start);
    explored[start] = true;
    unexplored.erase(start);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        for (int neighbor : adj[curr]) {
            if (!explored[neighbor]) {
                explored[neighbor] = true;
                unexplored.erase(neighbor);
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    explored.assign(n, false);
    for (int i = 0; i < n; i++) unexplored.insert(i);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // convert to 0-based index
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int countt = 0;
    vector<int> s_p, e_p;

    while (!unexplored.empty()) {
        int start = *unexplored.begin();
        DFS(start);

        if (!unexplored.empty()) {
            int next = *unexplored.begin();
            countt++;
            s_p.push_back(start + 1);
            e_p.push_back(next + 1);
        }
    }

    cout << countt << endl;
    for (int i = 0; i < s_p.size(); i++) {
        cout << s_p[i] << " " << e_p[i] << endl;
    }

    return 0;
}
