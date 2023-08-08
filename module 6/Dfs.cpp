#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
vector<int> adj[N];

void dfs(int u)
{
    visited[u] = 1;
    cout << "node "<< u << endl;
    for (int v : adj[u]) 
    {
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }
}
int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    dfs(1);
    return 0;
}