#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
bool visited[N];

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    int root;
    cin >> root;

    int found = 0;
    for (int node : adj_list[root])
    {
        found++; // Increment for each directly connected house
    }

    cout << found << endl;

    return 0;
}
