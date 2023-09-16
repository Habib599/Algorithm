#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N, M;
        cin >> N >> M;

        int marks[N];

        for (int i = 0; i < N; i++) 
        {
            cin >> marks[i];
        }

        vector<int> dp(M + 1, INT_MAX); // Use a vector to store minimum marks needed.
        dp[0] = 0; // 0 marks are needed to obtain a sum of 0.

        for (int i = 0; i < N; i++) 
        {
            for (int j = marks[i]; j <= M; j++)
            {
                if (dp[j - marks[i]] != INT_MAX) 
                {
                    dp[j] = min(dp[j], dp[j - marks[i]] + 1); // Calculate minimum marks needed.
                }
            }
        }

        if (dp[M] == INT_MAX) 
        {
            cout << -1 << endl; // If it's not possible, print -1.
        } 
        else 
        {
            cout << dp[M] << endl; // Output the minimum marks needed.
        }
    }

    return 0;
}
