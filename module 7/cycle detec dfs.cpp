#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

bool dfs(int node, int p=-1)
{
    bool cycleExits= false;
    visited[node] = true;
    // cout << "node "<< node << endl;
    for (int v : adj[node]) 
    {
        if(v==p) continue;
        if (visited[v]) return true;
        cycleExits |= dfs(v,node);
    }
    return cycleExits;
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
    if(dfs(1))
    {
        cout << "cycle detected"<<endl;
    }
    else
        cout << "no cycle detected"<<endl;
    return 0;
}