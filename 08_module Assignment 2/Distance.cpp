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

    int t;
    cin >> t;
    while (t--){
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
