#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int cc=0;

int dfs(int src)
{
    visited[src]=true;
    for( int node: adj_list[src])
    {
        if(visited[node]) continue;
        cc++;
        dfs(node);
    }
    return cc;
}
int main() 
{
    int n, m;
    cin >> n >> m;
    queue<int>q2;
    vector<int>q3;
    for (int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        q2.push(u);
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    while(!q2.empty())
    {
        int f=dfs(q2.front());
        // if(f==0) continue;
        q3.push_back(f);
        q2.pop();
        cc=0;
    }
    sort(q3.begin(), q3.end());
    for (int num : q3) 
    {
        cout << num << " ";
    }
    return 0;
}