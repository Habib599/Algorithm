#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int countWaysToDivide(vector<int>A, int N, int D) 
{
    int totalSum = 0;
    for (int num : A) totalSum += num;

    if ((D + totalSum) % 2 != 0)  return 0;

    int targetSum = (D + totalSum) / 2;

    vector<vector<int>> dp(N + 1, vector<int>(targetSum + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 0; j <= targetSum; j++) 
        {
            dp[i][j] = dp[i - 1][j];

            if (A[i - 1] <= j) 
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i - 1]]) % MOD;
            }
        }
    }

    return dp[N][targetSum];
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N, D;
        cin >> N >> D;

        vector<int> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> A[i];
        }

        int ways = countWaysToDivide(A, N, D);
        cout << ways << endl;
    }

    return 0;
}
