#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while (t--) 
    {
        int n;
        cin >> n;

        
        while (n > 1) 
        {
            if (n % 2 == 0) 
            {
                n /= 2;
            } 
            else if (n >= 3) 
            {
                n -= 3;
            } 
            else 
            {
                break;
            }
        }

        if (n == 1) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
