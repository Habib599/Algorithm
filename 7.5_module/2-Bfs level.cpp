#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src]=0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        // cout <<"Node: "<< u << endl;
        for (int v : adj_list[u]) {
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                level[v]= level[u]+1;
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bfs(1);

    int search;
    cin>> search;
    for (int i = search; i <=n; i++){
            cout<< "Level of "<<i<<" = "<< level[i]<<endl;
    }
    
    return 0;
}