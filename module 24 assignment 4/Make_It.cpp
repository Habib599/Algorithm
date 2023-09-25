
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
bool dp[N];
bool make_it(int n,int target)
{
   if(n==target) return true;
   if(n < target) return false;
   if (dp[n]) return false;  
   
   return dp[n]=make_it(n,target+3) || make_it(n,target*2);
}
int main()
{
   int n,test;
   cin>>test;
    while (test--)
    {    
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            dp[i]=false;
            
        }  
        memset(dp, false, sizeof(dp));
        if(make_it(n,1)) 
            cout<<"YES"<<endl;

        else 
            cout<<"NO"<<endl;   
    }      
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main() 
// {
//     int t;
//     cin >> t;
    
//     while (t--) 
//     {
//         int n;
//         cin >> n;

        
//         while (n > 1) 
//         {
//             if (n % 2 == 0) 
//             {
//                 n /= 2;
//             } 
//             else if (n >= 3) 
//             {
//                 n -= 3;
//             } 
//             else 
//             {
//                 break;
//             }
//         }

//         if (n == 1) 
//         {
//             cout << "YES" << endl;
//         } 
//         else 
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }
