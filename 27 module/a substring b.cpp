#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    // normal O(M)
    int i = 0;
    bool ans = false;
    for (char c : b)
    {
        if (c == a[i])
        {
            i++;
            ans=true;
        }
        else
        {
            i=0;
            ans=false;
        }
        if (i == a.size())
        {
            break;
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}