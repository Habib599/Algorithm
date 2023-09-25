#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int dp[N][N];
    for (int i = 1; i <=N; i++) 
    {
        for (int j = 1; j <=N; j++) 
        {
            dp[i][j] = -1;
        }
    }
    //i
    for (int i = 1; i <= 1; i++) 
    {
         for (int j = 1; j <= N; j++) 
        {
            dp[i][j]=j;
        }
    }
    //j
    for (int i = 1; i <= N; i++) 
    {
         for (int j = 1; j <= 1; j++) 
        {
            dp[i][j]=i;
        }
    }//N
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            if (i==N||j==N) 
            {
                dp[i][j]=N;
            }
        }

    }
    //table
    for (int i = 1; i <=N; i++)
    {
        for (int j = 1; j <=N; j++)
        {
            if(dp[i][j]==-1)
                cout<<" ";
            else
                cout<<dp[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
