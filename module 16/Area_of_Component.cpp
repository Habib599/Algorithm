#include<bits/stdc++.h>
#define pair pair<int, int>
using namespace std;
const int N = 1005;
vector<pair> dis = {{0,-1},{0,1},{-1,0},{1,0}};
vector<string> s;
int visited[N][N];
int n,m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int dfs(int i, int j)
{
    if(!isValid(i,j)) return 0;
    if(visited[i][j]) return 0;
    if(s[i][j] == '-') return 0;
    visited[i][j] = true;
    
    int cons = 1;
    for(auto d : dis)
    {
        cons += dfs(i+d.first,j+d.second);
    }
    return cons;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        s.push_back(x);
    }
    int minimum = INT_MAX;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j] == '-') continue;
            if(visited[i][j]) continue;
            int cons = dfs(i,j);
            minimum = min(minimum,cons);
        }
    }
    if(minimum == INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<minimum<<endl;
    }
    return 0;
}