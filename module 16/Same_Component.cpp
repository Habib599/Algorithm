#include<bits/stdc++.h>
#define pair pair<int,int>
using namespace std;
const int N = 1005;
vector<pair> path = {{-1,0},{1,0},{0,-1},{0,1}};
bool vis[N][N];
char a[N][N];
int n,m;
bool isValid(int cI, int cJ)
{
    if(cI >= 0 && cI < n && cJ >= 0 && cJ < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bfs(int si, int sj)
{
    queue<pair> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty())
    {
        pair parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            pair p = path[i];
            int cI = pi+p.first;
            int cJ = pj+p.second;
            if(isValid(cI,cJ) && !vis[cI][cJ] && a[cI][cJ] == '.')
            {
                vis[cI][cJ] = true;
                q.push({cI,cJ});
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    int di,dj;
    cin>>di>>dj;
    if(vis[di][dj])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}