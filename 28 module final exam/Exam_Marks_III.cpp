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

        int dp[1001];
        fill(dp, dp + 1001, 1001);
        dp[0] = 0;

        for (int i = 0; i < N; i++) 
        {
            for (int j = marks[i]; j <= 1000; j++) 
            {
                dp[j] = min(dp[j], dp[j - marks[i]] + 1);
            }
        }

        if (dp[1000 - M] == 1001) 
        {
            cout << "-1" << endl;  
        } 
        else 
        {
            cout << dp[1000 - M] << endl;
        }
    }

    return 0;
}