#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];

    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int j=0;j<=m;j++) dp[0][j]=0;

    //main code lcs
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if (a[i-1]==b[j-1]) 
            {
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
    // print scs
    int i = n, j = m;
    string print_scs;
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            print_scs += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            print_scs += a[i - 1];
            i--;
        }
        else
        {
            print_scs += b[j - 1];
            j--;
        }
    }
    while (i != 0)
    {
        print_scs += a[i - 1];
        i--;
    }
    while (j != 0)
    {
        print_scs += b[j - 1];
        j--;
    }
    reverse(print_scs.begin(), print_scs.end());
    cout << print_scs << endl;
    cout<<n+m-dp[n][m];
    return 0;
}