#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int zaman;
    cin >> zaman;

    bfs(0);
    if(zaman==0) cout<<"0"<<endl;
    

    else{
        vector<int>v;
        for (int i = 0; i <=N; i++){
            if (level[i] == zaman)
                v.push_back(i);
        }
        if(v.empty()) 
            cout<<"-1"<<endl;
        else{
            for(int val : v)
                cout<<val<<" ";
        }
    }
    return 0;
}
