#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int K) 
{
    int left = 0;
    int right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == K) 
        {
            return mid;
        } 
        else if (arr[mid] < K) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main() 
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    int idx = binarySearch(arr, n, K);
    if (K == arr[idx+1] || K == arr[idx-1] ) 
    {
        cout << "YES" << endl;
    } else 
    {
        cout << "NO" << endl;
    }
    return 0;
}
