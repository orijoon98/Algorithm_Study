#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int dist[200000];
int n, k;

int main(){
    FAST;
    cin>>n>>k;
    fill(dist, dist+200000, -1);
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(dist[k] == -1){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){
            if(nxt<0 || nxt > 200000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout<<dist[k];
}

