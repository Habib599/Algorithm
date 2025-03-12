#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s]=0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        cout <<"Node: "<< u <<"  "<< level[u]<<" level"<< endl;
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
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int s, v;
        cin >> s >> v;
        adj_list[s].push_back(v);
        adj_list[v].push_back(s);
    }
    
    bfs(1);

    // for (int i = 1; i <=n; i++){
    //     cout<< "level of "<<i<<": "<< level[i]<<endl;
    // }
    
    return 0;
}