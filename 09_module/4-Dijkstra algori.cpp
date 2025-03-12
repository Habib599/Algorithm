#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e3+5;
const int INF = 1e9+5;

vector<pii> adj[N];
vector<int>dist(N, INF);
vector<bool> visited(N);
// bool visited[N];


void dijkstra(int s){
    priority_queue<pii,vector<pii>, greater<pii>>pq;
    dist[s]=0;
    pq.push({dist[s],s});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;

        for(pii vpair: adj[u]){
            int v=vpair.first;
            int w= vpair.second;

            if(visited[v]) continue;

            if(dist[v] > dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++){
        int u, v,w ;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int s,d;
    cin>>s>>d;
    dijkstra(s);
    for (int i = 1; i <=n; i++){
        cout<<"distance of node "<<i<<": ";
        cout<< dist[i]<< endl;
    }
    cout<< dist[d]<< endl;

    return 0;
}