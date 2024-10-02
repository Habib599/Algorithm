#include<bits/stdc++.h>
#define pair pair<int, int>
using namespace std;
const int N = 105;
vector<pair> dis = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int visited[N][N];
int level[N][N];
int n,m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        pair parent = q.front();
        int i = parent.first;
        int j = parent.second;
        q.pop();
        for(auto d : dis)
        {
            int ni = i+d.first;
            int nj = j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj])
            {
                q.push({ni,nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] +1;

            }
        }
    }
}
void reset()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int si,sj,qi,qj;
        cin>>si>>sj>>qi>>qj;
        reset();
        bfs(si,sj);
        if(visited[qi][qj])
        {
            cout<<level[qi][qj]<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}