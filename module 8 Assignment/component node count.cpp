#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];

int bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int node = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        node++;

        for(int v : adj[x])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return node;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> v;

    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            int cnode = bfs(i);
            if(cnode > 1)
            {
                v.push_back(cnode);
            }
        }
    }

    sort(v.begin(), v.end());

    for(int cnode : v)
    {
        cout << cnode << " ";
    }

    return 0;
}