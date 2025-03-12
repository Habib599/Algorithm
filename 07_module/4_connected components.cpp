#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool visited[N];
vector<int> components[N];
int cc=0;

void dfs(int s){
    visited[s]=true;
    components[cc].push_back(s);
    for( int v: adj[s]){
        if(!visited[v]) 
            dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
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
        adj[s].push_back(v);
        adj[v].push_back(s);
    }
    
    for (int i = 1; i <=n; i++){
        if(!visited[i]){
            cc++;
            dfs(i);
        }
    }
    //cout<< "component: "<<cc<<endl;
     // Print the components
     for (int i = 1; i <= cc; i++) {
        cout << "component " << i << ":";
        for (int v : components[i]) {
            cout << " " << v;
        }
        cout << endl;
    }
    return 0;
}