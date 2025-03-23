#include <bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    int parent;
    int current_cost;
    bool explored;
    vector<int> neighbours;
    vector<int> distances;
};

vector<Node> nodes;
vector<int> entities;

int main(){
    int n, e, s, start, target;
    cin >> n >> e >> s >> start >> target;

    for(int i=0;i<n;i++){
        Node node;
        node.id = i;
        node.parent = -1;
        node.current_cost = INT_MAX;
        node.explored = false;

        nodes.push_back(node);
    }

    nodes[start].current_cost = 0;

    for(int i=0;i<e;i++){
        int u, v, dist;
        cin >> u >> v >> dist;

        nodes[u].neighbours.push_back(v);
        nodes[u].distances.push_back(dist);

        nodes[v].neighbours.push_back(u);
        nodes[v].distances.push_back(dist);
    }

    for(int i=0;i<s;i++){
        int entity;
        cin >> entity;
        entities.push_back(entity);
    }

    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(i!=j){
                int u = entities[i];
                int v = entities[j];

                nodes[u].neighbours.push_back(v);
                nodes[u].distances.push_back(0);
            }
        }
    }

    while(!nodes[target].explored){
        int min_cost = INT_MAX; int v = -1;

        for(int i=0;i<n;i++){
            if(nodes[i].current_cost < min_cost && !nodes[i].explored){
                min_cost = nodes[i].current_cost;
                v = i;
            }
        }

        nodes[v].explored = true;

        if(v == target) break;

        for(int i=0;i<nodes[v].neighbours.size();i++){
            int u = nodes[v].neighbours[i];
            int len = nodes[v].distances[i];

            if(min_cost + len < nodes[u].current_cost){
                nodes[u].current_cost = min_cost + len;
                nodes[u].parent = v;
            }
        }
    }

    cout << nodes[target].current_cost;

    return 0;
}
