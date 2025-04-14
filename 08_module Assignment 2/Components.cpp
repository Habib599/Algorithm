#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

int dfs(int u) {
    visited[u] = true;
    int node = 1;  

    for (int v : adj[u]) {
        if (!visited[v]) 
            node += dfs(v);
    }
    return node;
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> v;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int cnode = dfs(i);
            if (cnode > 1) 
                v.push_back(cnode);
        }
    }

    sort(v.begin(), v.end());

    for (int cnode : v) {
        cout << cnode << " ";
    }

    return 0;
}
