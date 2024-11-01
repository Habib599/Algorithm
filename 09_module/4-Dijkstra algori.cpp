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
        int fnode=pq.top().second;
        pq.pop();
        visited[fnode]=true;

        for(pii vpair: adj_list[fnode])
        {
            int snode=vpair.first;
            int w= vpair.second;

            if(visited[snode]) continue;

            if(dist[snode] > dist[fnode]+w)
            {
                dist[snode]=dist[fnode]+w;
                pq.push({dist[snode],snode});
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
        int fnode, snode,w ;
        cin >> fnode >> snode>>w;
        adj_list[fnode].push_back({snode,w});
        adj_list[snode].push_back({fnode,w});
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