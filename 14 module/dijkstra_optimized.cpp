#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e5 + 5;
vector<pii> adj[N];
vector<int> dis(N, INT_MAX);
bool visited[N];
void dijkstra(int s){
    priority_queue<pii,vector<pii>, greater<pii>>pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()){
        pii parent = pq.top();
        pq.pop();

        int parentD = parent.first;
        int parentN = parent.second;
        if (visited[parentN]) continue;
        visited[parentN] = true;

        for (pii child : adj[parentN]){
            int childN = child.first;
            int childC = child.second;
            if (parentD + childC < dis[childN]){
                dis[childN] = parentD + childC;
                pq.push({dis[childN], childN});
            }
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    while (e--){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        // adj[b].push_back({a, childC});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++){
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}