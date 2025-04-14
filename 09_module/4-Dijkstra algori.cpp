#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e3+5;
const int INF = 1e9+5;

vector<pii> adj[N];
vector<int>dist(N, INF);
vector<bool> visited(N,false);
// bool visited[N];


void dijkstra(int s){
    priority_queue<pii,vector<pii>, greater<pii>>pq;
    pq.push({0,s});
    dist[s] = 0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(visited[u]) continue;
        visited[u]=true;

        for(pii vpair: adj[u]){
            int v=vpair.first;
            int w= vpair.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v,w ;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int s,d;
    cin>>s>>d;
    dijkstra(s);
    for (int i = 1; i <=n; i++){
        cout<<"distance of node "<<i<<": "<< dist[i]<< endl;
    }
    cout<< dist[d]<< endl;

    return 0;
}