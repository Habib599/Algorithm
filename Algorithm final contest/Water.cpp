#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            pq.push(arr[i]);
        }
        int max=pq.top();
        pq.pop();
        int min=pq.top();

        for (int i = 0; i < n; i++)
        {
            if (max==arr[i]|| min==arr[i])
            {
                cout<<i<<" ";
            }
        }cout<<endl;
    }
    return 0;
}