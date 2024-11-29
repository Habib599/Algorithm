#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 1e3+5;
const int INF = 1e9+5;

vector<pii> adj_list[N];
vector<int>dist(N, INF);
vector<bool> visited(N);
// bool visited[N];


void dijkstra(int src)
{
    priority_queue<pii,vector<pii>, greater<pii>>pq;
    dist[src]=0;
    pq.push({dist[src],src});

    while(!pq.empty())
    {
        int pnode=pq.top().second;
        pq.pop();
        visited[pnode]=true;

        for(pii vpair: adj_list[pnode])
        {
            int cnode=vpair.first;
            int w= vpair.second;

            if(visited[cnode]) continue;

            if(dist[cnode] > dist[pnode]+w)
            {
                dist[cnode]=dist[pnode]+w;
                pq.push({dist[cnode],cnode});
            }
        }
    }
}
int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++)
    {
        int u, v,w ;
        cin >> u >> v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    int s,d;
    cin>>s>>d;
    dijkstra(s);
    
    for (int i = 1; i <=n; i++)
    {
        cout<<"distance of node "<<i<<": ";

        cout<< dist[i]<< endl;
    }
    cout<< dist[d]<< endl;

    return 0;
}