#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjmat[N][N];

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adjList(n + 1); //2D vector
    while(e--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    // convert list to matrix
    for (int i = 1; i <= n; i++) {
        for (int j : adjList[i]) {
            adjmat[i][j] = 1;
        }
    }
    // print
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
