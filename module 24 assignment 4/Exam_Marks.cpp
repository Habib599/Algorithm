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

        bool dp[N + 1][1001];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 0; j <= 1000; j++)
             {
                dp[i][j] = dp[i - 1][j]; 

                if (j >= marks[i - 1]) 
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - marks[i - 1]];
                }
            }
        }

        if (dp[N][1000 - M]) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
