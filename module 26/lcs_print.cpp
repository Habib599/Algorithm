#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b,print_lcs;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                print_lcs += a[i - 1];//
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // int i = n, j = m;
    // string print_lcs;
    // while (i != 0 && j != 0)
    // {
    //     if (a[i - 1] == b[j - 1])
    //     {
    //         print_lcs += a[i - 1];
    //         i--;
    //         j--;
    //     }
    //     else
    //     {
    //         if (dp[i][j - 1] > dp[i - 1][j])
    //         {
    //             j--;
    //         }
    //         else
    //         {
    //             i--;
    //         }
    //     }
    // }
    // reverse(print_lcs.begin(), print_lcs.end());
    cout << print_lcs << endl;
    cout << dp[n][m] << endl;
    return 0;
}