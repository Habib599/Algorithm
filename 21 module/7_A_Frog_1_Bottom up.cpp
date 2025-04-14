#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cost[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    
    dp[1] = 0;//const
    dp[2] = abs(cost[2] - cost[1]);//const
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 2] + abs(cost[i] - cost[i - 2]), //3-2=1 theke asa
                    dp[i - 1] + abs(cost[i] - cost[i - 1])); //3-1=2 theke asa
    }
    cout << dp[n] << endl;
    return 0;
}
