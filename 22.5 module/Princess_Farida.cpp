#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_coins(vector<long long>& coins) {
    int n = coins.size();
    if (n == 0) return 0;
    if (n == 1) return coins[0];
    vector<long long> dp(n);
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + coins[i]);
    }
    return dp.back();
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<long long> coins(N);
        for (int j = 0; j < N; ++j) {
            cin >> coins[j];
        }
        long long result = max_coins(coins);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}