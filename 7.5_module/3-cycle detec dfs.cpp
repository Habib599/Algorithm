#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p=-1){
    visited[u] = true;
    // cout << "u "<< u << endl;
    for (int v : adj[u]) {
        if(v == p) continue;
        if (visited[v] || dfs(v, u)) return true;
    }   
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int node, v;
        cin >> node >> v;
        adj[node].push_back(v);
        adj[v].push_back(node);
    }

    if(dfs(1)) cout << "YES"<<endl;
    else cout << "NO"<<endl;

    return 0;

}