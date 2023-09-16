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

        bool dp[1001];
        memset(dp, false, sizeof(dp));

        dp[0] = true;

        for (int i = 0; i < N; i++) 
        {
            for (int j = marks[i]; j <= 1000; j++)
             {
                dp[j] = dp[j] || dp[j - marks[i]];
            }
        }

        if (dp[1000 - M]) 
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
