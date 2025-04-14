#include<bits/stdc++.h>
#define pair pair<int, int>
using namespace std;
const int N = 1005;
const int INF = 1e9+10;
vector<pair> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);
void dijkstra(int source)
{
    priority_queue<pair, vector<pair>, greater<pair>> pq;
    dist[source] = 0;
    pq.push({dist[source],source});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for(pair vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v]) continue;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int s,t;
    cin>>s>>t;
    dijkstra(s);
    while(t--){
        long long int dnode,egw;
        cin>>dnode>>egw;
        cout << (dist[dnode] <= egw ? "YES" : "NO") << endl;
    }
    return 0;
}