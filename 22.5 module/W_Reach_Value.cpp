#include <bits/stdc++.h>
using namespace std;

bool canReach(long long current, long long N) {
    if (current == N) return true; // Base case: reached N
    if (current > N) return false; // Base case: exceeded N

    // Recursive case: try multiplying by 10 and 20
    return canReach(current * 10, N) || canReach(current * 20, N);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        // Start with current = 1
        cout << (canReach(1, N) ? "YES" : "NO") << endl;
    }

    return 0;
}