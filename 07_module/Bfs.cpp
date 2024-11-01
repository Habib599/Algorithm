#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout <<"Node: "<< head << endl;
        for (int node : adj_list[head]) 
        {
            if (visited[node])  continue;
            
            q.push(node);
            visited[node] = true;
            //level[node]= level[head]+1;
        }
    }

}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int src, v;
        cin >> src >> v;
        adj_list[src].push_back(v);
        adj_list[v].push_back(src);
    }
    
    bfs(1);
    return 0;
}