#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj[N];

int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = 1;
    // cout << "node "<< u << endl;
    for (int v : adj[u]) 
    {
        if (visited[v] == 0)
        {
            depth[v]=depth[u]+1;
            dfs(v);
            //if(height[v]+1>height[u])
               // height[u]= height[v]+1;
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
        adj[v].push_back(u);
    }
    int d;
    cin>>d;

    dfs(1);
    cout<< "Depth of " << d <<" = "<<depth[d]<<endl;
    
    
    return 0;
}