#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int src){
    queue<int> q;
    stack<int>st;
    q.push(src);
    visited[src] = true;
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
        // cout<< u <<" ";
        st.push(u);
        for (int v : adj[u]) {
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);
    return 0;
}