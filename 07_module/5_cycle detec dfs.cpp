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
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bool iscycle=false;
    // for (int i = 1; i <=n; i++){
    //     if(!visited[i])
    //         iscycle |= dfs(i);
    // }

    if(dfs(1)) cout << "cycle detected"<<endl;
    else        cout << "no cycle"<<endl;

return 0;
}