#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    stack<int>s;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        // cout<< head <<" ";
        s.push(head);
        for (int node : adj_list[head]) 
        {
            if (visited[node] == true)  continue;
            
            q.push(node);
            visited[node] = true;
        }
    }
    while (!s.empty()) 
    {
        cout << s.top() << " ";
        s.pop();
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
    
    bfs(1);
    return 0;
}