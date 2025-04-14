#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj_list[u]) {
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
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
  
    int root;
    cin >> root;

    bfs(root);
    int found=0;
    for (int i = 0; i < n; i++){
        if (level[i] == 1)
            found++;
    }

    cout << found<< endl;
    return 0;
}
