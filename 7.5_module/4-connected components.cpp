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

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
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
    cout<<cc<<endl;
    return 0;
}