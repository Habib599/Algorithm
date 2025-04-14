#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N];

int main() {
    int n;
    cin >> n; 
    
    //vector<vector<int>> adj(n + 1, vector<int>(n + 1)); // Adjust for 1-based indexing
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    
    // Convert matrix to list
    vector<vector<int>> adjlist(n + 1); //2D vector
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (adj[i][j] == 1) {
                adjlist[i].push_back(j); // Adjusted index
            }
        }
    }

    // print list
    for (int i = 1; i <= n; i++) {
        cout << "List " << i << " : ";
        for (int j : adjlist[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
