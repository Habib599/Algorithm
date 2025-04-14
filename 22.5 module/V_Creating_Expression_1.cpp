#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int sum, int X, vector<int>& A) { //recurtion but bottom top
    if (i == A.size()) return sum == X;
    return solve(i + 1, sum + A[i], X, A) || 
           solve(i + 1, sum - A[i], X, A);
}

int main() {
    int N, X; 
    cin >> N >> X;
    vector<int> A(N); 
    for (int& x : A) cin >> x;
    cout << (solve(0, 0, X, A) ? "YES" : "NO") << endl;
}