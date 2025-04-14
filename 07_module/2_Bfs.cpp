#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];
//int level[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        cout <<"Node: "<< u << endl;

        for (int v : adj_list[u]) {
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                //level[v]= level[u]+1;
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int s, v;
        cin >> s >> v;
        adj_list[s].push_back(v);
        adj_list[v].push_back(s);
    }
    
    bfs(1);
    return 0;
}