#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

bool dfs(int node, int p=-1)
{
    bool cycle= false;
    visited[node] = true;
    // cout << "node "<< node << endl;
    for (int v : adj[node]) 
    {
        if(v==p) continue;
        if (visited[v]) return true;
        cycle |= dfs(v,node);
    }
    return cycle;
}
int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int node, v;
        cin >> node >> v;
        adj[node].push_back(v);
        adj[v].push_back(node);
    }

    bool iscycle=false;
    for (int i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        iscycle |= dfs(i);
    }
    if(iscycle)
    {
        cout << "cycle detected"<<endl;
    }
    else
        cout << "no cycle"<<endl;

return 0;
}