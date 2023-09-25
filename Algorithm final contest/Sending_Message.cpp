#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    while (cin >> b >> a) 
    {
        int n = a.size(), m = b.size();

        int i = 0;
        bool ans = false;
        for (char c : b) {
            if (c == a[i]) 
            {
                i++;
            }
            if (i == n) 
            {
                ans = true;
                break;
            }
        }

        if (ans) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
