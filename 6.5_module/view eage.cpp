#include<bits/stdc++.h>
using namespace std;

const int N= 1e3+5;
vector<int>adj[N];

int main(){
    int n,e;
    cin >> n >>e;
    while(e--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <=n ; i++){
        cout<<i<<"->" ;
        for (int j:adj[i]){
            cout<<j;
        }
        cout<<endl;
    }
    
    return 0;
}