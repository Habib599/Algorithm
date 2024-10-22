#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> profit(n, vector<int>(m));
    
    // Reading the profit table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> profit[i][j];
        }
    }

    // DP array to store the maximum profit for subarrays on day i
    vector<int> dp(m);

    // Initialize dp for day 1 (profit[0][j])
    for (int j = 0; j < m; ++j) {
        dp[j] = profit[0][j];
    }

    // Traverse over each day starting from day 2
    for (int i = 1; i < n; ++i) {
        // Calculate left max and right max for the current day
        vector<int> left_max(m), right_max(m);

        // Calculate left_max for day i-1 (maximum subarray ending before or at j)
        left_max[0] = dp[0];
        for (int j = 1; j < m; ++j) {
            left_max[j] = max(left_max[j - 1], dp[j]);
        }

        // Calculate right_max for day i-1 (maximum subarray starting at or after j)
        right_max[m - 1] = dp[m - 1];
        for (int j = m - 2; j >= 0; --j) {
            right_max[j] = max(right_max[j + 1], dp[j]);
        }

        // Temp array to store new dp values for day i
        vector<int> new_dp(m, 0);

        // Update dp for day i, considering both left_max and right_max
        for (int j = 0; j < m; ++j) {
            // Max profit if selecting subarray from left_max or right_max plus current profit
            new_dp[j] = profit[i][j] + max(left_max[j], right_max[j]);
        }

        // Update dp to new_dp for the next iteration
        dp = new_dp;
    }

    // The result is the maximum value in dp after the last day
    int result = *max_element(dp.begin(), dp.end());
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
