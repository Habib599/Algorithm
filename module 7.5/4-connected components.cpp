#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];

void dfs(int src)
{
    visited[src]=true;
    for( int node: adj_list[src])
    {
        if(visited[node]) continue;
        dfs(node);
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        
        for (int node : adj_list[head]) 
        {
            if (visited[node] == true)  continue;
            
            q.push(node);
            visited[node] = true;
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    int cc=0;
    for (int i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        bfs(i);
        cc++;
    }
    cout<<cc<<endl;
    return 0;
}