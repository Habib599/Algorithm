#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5+7;
const int INF = 1e9+7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
int d[N];
int n,m;

void bellman_ford(int s){
	fill(d, d + N, INF);
	d[s] = 0;

	for(int i=1; i<n; i++){//node
		for(auto edge: list_of_edges){//edge
			int u = edge.first.first;
			int v = edge.first.second;
			int w = edge.second;

			if(d[u]!=INF && d[v] > d[u]+w)
				d[v] = d[u] + w;
		}
	}
}// O(nm)// O(n^2)

int main(){

    cin >> n >> m;

    while(m--){
    	int u,v,w;
    	cin >> u >> v >> w;
    	//g[u].push_back({v,w});
    	list_of_edges.push_back({{u,v},w});
    }

    bellman_ford(1);

    for(int i=1;i<=n;i++){
    	cout << "D of " << i << ": " << d[i] << endl;
    }
 	return 0;   
}
