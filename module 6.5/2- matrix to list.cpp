#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n; 
    
    vector<vector<int>> adjmat(n + 1, vector<int>(n + 1)); // Adjust for 1-based indexing
    
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
    
    // Print adjacency list
    // for (int i = 1; i <= n; ++i) 
    // {
    //     cout << "List " << i << " : ";
    //     for (int j = 0; j < adjlist[i].size(); ++j) 
    //     {
    //         cout << adjlist[i][j];
    //         if (j != adjlist[i].size() - 1)
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        cout << "List " << i << " : ";
        for (int j : adjlist[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
