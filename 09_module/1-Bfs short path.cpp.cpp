#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj_list[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src]=0;
    parent[src]=-1;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        // cout <<"Node: "<< head << endl;
        for (int node : adj_list[head]) 
        {
            if (visited[node])  continue;
            
            q.push(node);
            visited[node] = true;
            level[node]=level[head]+1;
            parent[node]=head;
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
    int s,d;
    cin >>s>>d;
    bfs(s);
    cout<<"Distance : "<< level[d]<< endl;
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<"parent of "<<i<<": "<<parent[i];
    //     cout<< endl;
    // }
    vector<int>path;
    int current=d;
    while (current!=-1)
    {
        path.push_back(current);
        current=parent[current];
    }
    cout<<"path : ";
    reverse(path.begin(),path.end());
    for(int node: path)
    {
        cout<< node<< " ";
    }

    return 0;
}