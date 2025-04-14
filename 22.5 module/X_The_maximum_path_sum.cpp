#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> A;
vector<vector<int>> dp; // Memoization Table

// Recursive function with memoization
int maxSum(int i, int j) {
    if (i == N - 1 && j == M - 1) 
        return A[i][j];

    // যদি আমরা গ্রিডের বাইরে যাই, তাহলে -∞ রিটার্ন করি যাতে এটি গণনায় না আসে
    if (i >= N || j >= M) 
        return -1e9;

    // যদি আগেই হিসাব করা থাকে, তাহলে সরাসরি রিটার্ন করি
    if (dp[i][j] != -1) 
        return dp[i][j];

    // নিচে ও ডানে যাওয়ার সর্বোচ্চ পথ বের করে মেমোতে রাখি
    return dp[i][j] = A[i][j] + max(maxSum(i + 1, j), maxSum(i, j + 1));
}

int main() {
    cin >> N >> M;
    A.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, -1)); // -1 দিয়ে ইনিশিয়ালাইজ

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cout << maxSum(0, 0) << endl;
    return 0;
}