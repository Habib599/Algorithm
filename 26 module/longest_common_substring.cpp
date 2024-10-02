#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];

    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int j=0;j<=m;j++) dp[0][j]=0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    // table visiable
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int mx = 0;
    int ci, cj;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
    }
    string print_lcs;
    while (ci != 0 && cj != 0)
    {
        if (a[ci - 1] == b[cj - 1])
        {
            print_lcs += a[ci - 1];
            ci--;
            cj--;
        }
        else
        {
            break;
        }
    }
    reverse(print_lcs.begin(), print_lcs.end());
    cout << print_lcs << endl;
    cout << mx << endl;
    return 0;
}