#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int node : adj_list[head]) 
        {
            if (visited[node] == true) continue;
            
            q.push(node);
            visited[node] = true;
            level[node] = level[head] + 1;
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int root, search;
        cin >> root >> search;

        //reset array
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        bfs(root);

        cout << level[search] << endl;
    }

    return 0;
}
