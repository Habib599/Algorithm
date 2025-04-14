#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int main(){
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    int m;
    cin>>m;

    while(m--){
        int u,v;
        cin>>u>>v;
        pq.push({u,v});
    }

    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}