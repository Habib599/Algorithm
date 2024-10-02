#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
bool visitedt[N];

void dfs(int u)
{
    visitedt[u] = 1;
    cout << u <<" ";
    for (int v : adj_list[u]) 
    {
        if (visitedt[v] == 0)
        {
            dfs(v);
        }
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
    queue<int>q;
    int cc=0;
    for (int i = 1; i <=n; i++)
    {
        if(visited[i]) continue;
        q.push(i);
        bfs(i);
        cc++;
    }
    cout<<cc<<endl;
    int j=1;
    while (!q.empty()) 
    {
        cout <<"Component "<< j<<" : ";
        dfs(q.front());
        cout<<endl;
        j++;
        q.pop();
    }
    return 0;
}