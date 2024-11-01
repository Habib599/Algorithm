#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
int nums[N];
void merge(int ar1[], int n, int ar2[],int m)
{
	
	ar1[n] = INT_MIN;
	ar2[m] = INT_MIN;

	int lp=0,rp=0;
	for(int i=0; i<n+m; i++)
	{
		if(ar1[lp] < ar2[rp])
		{
			nums[i] = ar2[rp];
			rp++;
		}
		else
		{
			nums[i] = ar1[lp];
			lp++;
		}
	}
}
int main()
{
    int n;
    cin >> n;
    int ar1[n];

    for(int i=0;i<n;i++)
    {
    	cin >> ar1[i];
    }
    int m;
    cin >> m;
    int ar2[m];

    for(int i=0;i<n;i++)
    {
    	cin >> ar2[i];
    }
    merge(ar1,n,ar2,m);
   
    for(int i=0; i<n+m;i++)
    {
    	cout << nums[i] << " ";
    }

 	return 0;
    
}
