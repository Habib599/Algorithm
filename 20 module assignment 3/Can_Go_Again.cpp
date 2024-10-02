#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18+7;

class Edge 
{
public:
    long long int u;
    long long int v;
    long long int w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main() 
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        edges.push_back(ed);
    }

    long long int source;
    cin >> source;

    long long int t;
    cin >> t;
    while (t--) 
    {
        long long int dest;
        cin >> dest;

        vector<long long int> dist(n + 1, INF);
        dist[source] = 0;

        // Relaxation 
        for (long long int i = 0; i < n - 1; i++) 
        {
            for (const Edge& edge : edges) 
            {
                long long int u = edge.u;
                long long int v = edge.v;
                long long int w = edge.w;
                if (dist[u] != INF && dist[u] + w < dist[v]) 
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Chake negative cycle
        bool negative_cycle = false;
        for (const Edge edge : edges) 
        {
            long long int u = edge.u;
            long long int v = edge.v;
            long long int w = edge.w;
            if (dist[u] != INF && dist[u] + w < dist[v]) 
            {
                negative_cycle = true;
                break;
            }
        }

        if (negative_cycle) 
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        } 
        else 
        {
            if (dist[dest] == INF) 
            {
                cout << "Not Possible" << endl;
            } 
            else
            {
                cout << dist[dest] << endl;
            }
        }
    }

    return 0;
}
