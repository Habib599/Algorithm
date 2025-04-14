#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m;
const int N = 1005;
bool vis[N][N];
char a[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//upore niche bame dane

bool isValid(int cI, int cJ){
    return (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.');
}
void dfs(int si, int sj){
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++){
        pii p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj]){
            dfs(ci, cj);
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && a[i][j] == '.'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}