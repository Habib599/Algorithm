#include<bits/stdc++.h>
using namespace std;

const int N= 1e3+5;
int adj[N][N];

int main(){
    int n,e;
    cin >> n >>e;
    while(e--){
        int u,v;
        cin >> u>> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for (int i = 1; i <=n; i++){
        for (int  j = 1; j <=n; j++){
            cout<< adj[i][j] <<" ";
        }
        cout<< endl;   
    }
    
    return 0;
}