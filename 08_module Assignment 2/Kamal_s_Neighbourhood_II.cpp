#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

int dfs(int u){
    visited[u] = true;
    int house = 1;

    for (int v : adj[u]) {
        if (!visited[v])
            house += dfs(v);
    }
    return house;
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int root;
    cin >> root;

    int house = dfs(root);
    cout << house-1 << endl;

    return 0;
}
