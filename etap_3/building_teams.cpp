#include <bits/stdc++.h>
using namespace std;

vector<int> teams;
vector<vector<int>> adj;
set<int> unassigned;

void dfs(int u, int team){
    teams[u] = team;
    unassigned.erase(u);
    int new_team = team == 1 ? 2 : 1;

    for(int i=0;i<adj[u].size();i++){
        if(teams[adj[u][i]] == 0){
            dfs(adj[u][i], new_team);
        }else if(teams[adj[u][i]] != new_team){
            teams[adj[u][i]] = 3;
        }
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    adj.resize(n);
    teams.assign(n, 0);

    for(int i=0;i<n;i++) unassigned.insert(i);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(!unassigned.empty()){
        dfs(*unassigned.begin(), 1);
    }

    string opt = "";
    for(int i=0;i<teams.size();i++){
        if(teams[i] == 3){
            opt = "IMPOSSIBLE";
            break;
        }
        opt += to_string(teams[i]) + " ";
    }

    cout << opt;

    return 0;
}
