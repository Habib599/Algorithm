#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s]=0;
    parent[s]=-1;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        // cout <<"Node: "<< u << endl;
        for (int v : adj[u]) {
            if (visited[v])  continue;
            
            q.push(v);
            visited[v] = true;
            level[v]=level[u]+1;
            parent[v]=u;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
    while (current!=-1){
        path.push_back(current);
        current=parent[current];
    }

    cout<<"path : ";
    reverse(path.begin(),path.end());
    for(int v: path){
        cout<< v<< " ";
    }

    return 0;
}