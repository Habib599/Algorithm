#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;

        int choco[N];

        for (int i = 0; i < N; i++) 
        {
            cin >> choco[i];
        }

        int sum = 0;

        for (int i = 0; i < N; i++) 
        {
            sum += choco[i];
        }

        //odd
        if (sum % 2 != 0) 
        {
            cout << "NO" << endl;
            continue;
        }

        //find subset
        bool dp[N + 1][sum / 2 + 1];
        for (int i = 0; i <= N; i++) 
        {
            for (int j = 0; j <= sum / 2; j++) 
            {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i <= N; i++) 
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= sum / 2; j++) 
            {
                if (j >= choco[i - 1]) 
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - choco[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[N][sum / 2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
