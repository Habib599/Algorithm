#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjmat[N][N];

int main() 
{
    int n;
    cin >> n; 
    
    //vector<vector<int>> adjmat(n + 1, vector<int>(n + 1)); // Adjust for 1-based indexing
    
    // input the adjacency matrix
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            cin >> adjmat[i][j];
        }
    }
    
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjlist(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (adjmat[i][j] == 1) 
            {
                adjlist[i].push_back(j); // Adjusted index
            }
        }
    }

    // print
    for (int i = 1; i <= n; i++) 
    {
        cout << "List " << i << " : ";
        for (int j : adjlist[i]) 
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
