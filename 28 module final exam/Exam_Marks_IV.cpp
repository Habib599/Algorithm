#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

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

        
        vector<long long> dp(1001, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) 
        {
            for (int j = marks[i]; j <= 1000; j++) 
            {
                dp[j] = (dp[j] + dp[j - marks[i]]) % MOD;
            }
        }
        cout << dp[1000 - M] << endl;
    }

    return 0;
}